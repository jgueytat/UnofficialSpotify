#ifndef SPOTIFYWRAPPER_H
#define SPOTIFYWRAPPER_H

#include <QtCore>
#include <QtNetwork>

#include <QOAuth2AuthorizationCodeFlow.h>

class SpotifyWrapper : public QObject
{
    Q_OBJECT
public:
    SpotifyWrapper(const QString &clientIdentifier, const QString &clientIdentifierSharedKey, QObject *parent = nullptr);

    QNetworkReply *requestConnect();

    bool isPermanent() const;
    void setPermanent(bool value);

signals:
    void authenticated();

public slots:
    void grant();

private:
    QOAuth2AuthorizationCodeFlow oauth2;
    bool permanent = false;
};

#endif // SPOTIFYWRAPPER_H
