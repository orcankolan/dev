#include "samplingthread.h"
#include "signaldata.h"
#include <qwt_math.h>
#include <math.h>
#include <QSerialPort>
#include <QStringList>
#include <QByteArray>
#include <QDebug>

SamplingThread::SamplingThread( QObject *parent ):
    QwtSamplingThread( parent )
{
    const QString serialPortName = "ttyACM0";

    serialPort = new QSerialPort( this );
    serialPort->setPortName(serialPortName);

    serialPort->setBaudRate(QSerialPort::Baud115200);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);

    if (!serialPort->open(QSerialPort::ReadOnly)) {
        qDebug() << QObject::tr("Failed to open port %1, error: %2")
                          .arg(serialPortName)
                          .arg(serialPort->errorString())
                       << endl;
    }
    else {
        qDebug() << QObject::tr("Port %1 is open").arg(serialPortName)<< endl;
    }

    connect( serialPort, SIGNAL(readyRead()), this, SLOT( readSerial() ) );
}


void SamplingThread::readSerial()
{
    QByteArray serialData = serialPort->readAll();
    QString serialString = QString::fromStdString(serialData.toStdString());
    QStringList serialSplit = serialString.split(" ");
    double value =  serialSplit[3].toDouble();
    d_value = value;
    valueChanged( value );
}

double SamplingThread::frequency() const
{
    return d_frequency;
}

double SamplingThread::amplitude() const
{
    return d_amplitude;
}

void SamplingThread::setFrequency( double frequency )
{
    d_frequency = frequency;
}

void SamplingThread::setAmplitude( double amplitude )
{
    d_amplitude = amplitude;
}

void SamplingThread::sample ( double elapsed )
{
    if ( d_frequency > 0.0 )
    {
        const QPointF s( elapsed, value( elapsed ) );
        SignalData::instance().append( s );
    }
}

double SamplingThread::value( double ) const
{
//    const double period = 1.0 / d_frequency;
//    const double x = ::fmod( timeStamp, period );
    const double v = d_value * d_amplitude;
    return v;
}

