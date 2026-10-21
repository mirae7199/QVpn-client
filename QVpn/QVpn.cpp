#include "QVpn.h"
#include "VpnController.h"

QVpn::QVpn( QWidget* parent )
    : QMainWindow( parent )
{
    ui.setupUi( this );
    m_controller = new VpnController( this );
    m_logPage = new vpnLogPage( this );
    m_logPage->show();

    setConnections();
}

QVpn::~QVpn()
{}

void QVpn::onStateChanged( VpnState state )
{
    if( state == VpnState::CONNECTED )
	{
        ui.btn_connect->setText( "DISCONNECT" );
	}
    else
    {
        ui.btn_connect->setText( "CONNECT" );
    }
}

void QVpn::setConnections()
{
    connect( ui.btn_connect, &QPushButton::clicked, m_controller, &VpnController::pushedBtnConnect );
    connect( m_controller, &VpnController::stateChanged, this, &QVpn::onStateChanged );
    connect( m_controller, &VpnController::sendOutPutData, m_logPage, &vpnLogPage::printLog );
    
}

