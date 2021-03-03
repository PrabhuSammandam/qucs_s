# qucs/diagrams library

add_compile_definitions(${Qt6Widgets_COMPILE_DEFINITIONS}
  ${Qt6Core5Compat_COMPILE_DEFINITIONS}
  ${Qt6Core_COMPILE_DEFINITIONS}
  ${Qt6Gui_COMPILE_DEFINITIONS})

INCLUDE_DIRECTORIES( ${CMAKE_SOURCE_DIR}
                     ${CMAKE_CURRENT_SOURCE_DIR}
                     ${Qt6Widgets_INCLUDE_DIRS}
                     ${Qt6Core5Compat_INCLUDE_DIRS}
                     ${Qt6Core_INCLUDE_DIRS}
                     ${Qt6Gui_INCLUDE_DIRS})

#INCLUDES = $(X11_INCLUDES) $(QT_INCLUDES) -I$(top_srcdir)/qucs

SET(DIAGRAMS_HDRS
curvediagram.h
diagram.h
diagramdialog.h
diagrams.h
graph.h
marker.h
markerdialog.h
polardiagram.h
psdiagram.h
rect3ddiagram.h
rectdiagram.h
smithdiagram.h
tabdiagram.h
timingdiagram.h
truthdiagram.h
)

SET(DIAGRAMS_SRCS
curvediagram.cpp	graph.cpp		polardiagram.cpp	smithdiagram.cpp
diagram.cpp		marker.cpp		psdiagram.cpp		tabdiagram.cpp
diagramdialog.cpp	markerdialog.cpp	rect3ddiagram.cpp	timingdiagram.cpp
rectdiagram.cpp		truthdiagram.cpp
)

SET(DIAGRAMS_MOC_HDRS
diagramdialog.h
markerdialog.h
)

QT6_WRAP_CPP( DIAGRAMS_MOC_SRCS ${DIAGRAMS_MOC_HDRS} )

ADD_LIBRARY(diagrams ${DIAGRAMS_HDRS} ${DIAGRAMS_SRCS} ${DIAGRAMS_MOC_SRCS})
