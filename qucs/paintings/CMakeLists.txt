# qucs/paintings library

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

SET(PAINTINGS_HDRS
arrow.h
arrowdialog.h
ellipse.h
ellipsearc.h
filldialog.h
graphicline.h
graphictext.h
graphictextdialog.h
id_dialog.h
id_text.h
painting.h
paintings.h
portsymbol.h
rectangle.h
)

SET(PAINTINGS_SRCS
arrow.cpp arrowdialog.cpp
graphicline.cpp	id_text.cpp
graphictext.cpp	painting.cpp
ellipse.cpp	graphictextdialog.cpp
portsymbol.cpp ellipsearc.cpp
rectangle.cpp filldialog.cpp
id_dialog.cpp
)

SET(PAINTINGS_MOC_HDRS
arrowdialog.h
filldialog.h
graphictextdialog.h
id_dialog.h
)

QT6_WRAP_CPP( PAINTINGS_MOC_SRCS ${PAINTINGS_MOC_HDRS} )

ADD_LIBRARY(paintings ${PAINTINGS_HDRS} ${PAINTINGS_SRCS} ${PAINTINGS_MOC_SRCS} )

