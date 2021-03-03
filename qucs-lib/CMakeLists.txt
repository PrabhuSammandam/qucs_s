PROJECT(qucslib CXX C)
CMAKE_MINIMUM_REQUIRED(VERSION 3.19.0)
#cmake_policy(VERSION 2.6)

SET(QUCS_NAME "qucs-s")

# use top VERSION file
file (STRINGS ${PROJECT_SOURCE_DIR}/../VERSION QUCS_VERSION)
message(STATUS "Configuring ${PROJECT_NAME} (GUI): VERSION ${QUCS_VERSION}")

set(PROJECT_VERSION "${QUCS_VERSION}")

set(PROJECT_VENDOR "Qucs team. This program is licensed under the GNU GPL")
set(PROJECT_COPYRIGHT_YEAR "2014")
set(PROJECT_DOMAIN_FIRST "qucs")
set(PROJECT_DOMAIN_SECOND "org")

#SET(CMAKE_BUILD_TYPE Debug)


ADD_DEFINITIONS( -DHAVE_CONFIG_H )

# configure the header config.h
CONFIGURE_FILE (
    "${PROJECT_SOURCE_DIR}/../config.h.cmake"
    "${PROJECT_BINARY_DIR}/config.h"
)

INCLUDE_DIRECTORIES(${PROJECT_BINARY_DIR}  "../qucs" )

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall ") # enable warning level
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x ") # enable C++11

# flag not available in mingw 4.8.2, MSVC10
IF(NOT WIN32)
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated-register ")
ENDIF()

#FIND_PACKAGE( Qt4 REQUIRED )
find_package(Qt6 COMPONENTS Widgets Gui Core Core5Compat REQUIRED)

SET( QT_USE_QTGUI TRUE )

#INCLUDE( ${QT_USE_FILE} )

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_VERBOSE_MAKEFILE ON)
add_compile_options(-fPIC)

ADD_DEFINITIONS(${QT_DEFINITIONS})

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

SET(QUCSLIB_SRCS
main.cpp qucslib.cpp displaydialog.cpp symbolwidget.cpp librarydialog.cpp
)

SET(QUCSLIB_MOC_HDRS
qucslib.h displaydialog.h symbolwidget.h librarydialog.h
)

QT6_WRAP_CPP( QUCSLIB_MOC_SRCS ${QUCSLIB_MOC_HDRS} )

SET(RESOURCES qucslib.qrc)
QT6_ADD_RESOURCES(RESOURCES_SRCS ${RESOURCES})

ADD_EXECUTABLE(${QUCS_NAME}lib MACOSX_BUNDLE WIN32
  ${QUCSLIB_SRCS}
  ${QUCSLIB_MOC_SRCS}
  ${RESOURCES_SRCS}
  )

TARGET_LINK_LIBRARIES(${QUCS_NAME}lib
  Qt6::Core5Compat
  Qt6::Core
  Qt6::Widgets
  Qt6::Gui)

INSTALL(TARGETS ${QUCS_NAME}lib
    BUNDLE DESTINATION bin COMPONENT Runtime
    RUNTIME DESTINATION bin COMPONENT Runtime
    )

ADD_SUBDIRECTORY( library )


