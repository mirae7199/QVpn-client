#include "QVpn.h"
#include <QtWidgets/QApplication>

int main( int argc, char* argv[] )
{
    QApplication app( argc, argv );
    QVpn window;
    window.show();
    return app.exec();
}
