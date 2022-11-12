#ifndef TOASTR_H
#define TOASTR_H

#include "Toastr_global.h"
#include <QWidget>
#include <QFrame>
#include <QPropertyAnimation>
#include <QTimer>
#include <QLabel>
#include <QGridLayout>
#include <QPainter>
#include <QDesktopWidget>
#include <QApplication>

QT_BEGIN_NAMESPACE
namespace Ui { class Toastr; }
QT_END_NAMESPACE


class TOASTR_EXPORT Toastr : public QFrame
{
    Q_OBJECT

    Q_PROPERTY(float popupOpacity READ getPopupOpacity WRITE setPopupOpacity)

    void setPopupOpacity(float opacity);
    float getPopupOpacity() const;
    void stateOrientation();
    void shiftOrientation(int numberElement);


public:
    Toastr(QWidget *parent = nullptr);
    ~Toastr();

    enum TOASTR_STYLE {
        MESSAGE,
        SUCCESS,
        WARNING,
        INFO,
        FAIL
    };

    enum TOASTR_ORIENTATION {
        TOP_RIGHT,
        TOP_LEFT,
        TOP_CENTER,
        TOP_FULL_WIDTH,
        BOTTOM_RIGHT,
        BOTTOM_LEFT,
        BOTTOM_CENTER,
        BOTTOM_FULL_WIDTH,
    };


    void setText(QString text);
    void setDuration(uint msec);
    void setShowDuration(uint msec);
    void setHideDuration(uint msec);
    void setStyle(TOASTR_STYLE style);
    void setIcon(QPixmap pixmap);
    void setBackgroundColor(QString color);
    void setOpacity(uint opacity);
    void setTextColor(QString color);
    void setOrientation(TOASTR_ORIENTATION orientation);


public slots:
    void show();

private slots:
    void hideAnimation();
    void hide();

    // QWidget interface
protected:
    virtual void paintEvent(QPaintEvent *event);

private:
    Ui::Toastr* ui;

    static uint TIMEOUT;
    static uint COUNT_TOASTR;
    static QVector<Toastr*> vectorToastr;

    // Timer attr
    QTimer *timer;
    uint showTimeout = 150;
    uint hideTimeout = 500;

    TOASTR_STYLE currentStyle;
    TOASTR_ORIENTATION currentOrientation = TOP_RIGHT;
    QPropertyAnimation animation;
    float popupOpacity;

    // Color attr
    QColor backgroundColor = Qt::gray;
    QString textColor = "#000000";
    uint opacity = 200;
    QColor GREEN = QColor(117,182,117,200);
    QColor RED = QColor(203,94,89,200);
    QColor YELLOW = QColor(249,171,53,200);
    QColor BLUE = QColor(88,173,196,200);
    QColor BLACK = QColor(0,0,0,200);

    const static uchar ROUND_RECT{5};
    const static uchar MARGIN_WIDTH{36};
    const static uchar SPACE_BETWEEN{10};

protected:
    virtual void enterEvent(QEvent *event);
    virtual void leaveEvent(QEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);

};


#endif // TOASTR_H
