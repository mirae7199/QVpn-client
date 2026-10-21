#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QVpn.h"
#include "VpnController.h"
#include "vpnLogPage.h"

class QVpn : public QMainWindow
{
    Q_OBJECT

public:
    QVpn( QWidget* parent = nullptr );
    ~QVpn();
	void setConnections();


private:
    Ui::QVpnClass ui;
    VpnController* m_controller;
    vpnLogPage* m_logPage;

private slots:
    void onStateChanged( VpnState state );
    
};

