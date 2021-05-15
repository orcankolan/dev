#include <qwidget.h>
#include "samplingthread.h"

class Plot;
class Knob;
class WheelBox;
class Readbox;
class QString;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow( QWidget * = NULL );
    Readbox *d_fieldRead;
    SamplingThread *smplThread;

    void start();

    double amplitude() const;
    double frequency() const;
    double signalInterval() const;

Q_SIGNALS:
    void amplitudeChanged( double );
    void frequencyChanged( double );
    void signalIntervalChanged( double );

public Q_SLOTS:
    void updateReader( double );

private:
    Knob *d_frequencyKnob;
    Knob *d_amplitudeKnob;
    WheelBox *d_timerWheel;
    WheelBox *d_intervalWheel;

    Plot *d_plot;
};
