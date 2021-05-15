#include <qwt_sampling_thread.h>
#include <QSerialPort>

class QSerialPort;

class SamplingThread: public QwtSamplingThread
{
    Q_OBJECT

public:
    SamplingThread( QObject *parent = NULL );

    double frequency() const;
    double amplitude() const;

    double d_value;

public Q_SLOTS:
    void setAmplitude( double );
    void setFrequency( double );

Q_SIGNALS:
    void valueChanged( double );

protected:
    virtual void sample( double elapsed );

private slots:
    void readSerial();

private:
    virtual double value( double timeStamp ) const;
    double d_frequency;
    double d_amplitude;

    QSerialPort* serialPort;
};
