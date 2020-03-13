#ifndef PUZZLER_PLUGIN_HEADER
#define PUZZLER_PLUGIN_HEADER

//##########################################################################
//#                                                                        #
//#                CLOUDCOMPARE PLUGIN: PuzzlerPlugin                      #
//#                                                                        #
//#  This program is free software; you can redistribute it and/or modify  #
//#  it under the terms of the GNU General Public License as published by  #
//#  the Free Software Foundation; version 2 of the License.               #
//#                                                                        #
//#  This program is distributed in the hope that it will be useful,       #
//#  but WITHOUT ANY WARRANTY; without even the implied warranty of        #
//#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         #
//#  GNU General Public License for more details.                          #
//#                                                                        #
//#                             COPYRIGHT: DGM                             #
//#                                                                        #
//##########################################################################

#include "ccStdPluginInterface.h"

//! Puzzler qCC plugin
class PuzzlerPlugin : public QObject, public ccStdPluginInterface
{
	Q_OBJECT
	Q_INTERFACES(ccStdPluginInterface)
	
	// The info.json file provides information about the plugin to the loading system and
	// it is displayed in the plugin information dialog.
	Q_PLUGIN_METADATA(IID "cccorp.cloudcompare.plugin.puzzler" FILE "info.json")
	
public:
	explicit PuzzlerPlugin( QObject *parent = nullptr );
	~PuzzlerPlugin() override = default;
	
	// inherited from ccStdPluginInterface
	void onNewSelection( const ccHObject::Container &selectedEntities ) override;
	QList<QAction *> getActions() override;
	
private:
	/*** ADD YOUR CUSTOM ACTIONS HERE ***/
	void doAction();
	
	//! Default action
	/** You can add as many actions as you want in a plugin.
		Each action will correspond to an icon in the dedicated
		toolbar and an entry in the plugin menu.
	**/
	QAction* m_action;
};

#endif
