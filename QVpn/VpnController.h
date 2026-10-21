#pragma once

#include <QObject>

#include "VpnState.h"
#include "QProcess"

class VpnController  : public QObject
{
	Q_OBJECT // Q_QBJECT 매크로를 선언해야 qt 기능을 사용할 수 있음. (signal, slot, property 등)

public:

public:
	VpnController( QObject* parent = nullptr );
	~VpnController(); 

	void connectVpn();
	void disConnectVpn();
	void refreshStatus();
	VpnState currentState();
	void executeOpenVpn();

private:
	VpnState _state;
	QProcess* m_openvpn;

signals:
	void stateChanged( VpnState state );
	void sendOutPutData( QByteArray data );
	void disconnecting();

public slots:
	void pushedBtnConnect();
	void onProcessOutput();
	void killOpenVpn();
	
};

