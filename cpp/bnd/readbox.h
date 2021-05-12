#ifndef READBOX_H
#define READBOX_H

#include <qwidget.h>

class QLCDNumber;
class QLabel;

class Readbox: public QWidget
{
    Q_OBJECT

    Q_PROPERTY( QColor theme READ theme WRITE setTheme )

public:
    Readbox ( const QString &title,
        double min, double max, QWidget *parent = NULL );

    virtual QSize sizeHint() const;

    void setValue( double value );
    double value() const;

    void setTheme( const QColor & );
    QColor theme() const;

Q_SIGNALS:
    double valueChanged( double );

protected:
    virtual void resizeEvent( QResizeEvent * );

private:
    QLCDNumber *d_number;
    QLabel *d_label;
};

#endif // READBOX_H
