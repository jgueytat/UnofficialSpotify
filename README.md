# Unofficial Spotify

**Unofficial Spotify** client based on [the Spotify WEB API](https://beta.developer.spotify.com/documentation/web-api/) and the [the Spotify WEB PLAYBACK SDK](https://beta.developer.spotify.com/documentation/web-playback-sdk/). The authorization is made with [the QtNetworkAuth module](https://doc.qt.io/qt-5.9/qtnetworkauth-index.html) backported from Qt 5.9.4. When Sailfish OS will be ported to Qt 5.9 LTS the submodule QtNetworkAuth should simply be removed from this repository.

## Status
### Shared Status
 * OAuth - ok
 * Web API - ok

### Sailfish OS Status concerning the Web Playback SDK
It seams a recent QtWebKit helps in getting the spotify-player.js to go further. Please follow [this thread](https://together.jolla.com/question/171114/xperia-xbug-qtwebkit-unusably-slow/?answer=180404#post-id-180404) to update your QtWebKit version. The packages to be installed on your Xperia X can be downloaded [here](https://openrepos.net/content/llelectronicsdev/qtwebkit-5212-dev). Thanks _leszek_ from #sailfishos !

#### Full current output of the application
> \[D\] unknown:0 - QML debugging is enabled. Only use this in a safe environment.
> 
> \[D\] unknown:0 - Using Wayland-EGL
> 
> \[D\] QOAuth2AuthorizationCodeFlow::buildAuthenticateUrl:380 - QOAuth2AuthorizationCodeFlow::buildAuthenticateUrl: https://accounts.spotify.com/authorize?client\_id=730d1c6aa1b34e2ab3ef55b01a0b47e0&redirect\_uri=http://localhost:1337/&response_type=code&scope=user-read-playback-state streaming user-read-birthdate user-read-email user-read-private&state=8r60JzcE
> 
> \[D\] unknown:0 - Defaulting to webview scaling factor of 1.0
> 
> \[W\] unknown:0 - 
> WARNING: This project is using the experimental QML API extensions for QtWebKit and is therefore tied to a specific QtWebKit release.
> 
> WARNING: The experimental API will change from version to version, or even be removed. You have been warned!
> 
> \[W\] unknown:0 - Inspector server started successfully. Try pointing a WebKit browser to http://127.0.0.1:9999
> 
> \[W\] unknown:0 - QQmlExpression: Expression file:///usr/lib/qt5/qml/Sailfish/Silica/SilicaWebView.qml:143:16 depends on non-NOTIFYable properties:
> 
> \[W\] unknown:0 - QQuickWebViewExperimental::transparentBackground
> 
> \[D\] unknown:0 - "No carrier"
> 
> \[D\] unknown:0 - "No carrier"
> 
> \[D\] unknown:0 - "No carrier"
> 
> \[D\] SpotifyConnectModel::requestConnect:77 - \[SpotifyConnectModel::requestConnect\] : Request launched
> 
> \[D\] SpotifyConnectModel::requestConnect:81 - \[SpotifyConnectModel::requestConnect\] : Reply received
> 
> \[D\] SpotifyConnectModel::requestConnect:91 - \[SpotifyConnectModel::requestConnect\] : Content received
> 
> \[D\] SpotifyConnectModel::requestConnect:92 - QJsonDocument({"devices":\[\]})
> 
> \[D\] onMessageReceived:16 - Message received from javascript : {"data":"BQDe7LVP0-ULdEyHQ3CAbiqenTOacfzhU8vlJfPXxftQF6ma4eeZxlybdiS2na4rxZcEgwNXhvZL6DN\_D-ydLy55\_401TxUHY1-j4SYGCxYrITpBdfZB_VlWV5PfAVn4qxKKkWBJXHSFztSyfOMtIAtOZAbW1PIUXC1ULhTET7A","origin":file:///home/nemo/.local/share/UnofficialSpotify/UnofficialSpotify/spotify-player.html}
> 
> \[D\] onMessageReceived:16 - Message received from javascript : {"data":"Failed to initialize player","origin":file:///home/nemo/.local/share/UnofficialSpotify/UnofficialSpotify/spotify-player.html}
> 
> \[D\] onMessageReceived:16 - Message received from javascript : {"data":"Ready with Device ID","origin":file:///home/nemo/.local/share/UnofficialSpotify/UnofficialSpotify/spotify-player.html}

### Desktop Status concerning the Web Playback SDK
[UnofficialSpotify-desktop](https://github.com/jgueytat/UnofficialSpotify-desktop) is the desktop equivalent of this repository. You need to have the Qt library installed with the QtNetworkAuth module installed. I recommend Qt 5.9.4 which is the current LTS.

## Documentation
### Sailfish

 * [Sailfish Silica](https://sailfishos.org/develop/docs/silica/)
 * [Jolla Harbour](https://harbour.jolla.com/) for deployment
 
### Spotify

 * [Web API](https://beta.developer.spotify.com/documentation/web-api/)
 * [Web Playback SDK](https://beta.developer.spotify.com/documentation/web-playback-sdk/)
 * [Web Console](https://beta.developer.spotify.com/console/)

