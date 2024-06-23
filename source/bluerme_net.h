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

#if 0

#ifndef _BLUERME_NET_H_
#define _BLUERME_NET_H_

#include "net_connection.h"

class BLUERMENet : public wxEvtHandler, public NetSocket
{
	~BLUERMENet();
public:
	BLUERMENet(wxEvtHandler* event_dump);

	bool Connect();
	void Close();
	void Log(wxString message) {}

	void HandleEvent(wxSocketEvent& evt);

	bool CanHostLive() { return can_host; }

protected:
	void OnParsePacket(NetworkMessage* nmsg);

	void OnReceiveWelcome(NetworkMessage* nmsg);
	void OnReceiveDisconnect(NetworkMessage* nmsg);
	void OnReceivePing(NetworkMessage* nmsg);

	wxSocketClient* socket;
	NetworkConnection* connection;
	bool can_host;

	wxEvtHandler* event_dump;
};

//=============================================================================
// Events

extern const wxEventType EVT_BLUERMENET_CONNECTION_ESTABLISHED;

#define EVT_BLUERMENET_CONNECTION_ESTABLISHED(id, fn) \
    DECLARE_EVENT_TABLE_ENTRY( \
        EVT_BLUERMENET_CONNECTION_ESTABLISHED, id, wxID_ANY, \
        (wxObjectEventFunction)(wxEventFunction) wxStaticCastEvent( wxCommandEventFunction, &fn ), \
        (wxObject *) nullptr \
    ),

extern const wxEventType EVT_BLUERMENET_CONNECTION_LOST;

#define EVT_BLUERMENET_CONNECTION_LOST(id, fn) \
    DECLARE_EVENT_TABLE_ENTRY( \
        EVT_BLUERMENET_CONNECTION_LOST, id, wxID_ANY, \
        (wxObjectEventFunction)(wxEventFunction) wxStaticCastEvent( wxCommandEventFunction, &fn ), \
        (wxObject *) nullptr \
    ),

extern const wxEventType EVT_BLUERMENET_SHOW_SERVLIST;

#define EVT_BLUERMENET_SHOW_SERVLIST(id, fn) \
    DECLARE_EVENT_TABLE_ENTRY( \
        EVT_BLUERMENET_SHOW_SERVLIST, id, wxID_ANY, \
        (wxObjectEventFunction)(wxEventFunction) wxStaticCastEvent( wxCommandEventFunction, &fn ), \
        (wxObject *) nullptr \
    ),

#endif

#endif
