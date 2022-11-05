TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += "C:/SFML-2.5.1/include"

LIBS += -L"C:/SFML-2.5.1/lib"
CONFIG(debug, debug|release){
    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}

SOURCES += \
    WashingHandsFunctions.cpp \
    babcia.cpp \
    button.cpp \
    fonts.cpp \
    gra_zakupy.cpp \
    instruction.cpp \
    main.cpp \
    mouseandcursor.cpp \
    picture.cpp \
    platforma.cpp \
    project.cpp \
    textures.cpp \
    wolontariusz.cpp \
    zbieranie_smieci.cpp

HEADERS += \
    WashingHandsClass.h \
    babcia.h \
    button.h \
    fonts.h \
    gra_zakupy.h \
    instruction.h \
    mouseandcursor.h \
    picture.h \
    platforma.h \
    project.h \
    textures.h \
    wolontariusz.h \
    zbieranie_smieci.h
