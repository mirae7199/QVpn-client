#include "vpnLogPage.h"

vpnLogPage::vpnLogPage( QWidget* parent )
	: QMainWindow( parent )
{
	ui.setupUi( this );

}

vpnLogPage::~vpnLogPage()
{}

void vpnLogPage::printLog( QByteArray data )
{
	ui.textBrowser->append( QString( data ) );
}

