#include "toastr.h"
#include "ui_toastr.h"
#include <QFrame>
#include <QGraphicsDropShadowEffect>
#include <QDesktopWidget>
#include <QApplication>
#include <QDebug>
#include <QTime>

uint Toastr::TIMEOUT = 2000;
uint Toastr::COUNT_TOASTR = 0;
QVector<Toastr*> Toastr::vectorToastr;

void Toastr::setPopupOpacity(float opacity)
{
    popupOpacity = opacity;
    setWindowOpacity(opacity);
}

float Toastr::getPopupOpacity() const
{
    return popupOpacity;
}

void Toastr::stateOrientation()
{
    switch (currentOrientation) {
        case TOASTR_ORIENTATION::TOP_RIGHT: {
            setGeometry(QApplication::desktop()->geometry().width() - MARGIN_WIDTH - width(),
                         QApplication::desktop()->geometry().y() + COUNT_TOASTR*(this->height() + SPACE_BETWEEN),
                        width(),
                        height());
        } break;
        case TOASTR_ORIENTATION::TOP_LEFT: {
            setGeometry(QApplication::desktop()->geometry().x() + MARGIN_WIDTH,
                         QApplication::desktop()->geometry().y() + COUNT_TOASTR*(this->height() + SPACE_BETWEEN),
                        width(),
                        height());
        } break;
        case TOASTR_ORIENTATION::TOP_CENTER: {
            setGeometry(QApplication::desktop()->geometry().x() - width()/2 + QApplication::desktop()->geometry().width()/2,
                         QApplication::desktop()->geometry().y() + COUNT_TOASTR*(this->height() + SPACE_BETWEEN),
                        width(),
                        height());
        } break;
        case TOASTR_ORIENTATION::TOP_FULL_WIDTH: {
        this->setMaximumWidth(QApplication::desktop()->geometry().width() - MARGIN_WIDTH);
            setGeometry(QApplication::desktop()->geometry().x() + MARGIN_WIDTH,
                         QApplication::desktop()->geometry().y() + COUNT_TOASTR*(this->height() + SPACE_BETWEEN),
                        QApplication::desktop()->geometry().width() - 2 * MARGIN_WIDTH,
                        height());
        } break;
        case TOASTR_ORIENTATION::BOTTOM_RIGHT: {
            setGeometry(QApplication::desktop()->geometry().width() - MARGIN_WIDTH - width(),
                        QApplication::desktop()->geometry().height() - MARGIN_WIDTH - (COUNT_TOASTR*(height() + SPACE_BETWEEN)) + QApplication::desktop()->geometry().y(),
                        width(),
                        height());
        } break;
        case TOASTR_ORIENTATION::BOTTOM_LEFT: {
            setGeometry(QApplication::desktop()->geometry().x() + MARGIN_WIDTH,
                        QApplication::desktop()->geometry().height() - MARGIN_WIDTH - (COUNT_TOASTR*(height() + SPACE_BETWEEN)) + QApplication::desktop()->geometry().y(),
                        width(),
                        height());
        } break;
        case TOASTR_ORIENTATION::BOTTOM_CENTER: {
            setGeometry(QApplication::desktop()->geometry().x() - width()/2 + QApplication::desktop()->geometry().width()/2,
                        QApplication::desktop()->geometry().height() - MARGIN_WIDTH - (COUNT_TOASTR*(height() + SPACE_BETWEEN)) + QApplication::desktop()->geometry().y(),
                        width(),
                        height());
        } break;
        case TOASTR_ORIENTATION::BOTTOM_FULL_WIDTH: {
            this->setMaximumWidth(QApplication::desktop()->geometry().width() - MARGIN_WIDTH);
            setGeometry(QApplication::desktop()->geometry().x() + MARGIN_WIDTH,
                        QApplication::desktop()->geometry().height() - MARGIN_WIDTH - (COUNT_TOASTR*(height() + SPACE_BETWEEN)) + QApplication::desktop()->geometry().y(),
                        QApplication::desktop()->geometry().width() - 2 * MARGIN_WIDTH,
                        height());
        } break;
    }
}

