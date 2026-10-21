#pragma once

#include <QMainWindow>
#include <QObject>

#include "ui_log.h"
#include "VpnController.h"

class vpnLogPage  : public QMainWindow	
{
	Q_OBJECT

public:
	vpnLogPage( QWidget* parent = nullptr );
	~vpnLogPage();

private:
	Ui::log ui;

public slots:
	void printLog( QByteArray data );
};

