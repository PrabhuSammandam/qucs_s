PROJECT(qucs-suite CXX)
CMAKE_MINIMUM_REQUIRED(VERSION 3.19.0)

#set(QT_QMAKE_EXECUTABLE "/home/psammandam/Qt/6.0.1/gcc_64/bin/qmake")
#set(CMAKE_PREFIX_PATH "/home/psammandam/Qt/6.0.1/gcc_64")

SET(QUCS_NAME "qucs-s")

file (STRINGS "${qucs-suite_SOURCE_DIR}/VERSION" QUCS_VERSION)
message(STATUS "Configuring Qucs: VERSION ${QUCS_VERSION}")

set(GIT unknown)

message(STATUS "${PROJECT_NAME} ${CMAKE_INSTALL_PREFIX}
  ${qucs-suite_BINARY_DIR}" )

# FIND_PACKAGE( Qt4 REQUIRED )
find_package(Qt6 COMPONENTS Widgets Core5Compat REQUIRED)

#SET( QT_USE_QT TRUE )
#SET( QT_USE_QTXML TRUE )
#SET( QT_USE_QTSVG TRUE )
#SET( QT_USE_QTCORE TRUE )
#SET( QT_USE_QTGUI TRUE )
#SET( QT_USE_QTSCRIPT TRUE )
#SET( QT_DEBUG TRUE)

# INCLUDE( ${QT_USE_FILE} )

ADD_DEFINITIONS(${QT_DEFINITIONS})


ADD_SUBDIRECTORY( qucs )
#ADD_SUBDIRECTORY( qucs-activefilter )
#ADD_SUBDIRECTORY( qucs-filter )
ADD_SUBDIRECTORY( qucs-lib )
#ADD_SUBDIRECTORY( translations )

#ADD_SUBDIRECTORY( qucs-doc )
#ADD_SUBDIRECTORY( examples )

INSTALL(DIRECTORY "examples" DESTINATION "share/${QUCS_NAME}")

#
# Custom uninstall target
#
configure_file(
  "${CMAKE_CURRENT_SOURCE_DIR}/cmake/uninstall.cmake.in"
  "${CMAKE_CURRENT_BINARY_DIR}/uninstall.cmake"
  IMMEDIATE @ONLY)

add_custom_target(uninstall
  COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/uninstall.cmake)


