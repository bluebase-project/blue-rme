//////////////////////////////////////////////////////////////////////
// This file is part of Remere's Map Editor
//////////////////////////////////////////////////////////////////////
// Remere's Map Editor is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Remere's Map Editor is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>.
//////////////////////////////////////////////////////////////////////

#include "main.h"

#ifdef _USE_PROCESS_COM

#include "gui.h"
#include "process_com.h"


//Server

BLUERMEProcessServer::BLUERMEProcessServer()
{
	////
}

BLUERMEProcessServer::~BLUERMEProcessServer()
{
	////
}

wxConnectionBase* BLUERMEProcessServer::OnAcceptConnection(const wxString& topic)
{
	if(topic.Lower() == "rme_talk") {
		g_gui.root->Iconize(false); //Show application if minimized
		g_gui.root->Raise(); //Request the window manager to raise this application to the top of Z-order
		return newd BLUERMEProcessConnection();
	}
	return nullptr;
}


//Client

BLUERMEProcessClient::BLUERMEProcessClient() : proc(nullptr)
{
	////
}

BLUERMEProcessClient::~BLUERMEProcessClient()
{
	delete proc;
}

wxConnectionBase* BLUERMEProcessClient::OnMakeConnection()
{
	return proc = newd BLUERMEProcessConnection();
}


//Connection

BLUERMEProcessConnection::BLUERMEProcessConnection() : wxConnection()
{
	////
}

BLUERMEProcessConnection::~BLUERMEProcessConnection()
{
	////
}

bool BLUERMEProcessConnection::OnExec(const wxString& topic, const wxString& fileName)
{
	if(topic.Lower() == "rme_talk" && fileName != wxEmptyString) {
		g_gui.LoadMap(FileName(fileName));
		return true;
	}
	return false;
}

#endif
