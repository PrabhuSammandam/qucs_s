# To have CMake pick a Qt installation of your choice that won't be found
# automatically, set the CMAKE_PREFIX_PATH environment variable.
# For example: "export CMAKE_PREFIX_PATH=/usr/local/trolltech/qt4.3.5"
#
# You can change the install location by
# running cmake like this:
#   mkdir build; cd build
#   cmake .. -DCMAKE_INSTALL_PREFIX=/new/install/prefix
#
# By default, the prefix is "/usr/local"

PROJECT(qucs-s CXX)
CMAKE_MINIMUM_REQUIRED(VERSION 3.19.0)
#cmake_policy(VERSION 2.6)

SET(QUCS_NAME "${PROJECT_NAME}")

# use top VERSION file
file (STRINGS ${PROJECT_SOURCE_DIR}/../VERSION QUCS_VERSION)
message(STATUS "Configuring ${PROJECT_NAME} (GUI): VERSION ${QUCS_VERSION}")

set(PROJECT_VERSION "${QUCS_VERSION}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_VERBOSE_MAKEFILE ON)
add_compile_options(-fPIC)

set(PROJECT_VENDOR "Qucs team. This program is licensed under the GNU GPL")
set(PROJECT_COPYRIGHT_YEAR "2014")
set(PROJECT_DOMAIN_FIRST "qucs")
set(PROJECT_DOMAIN_SECOND "org")

#
#SET(CMAKE_BUILD_TYPE Debug)

# If Git hash not defined, try to define it
IF(NOT GIT)
IF(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/../../.git )
FIND_PACKAGE(Git)
# Get the latest abbreviated commit hash of the working branch
execute_process(
    COMMAND ${GIT_EXECUTABLE} log --pretty=format:%h -n 1u
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    OUTPUT_VARIABLE GIT_COMMIT_HASH
    )
set(GIT ${GIT_COMMIT_HASH})
message(STATUS "Found Git repository, last commit hash: ${GIT}")
ENDIF()
ENDIF()

#
ADD_DEFINITIONS( -DHAVE_CONFIG_H )

# FIND_PACKAGE( Qt4 4.6.3 REQUIRED QtCore QtGui Qt3Support QtSvg QtXml QtScript)
# INCLUDE( ${QT_USE_FILE} )

#MESSAGE("QT_INCLUDES=[${QT_INCLUDES}]")
#MESSAGE("QT_LIBRARIES=[${QT_LIBRARIES}]")

# Check whether the Qt QTabWidget::setMovable() function exists.
# This function was added in Qt 4.5.
# * Maybe use CMake CheckCXXSourceCompiles in the future?
TRY_COMPILE( HAVE_QTABWIDGET_SETMOVABLE
    ${CMAKE_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../cmake/QTabWidget_setMovable.cpp
    CMAKE_FLAGS "-DINCLUDE_DIRECTORIES:STRING=${QT_INCLUDES}"
    LINK_LIBRARIES ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY}
    OUTPUT_VARIABLE TRY_OUT )
IF(NOT HAVE_QTABWIDGET_SETMOVABLE)
MESSAGE("QTabWidget::setMovable() not available, feature disabled.")
ENDIF()

# configure the header config.h
CONFIGURE_FILE (
    "${PROJECT_SOURCE_DIR}/../config.h.cmake"
    "${PROJECT_BINARY_DIR}/config.h"
    )

INCLUDE_DIRECTORIES("${PROJECT_BINARY_DIR}")
INCLUDE_DIRECTORIES( ${CMAKE_SOURCE_DIR} )
INCLUDE_DIRECTORIES(../tools)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra ") # enable warning level
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x ") # enable C++11

# flag not available in mingw 4.8.2, MSVC10
IF(NOT WIN32)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated-register ")
ENDIF()

ADD_DEFINITIONS(${QT_DEFINITIONS})

INCLUDE_DIRECTORIES(
    ${PROJECT_SOURCE_DIR}
    #${qucs_SOURCE_DIR}/bitmaps ->no sources here
    ${PROJECT_SOURCE_DIR}/components
    ${PROJECT_SOURCE_DIR}/diagrams
    ${PROJECT_SOURCE_DIR}/dialogs
    #${qucs_SOURCE_DIR}/octave ->no sources here
    ${PROJECT_SOURCE_DIR}/paintings
    ${PROJECT_SOURCE_DIR}/tools
    )

  add_compile_definitions(${Qt6Widgets_COMPILE_DEFINITIONS}
    ${Qt6Core5Compat_COMPILE_DEFINITIONS}
    ${Qt6Core_COMPILE_DEFINITIONS}
    ${Qt6Gui_COMPILE_DEFINITIONS})

 include_directories(${Qt6Widgets_INCLUDE_DIRS}
   ${Qt6Core5Compat_INCLUDE_DIRS}
   ${Qt6Core_INCLUDE_DIRS}
   ${Qt6Gui_INCLUDE_DIRS})

#ADD_SUBDIRECTORY( bitmaps ) -> added as resources
ADD_SUBDIRECTORY( components )
ADD_SUBDIRECTORY( diagrams )
ADD_SUBDIRECTORY( dialogs )
ADD_SUBDIRECTORY( octave )
ADD_SUBDIRECTORY( python )
ADD_SUBDIRECTORY( paintings )
ADD_SUBDIRECTORY( extsimkernels )
ADD_SUBDIRECTORY( spicecomponents )
ADD_SUBDIRECTORY( tools )

SET(QUCS_SRCS
    element.cpp	octave_window.cpp	qucsdoc.cpp
    textdoc.cpp  main.cpp	schematic.cpp
    mnemo.cpp	qucs.cpp	viewpainter.cpp
    module.cpp	schematic_element.cpp	wire.cpp
    mouseactions.cpp qucs_actions.cpp	schematic_file.cpp
    wirelabel.cpp node.cpp qucs_init.cpp
    syntax.cpp misc.cpp messagedock.cpp
    imagewriter.cpp printerwriter.cpp projectView.cpp
    )

SET(QUCS_HDRS
    element.h
    main.h
    messagedock.h
    misc.h
    mnemo.h
    module.h
    mouseactions.h
    node.h
    octave_window.h
    qucs.h
    qucsdoc.h
    schematic.h
    syntax.h
    textdoc.h
    viewpainter.h
    wire.h
    wirelabel.h
    )

#
# files that have Q_OBJECT need to be MOC'ed
#
SET(QUCS_MOC_HDRS
    octave_window.h
    qucs.h
    schematic.h
    textdoc.h
    messagedock.h
    projectView.h
    )

#
# headers that need to be moc'ed
#
qt6_wrap_cpp( QUCS_MOC_SRCS ${QUCS_MOC_HDRS} )

#
# generate rules for building source files from bitmap resources
#
SET(RESOURCES qucs.qrc)
QT6_ADD_RESOURCES(RESOURCES_SRCS ${RESOURCES})

if(UNIX AND NOT APPLE)

    SET(ICON16 bitmaps/hicolor/16x16/apps/${QUCS_NAME}.png )
    SET(ICON22 bitmaps/hicolor/22x22/apps/${QUCS_NAME}.png )
    SET(ICON32 bitmaps/hicolor/32x32/apps/${QUCS_NAME}.png )
    SET(ICON48 bitmaps/hicolor/48x48/apps/${QUCS_NAME}.png )
    SET(ICON64 bitmaps/hicolor/64x64/apps/${QUCS_NAME}.png )
    SET(ICON128 bitmaps/hicolor/128x128/apps/${QUCS_NAME}.png )
    SET(ICON256 bitmaps/hicolor/256x256/apps/${QUCS_NAME}.png )
    SET(ICON512 bitmaps/hicolor/512x512/apps/${QUCS_NAME}.png )
    SET(ICONsc bitmaps/hicolor/scalable/apps/${QUCS_NAME}.svg )

    INSTALL( FILES ${ICON16} DESTINATION ${CMAKE_INSTALL_PREFIX}/share/icons/hicolor/16x16/apps)
    INSTALL( FILES ${ICON22} DESTINATION ${CMAKE_INSTALL_PREFIX}/share/icons/hicolor/22x22/apps)
    INSTALL( FILES ${ICON32} DESTINATION ${CMAKE_INSTALL_PREFIX}/share/icons/hicolor/32x32/apps)
    INSTALL( FILES ${ICON48} DESTINATION ${CMAKE_INSTALL_PREFIX}/share/icons/hicolor/48x48/apps)
    INSTALL( FILES ${ICON64} DESTINATION ${CMAKE_INSTALL_PREFIX}/share/icons/hicolor/64x64/apps)
    INSTALL( FILES ${ICON128} DESTINATION ${CMAKE_INSTALL_PREFIX}/share/icons/hicolor/128x128/apps)
    INSTALL( FILES ${ICON256} DESTINATION ${CMAKE_INSTALL_PREFIX}/share/icons/hicolor/256x256/apps)
    INSTALL( FILES ${ICON512} DESTINATION ${CMAKE_INSTALL_PREFIX}/share/icons/hicolor/512x512/apps)
    INSTALL( FILES ${ICONsc} DESTINATION ${CMAKE_INSTALL_PREFIX}/share/icons/hicolor/scalable/apps)

    SET(DESKTOP ${QUCS_NAME}.desktop )
    INSTALL( FILES ${DESKTOP} DESTINATION ${CMAKE_INSTALL_PREFIX}/share/applications)
endif()

#
#  CMake's way of creating an executable
#
ADD_EXECUTABLE( ${QUCS_NAME} MACOSX_BUNDLE WIN32
    ${QUCS_HDRS}
    ${QUCS_SRCS}
    ${QUCS_MOC_SRCS}
    ${RESOURCES_SRCS} )

#
# Tell CMake which libraries we need to link our executable against.
#
TARGET_LINK_LIBRARIES( ${QUCS_NAME}  components diagrams dialogs paintings extsimkernels spicecomponents q3lib
  Qt6::Core5Compat
  Qt6::Core
  Qt6::Widgets
  Qt6::Gui)

#
# Prepare the installation
#
SET(plugin_dest_dir bin)
SET(qtconf_dest_dir bin)
SET(APPS "${CMAKE_INSTALL_PREFIX}/bin/${PROJECT_NAME}")

#
# Install the Qucs application, on Apple, the bundle is
# installed as on other platforms it'll go into the bin directory.
#
INSTALL(TARGETS ${QUCS_NAME}
    BUNDLE DESTINATION bin COMPONENT Runtime
    RUNTIME DESTINATION bin COMPONENT Runtime
    )

#--------------------------------------------------------------------------------
# Use BundleUtilities to get all other dependencies for the application to work.
# It takes a bundle or executable along with possible plugins and inspects it
# for dependencies.  If they are not system dependencies, they are copied.

# Now the work of copying dependencies into the bundle/package
# The quotes are escaped and variables to use at install time have their $ escaped
# An alternative is the do a configure_file() on a script and use install(SCRIPT  ...).
# Note that the image plugins depend on QtSvg and QtXml, and it got those copied
# over.
INSTALL( FILES ${SCRIPTS} DESTINATION bin/ )

INSTALL( FILES ${QUCS_NAME}.1 DESTINATION share/man/man1 )

# To Create a package, one can run "cpack -G DragNDrop CPackConfig.cmake" on Mac OS X
# where CPackConfig.cmake is created by including CPack
# And then there's ways to customize this as well
#set(CPACK_BINARY_DRAGNDROP ON)
#include(CPack)



