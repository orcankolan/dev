#include "mainwindow.h"
#include "plot.h"
#include "knob.h"
#include "wheelbox.h"
#include "readbox.h"
#include <qwt_scale_engine.h>
#include <qlabel.h>
#include <qlayout.h>
#include <qlcdnumber.h>
#include <QDebug>

MainWindow::MainWindow( QWidget *parent ):
    QWidget( parent ),
    smplThread(this)
{
    const double intervalLength = 50.0; // seconds

//    SamplingThread smplThread(this);

    d_plot = new Plot( this );
    d_plot->setIntervalLength( intervalLength );

    d_fieldRead = new Readbox( "Voltaj [mV]", this );
//    d_fieldRead->setValue( 0.0);

    d_amplitudeKnob = new Knob( "Genlik", 1.0, 10.0, this );
    d_amplitudeKnob->setValue( 1.0 );

//    d_frequencyKnob = new Knob( "Frekans [Hz]", 1, 20.0, this );
//    d_frequencyKnob->setValue( 1.0 );

    d_intervalWheel = new WheelBox( "Zaman Aralığı [s]", 1.0, 100.0, 1.0, this );
    d_intervalWheel->setValue( intervalLength );

    d_timerWheel = new WheelBox( "Örnek Aralığı [ms]", 10.0, 2000.0, 0.1, this );
    d_timerWheel->setValue( 10.0 );

    QVBoxLayout* vLayout1 = new QVBoxLayout();
    vLayout1->addWidget( d_fieldRead );
    vLayout1->addWidget( d_intervalWheel );
    vLayout1->addWidget( d_timerWheel );
    vLayout1->addWidget( d_amplitudeKnob );
    vLayout1->addStretch(1);
//    vLayout1->addWidget( d_frequencyKnob );

    QVBoxLayout* vLayout2 = new QVBoxLayout();
    vLayout2->addWidget( d_plot);
    vLayout2->addStretch( 1 );

    QHBoxLayout* layout = new QHBoxLayout( this );
    layout->addLayout( vLayout2, 12 );
//    layout->addStretch( 1 );
    layout->addLayout( vLayout1, 2 );

    connect( d_amplitudeKnob, SIGNAL( valueChanged( double ) ),
        SIGNAL( amplitudeChanged( double ) ) );

//    connect( d_frequencyKnob, SIGNAL( valueChanged( double ) ),
//        SIGNAL( frequencyChanged( double ) ) );
    connect( d_timerWheel, SIGNAL( valueChanged( double ) ),
        SIGNAL( signalIntervalChanged( double ) ) );

    connect( d_intervalWheel, SIGNAL( valueChanged( double ) ),
        d_plot, SLOT( setIntervalLength( double ) ) );
}

void MainWindow::start()
{
    d_plot->start();
}

void MainWindow::updateReader(double value)
{
    qDebug() << value ;
    d_fieldRead->setValue(value);
//    d_plot->replot();
}

//double MainWindow::frequency() const
//{
//    return d_frequencyKnob->value();
//}

double MainWindow::amplitude() const
{
    return d_amplitudeKnob->value();
}

double MainWindow::signalInterval() const
{
    return d_timerWheel->value();
}
