# NOTICE:
#
# Application name defined in TARGET has a corresponding QML filename.
# If name defined in TARGET is changed, the following needs to be done
# to match new name:
#   - corresponding QML filename must be changed
#   - desktop icon filename must be changed
#   - desktop filename must be changed
#   - icon definition filename in desktop file must be changed
#   - translation filenames have to be changed

# The name of your application
TARGET = UnofficialSpotify

CONFIG += sailfishapp

SOURCES += \
    src/UnofficialSpotify.cpp \
    src/spotifywrapper.cpp \
    src/spotifyconnectmodel.cpp

HEADERS += \
    src/clientidsecret/spotifysecret.h \
    src/spotifywrapper.h \
    src/spotifyconnectmodel.h

DISTFILES += \
    qml/UnofficialSpotify.qml \
    qml/pages/FirstPage.qml \
    qml/pages/ConnectPage.qml \
    rpm/UnofficialSpotify.changes.in \
    rpm/UnofficialSpotify.changes.run.in \
    rpm/UnofficialSpotify.spec \
    rpm/UnofficialSpotify.yaml \
    translations/*.ts \
    UnofficialSpotify.desktop

SAILFISHAPP_ICONS = 86x86 108x108 128x128

# to disable building translations every time, comment out the
# following CONFIG line
CONFIG += sailfishapp_i18n

# German translation is enabled as an example. If you aren't
# planning to localize your app, remember to comment out the
# following TRANSLATIONS line. And also do not forget to
# modify the localized app name in the the .desktop file.
TRANSLATIONS += translations/UnofficialSpotify-fr.ts

INCLUDEPATH += $$_PRO_FILE_PWD_/src/
DEPENDPATH += $$_PRO_FILE_PWD_/src/

# Library OAUth2 coming from the QtNetworkAuth module
qtHaveModule(networkauth):QT += network networkauth

!qtHaveModule(networkauth)
{
    message("Using QtNetworkAuth backported from Qt 5.9.4")
    QT += core-private network
    INCLUDEPATH += $$_PRO_FILE_PWD_/QtNetworkAuth/
    DEPENDPATH += $$_PRO_FILE_PWD_/QtNetworkAuth/
    SOURCES += $$files(QtNetworkAuth/*.cpp)
    HEADERS += $$files(QtNetworkAuth/*.h)
}
