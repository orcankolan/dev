#include <qapplication.h>
#include "mainwindow.h"


int main( int argc, char **argv )
{
    QApplication app( argc, argv );
    app.setPalette( Qt::gray );

    MainWindow window;
    window.resize( 860, 490 );

//    window.smplThread->setFrequency( window.frequency() );
    window.smplThread->setAmplitude( window.amplitude() );
    window.smplThread->setInterval( window.signalInterval() );

    window.connect( &window, SIGNAL( frequencyChanged( double ) ),
        window.smplThread, SLOT( setFrequency( double ) ) );

    window.connect( &window, SIGNAL( amplitudeChanged( double ) ),
        window.smplThread, SLOT( setAmplitude( double ) ) );

    window.connect( &window, SIGNAL( signalIntervalChanged( double ) ),
        window.smplThread, SLOT( setInterval( double ) ) );

    window.connect( window.smplThread, SIGNAL( valueChanged( double ) ),
        &window, SLOT( updateReader( double ) ) );

    window.show();
    window.smplThread->start();
    window.start();

    bool ok = app.exec();

    window.smplThread->stop();

    window.smplThread->wait( 1000 );

    return ok;
}
