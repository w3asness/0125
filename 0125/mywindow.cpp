#include "mywindow.h"

MyWindow::MyWindow(QWidget *parent) : QWidget(parent){
this->setGeometry(100,100,300,500);

    lcd = new QLCDNumber(this);
    lcd->setGeometry(100,50,100,40);

    btnStart = new QPushButton(this);
    btnStart->setGeometry(100,100,100,30);
    btnStart->setText("Start");

    edt = new QLineEdit(this);
    edt->setGeometry(100,10,100,30);

    btnUp = new QRadioButton(this);
    btnUp->setGeometry(10,300,200,30);
    btnUp->setText("Straight");
    btnUp->setChecked(true);

    btnDown = new QRadioButton(this);
    btnDown->setGeometry(200,300,200,30);
    btnDown->setText("Backwards");

    timer = new QTimer(this);
    timer->setInterval(1000);

    second = 0;

    connect(timer,SIGNAL(timeout()),this,SLOT(time()));
    connect(btnStart,SIGNAL(pressed()),this,SLOT(time()));
    connect(edt, SIGNAL(textEdited(QString)),this,SLOT(change(QString)));
}

void MyWindow::time(){
    if (btnUp->isChecked()){
       second++;
        }
    else {
        second--;
    }
    lcd->display(second);
}

void MyWindow::start()
{
    if (timer->isActive()) {
        timer->stop();
        btnStart->setText("Stop");
    }
}

void MyWindow::change(QString newText){
timer->stop();
btnStart->setText("Start");

second = newText.toInt();
lcd->display(second);
}
