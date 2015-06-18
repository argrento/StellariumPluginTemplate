# Copyright (C) 2007 Fabien Chereau
# Copyright (C) 2015 Kirill Snezhko
#
# Based on the HelloStelModule

INCLUDE_DIRECTORIES(.)

LINK_DIRECTORIES(${BUILD_DIR}/src)

SET(DynamicPluginTemplate_SRCS
    # Source cde
    DynamicPluginTemplate.hpp
    DynamicPluginTemplate.cpp
    gui/DynamicPluginTemplateWindow.cpp
  	gui/DynamicPluginTemplateWindow.hpp
 )

SET(DynamicPluginTemplate_UIS
    # Forms
    gui/dynamicPluginTemplateWindow.ui
)

SET(DynamicPluginTemplate_RES_SXX
    # Resources
)

# Wrapping UI
QT5_WRAP_UI(DynamicPluginTemplate_UIS_H ${DynamicPluginTemplate_UIS})

# Library properties
ADD_LIBRARY(DynamicPluginTemplate-static MODULE ${DynamicPluginTemplate_SRCS} ${DynamicPluginTemplate_RES_SXX} ${DynamicPluginTemplate_UIS_H})
QT5_USE_MODULES(DynamicPluginTemplate-static Core Gui Declarative)
SET_TARGET_PROPERTIES(DynamicPluginTemplate-static PROPERTIES OUTPUT_NAME "DynamicPluginTemplate" AUTOMOC TRUE COMPILE_FLAGS "-DQT_DYNAMICPLUGIN")
TARGET_LINK_LIBRARIES(DynamicPluginTemplate-static ${extLinkerOption})
