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
