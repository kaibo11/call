#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDoubleValidator"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QDoubleValidator *doublevalidator = new QDoubleValidator(this); // 默认范围为任意双精度浮点数

    ui->price1->setValidator(doublevalidator);
    ui->price2->setValidator(doublevalidator);
    ui->price3->setValidator(doublevalidator);
    ui->price4->setValidator(doublevalidator);
    ui->price5->setValidator(doublevalidator);


    ui->cost1->setValidator(new QRegExpValidator(QRegExp("[1-9]\\d*"), ui->cost1));
    ui->cost2->setValidator(new QRegExpValidator(QRegExp("[1-9]\\d*"), ui->cost2));
    ui->cost3->setValidator(new QRegExpValidator(QRegExp("[1-9]\\d*"), ui->cost3));
    ui->cost4->setValidator(new QRegExpValidator(QRegExp("[1-9]\\d*"), ui->cost4));
    ui->cost5->setValidator(new QRegExpValidator(QRegExp("[1-9]\\d*"), ui->cost5));
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_calButton_clicked()
{

    int costall =0;

    if(ui->price1->text().isEmpty() || ui->cost1->text().isEmpty()){
        return;
    }
    double cost1 = ui->cost1->text().toInt();
    double  price1 = ui->price1->text().toDouble(); // 返回转换后的浮点数，如果转换失败，返回0.0 // 返回转换后的整数，如果转换失败，返回0
    costall+= cost1;

    if(ui->price2->text().isEmpty() || ui->cost2->text().isEmpty()){
         double result = costall/(cost1/price1);
            ui->costAndRate->setText(QString::number(result));
         double decreasePercentage = ((result - price1) / price1) * 100.0;
         QString percentageString = QString("-%1%").arg(decreasePercentage, 0, 'f', 2);
         ui->rate->setText(percentageString);


         // 设置出货价格
         double qingcangjia = result*1.01;
         ui->qingcangjiage->setText(QString::number(qingcangjia));


         // 设置尾盘补仓价格
         ui->bucangjiage->setText(QString::number(price1*0.95));
         return;
        return;
    }
    double cost2 = ui->cost2->text().toInt();
    double price2 = ui->price2->text().toDouble();
    costall+= cost2;

    if(ui->price3->text().isEmpty() || ui->cost3->text().isEmpty()){
        double result = costall/(cost1/price1 + cost2/price2);
        ui->costAndRate->setText(QString::number(result));

        double decreasePercentage = ((result - price2) / price2) * 100.0;
        QString percentageString = QString("-%1%").arg(decreasePercentage, 0, 'f', 2);
        ui->rate->setText(percentageString);


        // 设置出货价格
        double qingcangjia = result*1.01;
        ui->qingcangjiage->setText(QString::number(qingcangjia));


        // 设置尾盘补仓价格
        ui->bucangjiage->setText(QString::number(price2*0.95));
        return;
        return;
    }

    double cost3 = ui->cost3->text().toInt();
    double price3 = ui->price3->text().toDouble();
    costall+= cost3;

    if(ui->price4->text().isEmpty() || ui->cost4->text().isEmpty()){
        double result = costall/(cost1/price1 + cost2/price2 + cost3/price3);
        ui->costAndRate->setText(QString::number(result));

        double decreasePercentage = ((result - price3) / price3) * 100.0;
        QString percentageString = QString("-%1%").arg(decreasePercentage, 0, 'f', 2);
        ui->rate->setText(percentageString);


        // 设置出货价格
        double qingcangjia = result*1.01;
        ui->qingcangjiage->setText(QString::number(qingcangjia));


        // 设置尾盘补仓价格
        ui->bucangjiage->setText(QString::number(price3*0.95));
        return;
    }

    double cost4 = ui->cost4->text().toInt();
    double price4 = ui->price4->text().toDouble();
    costall+= cost4;

    if(ui->price5->text().isEmpty() || ui->cost5->text().isEmpty()){
        double result = costall/(cost1/price1 + cost2/price2 + cost3/price3 + cost4/price4);
        ui->costAndRate->setText(QString::number(result));
        double decreasePercentage = ((result - price4) / price4) * 100.0;
        QString percentageString = QString("-%1%").arg(decreasePercentage, 0, 'f', 2);
        ui->rate->setText(percentageString);


        // 设置出货价格
        double qingcangjia = result*1.01;
        ui->qingcangjiage->setText(QString::number(qingcangjia));


        // 设置尾盘补仓价格
        ui->bucangjiage->setText(QString::number(price4*0.95));
        return;
    }

    double cost5 = ui->cost5->text().toInt();
    double price5 = ui->price5->text().toDouble();
    costall+= cost5;

   // 设置持仓成本，====回本价格
   double resultAll = costall/(cost1/price1 + cost2/price2 + cost3/price3 + cost4/price4 + cost5/price5);
    ui->costAndRate->setText(QString::number(resultAll));

   // 设置涨多少回本，也就是说亏了百分之多少。
   double decreasePercentage = ((resultAll - price5) / price5) * 100.0;
   QString percentageString = QString("-%1%").arg(decreasePercentage, 0, 'f', 2);
   ui->rate->setText(percentageString);

   // 设置出货价格
   double qingcangjia = resultAll*1.01;
   ui->qingcangjiage->setText(QString::number(qingcangjia));


   // 设置尾盘补仓价格
   ui->bucangjiage->setText(QString::number(price5*0.95));

}


void MainWindow::on_clearPrice_clicked()
{
    ui->price1->clear();
    ui->price2->clear();
    ui->price3->clear();
    ui->price4->clear();
    ui->price5->clear();
}


void MainWindow::on_clearButton_clicked()
{
    ui->price1->clear();
    ui->price2->clear();
    ui->price3->clear();
    ui->price4->clear();
    ui->price5->clear();

}

