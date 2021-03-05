CMAKE_MINIMUM_REQUIRED(VERSION 3.19.0)
PROJECT(q3lib CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_VERBOSE_MAKEFILE ON)

find_package(Qt6 COMPONENTS Widgets Core REQUIRED)

add_compile_options(-fPIC)
add_compile_definitions(QT_NO_THREAD ${Qt6Core_COMPILE_DEFINITIONS} ${Qt6Widgets_COMPILE_DEFINITIONS})

include_directories(${Qt6Core_INCLUDE_DIRS} ${Qt6Widgets_INCLUDE_DIRS})

set(SRCS
  q3gvector.cpp
  q3ptrcollection.cpp
  q3gdict.cpp
  q3glist.cpp
  q3scrollview.cpp
  )

set(HDRS
  q3ptrlist.h
  q3valuelist.h
  q3ptrcollection.h
  q3glist.h
  q3gvector.h
  qlinkedlist.h
  q3gdict.h
  q3ptrdict.h
  q3dict.h
  q3scrollview.h
  )

QT6_WRAP_CPP( MOC_SRCS q3scrollview.h )

add_library(${PROJECT_NAME} ${SRCS} ${HDRS} ${MOC_SRCS})

