#include "readbox.h"
#include <qwt_math.h>
#include <qpen.h>
#include <qwt_knob.h>
#include <qlcdnumber.h>
#include <qwt_round_scale_draw.h>
#include <qwt_scale_engine.h>
#include <qlabel.h>
#include <qevent.h>

Readbox::Readbox( const QString &title, double min, double max, QWidget *parent ):
    QWidget( parent )
{
    QFont font( "Helvetica", 10 );

    d_number = new QLCDNumber( this );
    d_number->setSegmentStyle( QLCDNumber::Flat );
    d_number->setAutoFillBackground( true );
    d_number->setFixedHeight( d_number->sizeHint().height() * 2 );

    QPalette pal( Qt::black );
    pal.setColor( QPalette::WindowText, Qt::green );
    d_number->setPalette( pal );

    font.setBold( true );
    d_label = new QLabel( title, this );
    d_label->setFont( font );
    d_label->setAlignment( Qt::AlignTop | Qt::AlignHCenter );

    setSizePolicy( QSizePolicy::MinimumExpanding,
        QSizePolicy::MinimumExpanding );

    connect( d_number, SIGNAL( valueChanged( double ) ),
        this, SIGNAL( valueChanged( double ) ) );
}

QSize Readbox::sizeHint() const
{
    QSize sz1 = d_number->sizeHint();
    QSize sz2 = d_label->sizeHint();

    const int w = qMax( sz1.width(), sz2.width() );
    const int h = sz1.height() * 3 + sz2.height() ;

    int off = 10 ;
    off -= 15; // spacing

    return QSize( w, h - off);
}


double Readbox::value() const
{
    return d_number->value();
}

void Readbox::setTheme( const QColor &color )
{
    d_number->setPalette( color );
}

QColor Readbox::theme() const
{
    return d_number->palette().color( QPalette::Window );
}

void Readbox::resizeEvent( QResizeEvent *event )
{
    const QSize sz = event->size();
    const QSize hint = d_label->sizeHint();

    d_label->setGeometry( 0, sz.height() - hint.height(),
        sz.width(), hint.height() );

    const int numberHeight = d_number->sizeHint().height();

    int off = 30; // spacing

    d_number->setGeometry( 0, d_label->pos().y() - numberHeight - off,
        sz.width(), numberHeight );
}