void Toastr::shiftOrientation(int numberElement)
{
    switch (currentOrientation) {
        case TOASTR_ORIENTATION::TOP_RIGHT: {
            setGeometry(QApplication::desktop()->geometry().width() - MARGIN_WIDTH - width(),
                        QApplication::desktop()->geometry().y() + height() + SPACE_BETWEEN + numberElement*(this->height() + SPACE_BETWEEN),
                        width(),
                        height());
        } break;
        case TOASTR_ORIENTATION::TOP_LEFT: {
            setGeometry(QApplication::desktop()->geometry().x() + MARGIN_WIDTH,
                        QApplication::desktop()->geometry().y() + height() + SPACE_BETWEEN + numberElement*(this->height() + SPACE_BETWEEN),
                        width(),
                        height());
        } break;
        case TOASTR_ORIENTATION::TOP_CENTER: {
            setGeometry(QApplication::desktop()->geometry().x() - width()/2 + QApplication::desktop()->geometry().width()/2,
                        QApplication::desktop()->geometry().y() + height() + SPACE_BETWEEN + numberElement*(this->height() + SPACE_BETWEEN),
                        width(),
                        height());
        } break;
        case TOASTR_ORIENTATION::TOP_FULL_WIDTH: {
        this->setMaximumWidth(QApplication::desktop()->geometry().width() - MARGIN_WIDTH);
            setGeometry(QApplication::desktop()->geometry().x() + MARGIN_WIDTH,
                        QApplication::desktop()->geometry().y() + height() + SPACE_BETWEEN + numberElement*(this->height() + SPACE_BETWEEN),
                        QApplication::desktop()->geometry().width() - 2 * MARGIN_WIDTH,
                        height());
        } break;
        case TOASTR_ORIENTATION::BOTTOM_RIGHT: {
            setGeometry(QApplication::desktop()->geometry().width() - MARGIN_WIDTH - width(),
                        QApplication::desktop()->geometry().height() - height() - MARGIN_WIDTH - numberElement*(this->height() + SPACE_BETWEEN),
                        width(),
                        height());
        } break;
        case TOASTR_ORIENTATION::BOTTOM_LEFT: {
            setGeometry(QApplication::desktop()->geometry().x() + MARGIN_WIDTH,
                        QApplication::desktop()->geometry().height() - height() - MARGIN_WIDTH - numberElement*(this->height() + SPACE_BETWEEN),
                        width(),
                        height());
        } break;
        case TOASTR_ORIENTATION::BOTTOM_CENTER: {
            setGeometry(QApplication::desktop()->geometry().x() - width()/2 + QApplication::desktop()->geometry().width()/2,
                        QApplication::desktop()->geometry().height() - height() - MARGIN_WIDTH - numberElement*(this->height() + SPACE_BETWEEN),
                        width(),
                        height());
        } break;
        case TOASTR_ORIENTATION::BOTTOM_FULL_WIDTH: {
            this->setMaximumWidth(QApplication::desktop()->geometry().width() - MARGIN_WIDTH);
            setGeometry(QApplication::desktop()->geometry().x() + MARGIN_WIDTH,
                        QApplication::desktop()->geometry().height() - height() - MARGIN_WIDTH - numberElement*(this->height() + SPACE_BETWEEN),
                        QApplication::desktop()->geometry().width() - 2 * MARGIN_WIDTH,
                        height());
        } break;
    }
}


Toastr::Toastr(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::Toastr)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_Hover, true);
    setWindowFlags(Qt::FramelessWindowHint |
                   Qt::Tool |
                   Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_TranslucentBackground);
    setAttribute(Qt::WA_ShowWithoutActivating);

    ui->textLabel->setStyleSheet(QString("QLabel {font: 600 10pt 'Segoe UI Semibold'; color: %1}").arg(textColor));

    animation.setTargetObject(this);
        animation.setPropertyName("popupOpacity");
        connect(&animation, &QAbstractAnimation::finished, this, &Toastr::hide);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Toastr::hideAnimation);
}

Toastr::~Toastr()
{
    delete ui;
}


void Toastr::setText(QString text)
{
    ui->textLabel->setText(text);
}

void Toastr::setDuration(uint msec)
{
    TIMEOUT = msec;
}

void Toastr::setShowDuration(uint msec)
{
    this->showTimeout = msec;
}

void Toastr::setHideDuration(uint msec)
{
    this->hideTimeout = msec;
}

