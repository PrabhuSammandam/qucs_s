PROJECT(qucslib CXX C)
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
cmake_policy(VERSION 2.6)

SET(BITMAPDIR TRUE)
SET(BINARYDIR TRUE)
SET(DOCDIR TRUE)
SET(LANGUAGEDIR TRUE)
SET(LIBRARYDIR TRUE)

SET(CMAKE_BUILD_TYPE Debug)

ADD_DEFINITIONS( -DHAVE_CONFIG_H )

# to the source code
CONFIGURE_FILE (
    "${PROJECT_SOURCE_DIR}/../config.h.cmake"
    "${PROJECT_BINARY_DIR}/config.h"
)

INCLUDE_DIRECTORIES("${PROJECT_BINARY_DIR}")

FIND_PACKAGE( Qt4 REQUIRED )
SET( QT_USE_QTGUI TRUE )
#SET( QT_USE_QT3SUPPORT TRUE )

INCLUDE( ${QT_USE_FILE} )

ADD_DEFINITIONS(${QT_DEFINITIONS})

SET(QUCSLIB_SRCS
main.cpp qucslib.cpp displaydialog.cpp symbolwidget.cpp searchdialog.cpp librarydialog.cpp
)

SET(QUCSLIB_MOC_HDRS
qucslib.h displaydialog.h symbolwidget.h searchdialog.h librarydialog.h
)

QT4_WRAP_CPP( QUCSLIB_MOC_SRCS ${QUCSLIB_MOC_HDRS} )

ADD_EXECUTABLE(qucslib ${QUCSLIB_SRCS} ${QUCSLIB_MOC_SRCS} )

TARGET_LINK_LIBRARIES( qucslib ${QT_LIBRARIES} )

INSTALL(TARGETS qucslib DESTINATION bin)

ADD_SUBDIRECTORY( library )

# man pages
INSTALL( FILES qucslib.1 DESTINATION share/man/man1 )
