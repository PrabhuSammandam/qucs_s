# qucs/dialogs library

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
  ${Qt6Gui_INCLUDE_DIRS}) # ui_*.h, out of tree

SET(DIALOGS_HDRS
  aboutdialog.h
  changedialog.h
  digisettingsdialog.h
  exportdialog.h
  importdialog.h
  labeldialog.h
  librarydialog.h
  loaddialog.h
  matchdialog.h
  newprojdialog.h
  packagedialog.h
  qucssettingsdialog.h
  savedialog.h
  searchdialog.h
  settingsdialog.h
  simmessage.h
  sweepdialog.h
  vasettingsdialog.h
  textboxdialog.h
  )



SET(DIALOGS_SRCS
  changedialog.cpp		packagedialog.cpp vasettingsdialog.cpp textboxdialog.cpp
  digisettingsdialog.cpp		qucssettingsdialog.cpp
  importdialog.cpp		savedialog.cpp labeldialog.cpp
  searchdialog.cpp     librarydialog.cpp settingsdialog.cpp
  matchdialog.cpp			simmessage.cpp newprojdialog.cpp
  sweepdialog.cpp			exportdialog.cpp loaddialog.cpp
  aboutdialog.cpp
  )

SET(DIALOGS_MOC_HDRS
  aboutdialog.h
  changedialog.h
  digisettingsdialog.h
  exportdialog.h
  importdialog.h
  labeldialog.h
  librarydialog.h
  loaddialog.h
  matchdialog.h
  newprojdialog.h
  packagedialog.h
  qucssettingsdialog.h
  savedialog.h
  searchdialog.h
  settingsdialog.h
  simmessage.h
  sweepdialog.h
  sweepdialog.h
  vasettingsdialog.h
  textboxdialog.h
  )

SET(DIALOGS_UIC_HDRS
  searchdialog.ui
  )

QT6_WRAP_CPP( DIALOGS_MOC_SRCS ${DIALOGS_MOC_HDRS} )

QT6_WRAP_UI( DIALOGS_UIC_SRCS ${DIALOGS_UIC_HDRS} )

ADD_LIBRARY(dialogs ${DIALOGS_HDRS} ${DIALOGS_SRCS} ${DIALOGS_MOC_SRCS} ${DIALOGS_UIC_SRCS})
