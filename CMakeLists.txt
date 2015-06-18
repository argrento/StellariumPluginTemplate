# Copyright (C) 2007 Fabien Chereau
# Copyright (C) 2015 Kirill Snezhko
#
# Based on the HelloStelModule

CMAKE_MINIMUM_REQUIRED(VERSION 2.8.11)

PROJECT(DynamicPluginTemplate)

SET(DYNAMICPLUGINTEMPLATE_VERSION "0.1.0")

FIND_PACKAGE(Qt5Core REQUIRED)
FIND_PACKAGE(Qt5Gui REQUIRED)
find_package(Qt5OpenGL REQUIRED)

SET(STELLARIUM_SOURCE_DIR $ENV{STELROOT})

INCLUDE_DIRECTORIES(
	${CMAKE_BINARY_DIR}
	${CMAKE_SOURCE_DIR}/src
	${CMAKE_SOURCE_DIR}/src/gui
	${STELLARIUM_SOURCE_DIR}/src
	${STELLARIUM_SOURCE_DIR}/src/core
	${STELLARIUM_SOURCE_DIR}/src/core/modules
	${STELLARIUM_SOURCE_DIR}/src/core/planetsephems
	${STELLARIUM_SOURCE_DIR}/src/core/external
	${STELLARIUM_SOURCE_DIR}/src/core/external/qtcompress
	${STELLARIUM_SOURCE_DIR}/src/core/external/glues_stel/source/
	${STELLARIUM_SOURCE_DIR}/src/core/external/glues_stel/source/libtess
	${STELLARIUM_SOURCE_DIR}/src/gui
	${STELLARIUM_SOURCE_DIR}/src/scripting
	${INTL_INCLUDE_DIR}
	${CMAKE_BINARY_DIR}/src
	${ZLIB_INCLUDE_DIR}
)

ADD_SUBDIRECTORY( src )

SET(QT_LINK_PARAMETERS Qt5::Core Qt5::Gui Qt5::OpenGL)

# Building 
SET(CMAKE_INSTALL_PREFIX $ENV{HOME}/.stellarium)

# TODO: Remove this hardcoded path
install(FILES builds/unix/src/libDynamicPluginTemplate.so DESTINATION modules/DynamicPluginTemplate/)
