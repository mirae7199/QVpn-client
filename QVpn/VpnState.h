#pragma once


enum class VpnState {
	UNKNOWN = 0,
	DISCONNECTED = 1,
	CONNECTING = 2,
	CONNECTED = 3,
	DISCONNECTING = 4,
	ERROR = 5,
};
