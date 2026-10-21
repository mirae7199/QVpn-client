#include "VpnController.h"
#include "QProcess"

#include <QPushButton>

VpnController::VpnController( QObject* parent )
	: QObject( parent ), _state( VpnState::DISCONNECTED )
{
	connect( this, &VpnController::disconnecting, this, &VpnController::killOpenVpn );
}

VpnController::~VpnController()
{}

VpnState VpnController::currentState()
{
	return _state;
}

void VpnController::pushedBtnConnect()
{
	
	if( _state == VpnState::CONNECTED )
	{
		emit &VpnController::disconnecting;
		_state = VpnState::DISCONNECTED;
	} 
	else
	{
		_state = VpnState::CONNECTED;
		executeOpenVpn();
	}

	emit stateChanged( _state );

}

void VpnController::executeOpenVpn() 
{
	QByteArray data;
	m_openvpn = new QProcess( this );
	connect( m_openvpn, &QProcess::readyReadStandardOutput, this, &VpnController::onProcessOutput );

	QString exe = QString( "C:\\Program Files\\OpenVPN\\bin\\openvpn.exe" );
	QStringList args;

	args << "--config" << "C:\\Users\\mirae\\Desktop\\공부\\QT_study\\QVpn\\openVpn\\vpngate_public-vpn-39.opengw.net_tcp_443.ovpn";
	m_openvpn->start( exe, args );
	
	if( m_openvpn->waitForStarted() == false )
	{
		data.append( "Failed to start OpenVPN process.\n" );
	}
	else
	{
		data.append( "OpenVPN process started successfully.\n" );
	}

	onProcessOutput();

}

void VpnController::killOpenVpn()
{
	m_openvpn->kill();
}

void VpnController::onProcessOutput()
{
	emit sendOutPutData( m_openvpn->readAllStandardOutput() );
}