void Toastr::setStyle(TOASTR_STYLE style)
{
    ui->iconLabel->show();

    switch (style) {
        case TOASTR_STYLE::MESSAGE: {
            backgroundColor = BLACK;
            backgroundColor.setAlpha(this->opacity);
            QPixmap icon = QPixmap(":/message.png");
            ui->iconLabel->setPixmap(icon);
            ui->iconLabel->setScaledContents(true);
        } break;
        case TOASTR_STYLE::SUCCESS: {
            backgroundColor = GREEN;
            backgroundColor.setAlpha(this->opacity);
            QPixmap icon = QPixmap(":/check.png");
            ui->iconLabel->setPixmap(icon);
            ui->iconLabel->setScaledContents(true);
        } break;
        case TOASTR_STYLE::WARNING: {
            backgroundColor = YELLOW;
            backgroundColor.setAlpha(this->opacity);
            QPixmap icon = QPixmap(":/warning.png");
            ui->iconLabel->setPixmap(icon);
            ui->iconLabel->setScaledContents(true);
        } break;
        case TOASTR_STYLE::INFO: {
            backgroundColor = BLUE;
            backgroundColor.setAlpha(this->opacity);
            QPixmap icon = QPixmap(":/info.png");
            ui->iconLabel->setPixmap(icon);
            ui->iconLabel->setScaledContents(true);
        } break;
        case TOASTR_STYLE::FAIL: {
            backgroundColor = RED;
            backgroundColor.setAlpha(this->opacity);
            QPixmap icon = QPixmap(":/shield.png");
            ui->iconLabel->setPixmap(icon);
            ui->iconLabel->setScaledContents(true);
        } break;
    }
}

void Toastr::setIcon(QPixmap pixmap)
{
    ui->iconLabel->show();
    ui->iconLabel->setPixmap(pixmap);
    ui->iconLabel->setScaledContents(true);
}

void Toastr::setBackgroundColor(QString color)
{
    this->backgroundColor = color;
}

void Toastr::setOpacity(uint opacity)
{
    this->backgroundColor.setAlpha(opacity);
    this->opacity = opacity;
}

void Toastr::setTextColor(QString color)
{
    ui->textLabel->setStyleSheet(QString("QLabel {font: 600 10pt 'Segoe UI Semibold'; color: %1}").arg(color));
}

void Toastr::setOrientation(TOASTR_ORIENTATION orientation)
{
    currentOrientation = orientation;
}


void Toastr::hide()
{
    if(getPopupOpacity() == 0.0){
        QWidget::hide();
        COUNT_TOASTR--;
        delete vectorToastr.first();
        vectorToastr.removeFirst();
        for(int i = 0;i<vectorToastr.length();i++) {
            vectorToastr.at(i)->shiftOrientation(i);
        }
    }
}

void Toastr::show()
{
    vectorToastr.append(this);
    COUNT_TOASTR++;

    setWindowOpacity(0.0);

    animation.setDuration(this->showTimeout);
    animation.setStartValue(0.0);
    animation.setEndValue(1.0);

    stateOrientation();

    QWidget::show();

    animation.start();
    timer->start(TIMEOUT);
}

void Toastr::hideAnimation()
{
    timer->stop();                  // Останавливаем таймер
    animation.setDuration(this->hideTimeout);    // Настраиваем длительность анимации
    animation.setStartValue(1.0);   // Стартовое значение будет 1 (полностью непрозрачный виджет)
    animation.setEndValue(0.0);     // Конечное - полностью прозрачный виджет
    animation.start();              // И запускаем анимацию

}

void Toastr::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter paint;
    paint.begin(this);
    paint.setRenderHints(QPainter::Antialiasing);
    paint.setBrush(QBrush(this->backgroundColor));
    paint.setPen(Qt::NoPen);
    paint.drawRoundedRect(this->rect(), ROUND_RECT, ROUND_RECT);
    paint.end();
}

void Toastr::enterEvent(QEvent *event)
{
    timer->stop();
    this->backgroundColor.setAlpha(255);
    QWidget::enterEvent(event);
}

void Toastr::leaveEvent(QEvent *event)
{
    timer->start();
    this->backgroundColor.setAlpha(opacity);
    QWidget::leaveEvent(event);
}

void Toastr::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    this->close();
}
