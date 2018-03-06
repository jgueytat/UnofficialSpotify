// Qt
#include <QtGui>

// Qt backport
#include <QOAuthHttpServerReplyHandler.h>

// Unofficial Spotify
#include "spotifywrapper.h"


const QUrl connectUrl("https://api.spotify.com/v1/me/player/devices");


SpotifyWrapper::SpotifyWrapper(const QString &clientIdentifier, const QString &clientIdentifierSharedKey, QObject *parent) :
    QObject(parent)
{
    m_spotifyPlayerFilePath = QDir(QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation)).filePath("spotify-player.html");

    auto replyHandler = new QOAuthHttpServerReplyHandler(1337, this);
    oauth2.setReplyHandler(replyHandler);
    oauth2.setAuthorizationUrl(QUrl("https://accounts.spotify.com/authorize"));
    oauth2.setAccessTokenUrl(QUrl("https://accounts.spotify.com/api/token"));
    oauth2.setScope("user-read-playback-state");

    connect(&oauth2, &QOAuth2AuthorizationCodeFlow::statusChanged, [=](
            QAbstractOAuth::Status status) {
        if (status == QAbstractOAuth::Status::Granted)
            emit authenticated();
    });
    oauth2.setModifyParametersFunction([&](QAbstractOAuth::Stage stage, QVariantMap *parameters) {
        if (stage == QAbstractOAuth::Stage::RequestingAuthorization && isPermanent())
            parameters->insert("duration", "permanent");
    });
    connect(&oauth2, &QOAuth2AuthorizationCodeFlow::authorizeWithBrowser,
            &QDesktopServices::openUrl);

    oauth2.setClientIdentifier(clientIdentifier);
    oauth2.setClientIdentifierSharedKey(clientIdentifierSharedKey);

    connect(&oauth2, &QOAuth2AuthorizationCodeFlow::tokenChanged,
            this, &SpotifyWrapper::tokenChangedSlot);
}

QNetworkReply *SpotifyWrapper::requestConnect()
{
    return oauth2.get(connectUrl);
}

bool SpotifyWrapper::isPermanent() const
{
    return permanent;
}

void SpotifyWrapper::setPermanent(bool value)
{
    permanent = value;
}

void SpotifyWrapper::grant()
{
    oauth2.grant();
}

void SpotifyWrapper::tokenChangedSlot(const QString &token)
{
    m_token = token;

    QFile l_spotifyPlayerFileIn("://spotify-player.html.in");

    Q_ASSERT(l_spotifyPlayerFileIn.open(QIODevice::ReadOnly|QIODevice::Text));
    QByteArray l_spotifyPlayerContent = l_spotifyPlayerFileIn.readAll();
    l_spotifyPlayerContent.replace(QString("TOKEN"), token.toLatin1());

    QFile l_spotifyPlayerFile(m_spotifyPlayerFilePath);
    qDebug() << "Spotify Player url : " << m_spotifyPlayerFilePath;
    qDebug() << "New OAuth token : " << m_token;

    Q_ASSERT(l_spotifyPlayerFile.open(QIODevice::WriteOnly));
    l_spotifyPlayerFile.write(l_spotifyPlayerContent);

    l_spotifyPlayerFile.close();
    l_spotifyPlayerFileIn.close();

    emit tokenChanged(m_token);
}
