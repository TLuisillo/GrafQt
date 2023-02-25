#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)


{
    ui->setupUi(this);

    //DEC
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), ui->lcdNumber, SLOT (display(int)));
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), ui->lcdNumber_4, SLOT (display(int)));
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), ui->lcdNumber_7, SLOT (display(int)));

    //HEXA
     connect(ui->horizontalSlider_2, SIGNAL(valueChanged(int)), ui->lcdNumber_2, SLOT (display(int)));
     connect(ui->horizontalSlider_2, SIGNAL(valueChanged(int)), ui->lcdNumber_5, SLOT (display(int)));
     connect(ui->horizontalSlider_2, SIGNAL(valueChanged(int)), ui->lcdNumber_8, SLOT (display(int)));

     //BIN
      connect(ui->horizontalSlider_3, SIGNAL(valueChanged(int)), ui->lcdNumber_3, SLOT (display(int)));
      connect(ui->horizontalSlider_3, SIGNAL(valueChanged(int)), ui->lcdNumber_6, SLOT (display(int)));
      connect(ui->horizontalSlider_3, SIGNAL(valueChanged(int)), ui->lcdNumber_9, SLOT (display(int)));
}

Dialog::~Dialog()
{
    delete ui;
}




void Dialog::on_horizontalSlider_valueChanged(int value)
{
    int rojo =value;
    int verde = ui->horizontalSlider_2->value();
    int azul = ui->horizontalSlider_3->value();
    QColor colorRGB = QColor(rojo,verde,azul);
    QString colorString = colorRGB.name();
    QString colorSeleccionado = "QWidget{background-color : " + colorString + "}";
    ui->widget->setStyleSheet(colorSeleccionado);
}


void Dialog::on_horizontalSlider_2_valueChanged(int value)
{
    int rojo = ui->horizontalSlider->value();
    int verde = value;
    int azul = ui->horizontalSlider_3->value();
    QColor colorRGB = QColor(rojo,verde,azul);
    QString colorString = colorRGB.name();
    QString colorSeleccionado = "QWidget{background-color : " + colorString + "}";
    ui->widget->setStyleSheet(colorSeleccionado);
}


void Dialog::on_horizontalSlider_3_valueChanged(int value)
{
    int rojo = ui->horizontalSlider->value();
    int verde = ui->horizontalSlider_2->value();
    int azul = value;
    QColor colorRGB = QColor(rojo,verde,azul);
    QString colorString = colorRGB.name();
    QString colorSeleccionado = "QWidget{background-color : " + colorString + "}";
    ui->widget->setStyleSheet(colorSeleccionado);
}

