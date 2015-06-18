/*
 * Copyright (C) 2007 Fabien Chereau
 * Copyright (C) 2015 Kirill Snezhko
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Suite 500, Boston, MA  02110-1335, USA.
 */

#include "StelApp.hpp"
#include "StelCore.hpp"
#include "StelLocaleMgr.hpp"
#include "StelModuleMgr.hpp"

#include "DynamicPluginTemplate.hpp"
#include "DynamicPluginTemplateWindow.hpp"

#include <QDebug>

/*************************************************************************
 This method is the one called automatically by the StelModuleMgr just 
 after loading the dynamic library
*************************************************************************/
StelModule* DynamicPluginTemplatePluginInterface::getStelModule() const
{
	return new DynamicPluginTemplate();
}

StelPluginInfo DynamicPluginTemplatePluginInterface::getPluginInfo() const
{
	StelPluginInfo info;
	info.id = "DynamicPluginTemplate";
	info.displayedName = N_("Dynamic Plugin Template");
	info.authors = "Kirill Snezhko";
	info.contact = "snezhko.kirill@gmail.com";
	info.description = N_("Startpoint for the dynamic plugin development.");
	return info;
}

/*************************************************************************
 Constructor
*************************************************************************/
DynamicPluginTemplate::DynamicPluginTemplate()
{
	setObjectName("DynamicPluginTemplate");
	mainWindow = new DynamicPluginTemplateWindow();
}

/*************************************************************************
 Destructor
*************************************************************************/
DynamicPluginTemplate::~DynamicPluginTemplate()
{
}

/*************************************************************************
 Reimplementation of the getCallOrder method
*************************************************************************/
double DynamicPluginTemplate::getCallOrder(StelModuleActionName actionName) const
{
	return 0.;
}

bool DynamicPluginTemplate::configureGui(bool show)
{
	if (show)
		mainWindow->setVisible(true);

	return true;
}

/*************************************************************************
 Init our module
*************************************************************************/
void DynamicPluginTemplate::init()
{
	qDebug() << "init called for DynamicPluginTemplate";
}

void DynamicPluginTemplate::deinit()
{
	delete mainWindow;
}
