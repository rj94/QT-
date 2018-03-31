#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QDateTime>
#include <QFont>
#include <QColorDialog>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{  
    ui->setupUi(this);
    timer  = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(clockdisplay()));
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clockdisplay()
{
    QTime time = QTime::currentTime();
    QString time_text = time.toString("hh : mm : ss");
    ui->label->setStyleSheet("QLabel {background-image: url(:/resources/pic2.jpeg)}");
    if(time.minute()%2 == 0)
    {
        ui->label->setStyleSheet("QLabel { background-color : white; color : black; }");
        QPixmap pixmap(":/resources/pic1.jpg");
        pixmap = pixmap.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, pixmap);
        this->setPalette(palette);
    }
    else
    {
        ui->label->setStyleSheet("QLabel { background-color : black; color : white; }");
        QPixmap pixmap(":/resources/pic2.jpeg");
        pixmap = pixmap.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, pixmap);
        this->setPalette(palette);
    }
    ui->label->setText(time_text);
}
