QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    formdrawing/commands.cpp \
    formdrawing/diagramscene.cpp \
    formdrawing/ellipse.cpp \
    formdrawing/formdrawing.cpp \
    formdrawing/line.cpp \
    formdrawing/myitem.cpp \
    formdrawing/rectangle.cpp \
    formdrawing/triangle.cpp \
    forminformation/figureviewbutton.cpp \
    forminformation/forminformation.cpp \
    main.cpp \
    mainwindow.cpp \
    network/udpserver.cpp \
    settings.cpp

HEADERS += \
    api_generated.h \
    flatbuffers/allocator.h \
    flatbuffers/array.h \
    flatbuffers/base.h \
    flatbuffers/buffer.h \
    flatbuffers/buffer_ref.h \
    flatbuffers/code_generator.h \
    flatbuffers/code_generators.h \
    flatbuffers/default_allocator.h \
    flatbuffers/detached_buffer.h \
    flatbuffers/file_manager.h \
    flatbuffers/flatbuffer_builder.h \
    flatbuffers/flatbuffers.h \
    flatbuffers/flatc.h \
    flatbuffers/flex_flat_util.h \
    flatbuffers/flexbuffers.h \
    flatbuffers/grpc.h \
    flatbuffers/hash.h \
    flatbuffers/idl.h \
    flatbuffers/minireflect.h \
    flatbuffers/pch/flatc_pch.h \
    flatbuffers/pch/pch.h \
    flatbuffers/reflection.h \
    flatbuffers/reflection_generated.h \
    flatbuffers/registry.h \
    flatbuffers/stl_emulation.h \
    flatbuffers/string.h \
    flatbuffers/struct.h \
    flatbuffers/table.h \
    flatbuffers/util.h \
    flatbuffers/vector.h \
    flatbuffers/vector_downward.h \
    flatbuffers/verifier.h \
    formdrawing/commands.h \
    formdrawing/diagramscene.h \
    formdrawing/ellipse.h \
    formdrawing/formdrawing.h \
    formdrawing/line.h \
    formdrawing/myitem.h \
    formdrawing/rectangle.h \
    formdrawing/triangle.h \
    forminformation/figureviewbutton.h \
    forminformation/forminformation.h \
    mainwindow.h \
    network/udpserver.h

FORMS += \
    formdrawing/formdrawing.ui \
    forminformation/forminformation.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
