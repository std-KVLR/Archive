TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -fpermissive

SOURCES += \
    DataStructures.cpp \
    MyAlgorithms.cpp \
    ProgramBlocks.cpp \
    data_input.cpp \
    main.cpp

HEADERS += \
    DataStructures.h \
    MyAlgorithms.h \
    MyDataStructuresArray.h \
    ProgramBlocks.h \
    SatterHelpers.h \
    Sorts/BubbleSort.h \
    data_input.h
