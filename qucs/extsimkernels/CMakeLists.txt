# qucs/extsimkernels library
# Classes and GUI for external simulation kernels (ngspice, xyce, etc.) interfacing

add_compile_definitions(${Qt6Widgets_COMPILE_DEFINITIONS}
  ${Qt6Core5Compat_COMPILE_DEFINITIONS}
  ${Qt6Core_COMPILE_DEFINITIONS}
  ${Qt6Gui_COMPILE_DEFINITIONS})

INCLUDE_DIRECTORIES( ${CMAKE_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
    ${Qt6Widgets_INCLUDE_DIRS}
    ${Qt6Core5Compat_INCLUDE_DIRS}
    ${Qt6Core_INCLUDE_DIRS}
    ${Qt6Gui_INCLUDE_DIRS})

#INCLUDES = $(X11_INCLUDES) $(QT_INCLUDES) -I$(top_srcdir)/qucs

SET(EXTSIMKERNELS_HDRS
    externsimdialog.h
    abstractspicekernel.h
    ngspice.h
    xyce.h
    qucs2spice.h
    spicecompat.h
    customsimdialog.h
    simsettingsdialog.h
    verilogawriter.h
    xspice_cmbuilder.h
    codemodelgen.h
    )

SET(EXTSIMKERNELS_SRCS
    externsimdialog.cpp
    abstractspicekernel.cpp
    ngspice.cpp
    xyce.cpp
    qucs2spice.cpp
    spicecompat.cpp
    customsimdialog.cpp
    simsettingsdialog.cpp
    verilogawriter.cpp
    xspice_cmbuilder.cpp
    codemodelgen.cpp
    )

SET(EXTSIMKERNELS_MOC_HDRS
    externsimdialog.h
    abstractspicekernel.h
    ngspice.h
    xyce.h
    customsimdialog.h
    simsettingsdialog.h
    )

QT6_WRAP_CPP( EXTSIMKERNELS_MOC_SRCS ${EXTSIMKERNELS_MOC_HDRS} )

ADD_LIBRARY(extsimkernels ${EXTSIMKERNELS_HDRS} ${EXTSIMKERNELS_SRCS} ${EXTSIMKERNELS_MOC_SRCS})

ADD_SUBDIRECTORY( xspice )

