#include "mafenetre.h"
#include "ui_mafenetre.h"
#include <QtGui>
#include <QTextStream>


void MaFenetre::tracerond(QPainter &paint, QPointF p)
{
    int rayon=4;
    paint.drawEllipse(p, rayon, rayon);
}

MaFenetre::MaFenetre(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MaFenetre)
{
    ui->setupUi(this);
}

MaFenetre::~MaFenetre()
{
    delete ui;
}

void MaFenetre::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPen trait_noir(Qt::black, 4, Qt::SolidLine);
    QBrush brosse_noire(Qt::black, Qt::SolidPattern);

    trait_noir.setCapStyle(Qt::RoundCap);
    trait_noir.setJoinStyle(Qt::RoundJoin);

    painter.setPen(trait_noir);
    painter.setBrush(brosse_noire);

    //Création des lignes horizontales
    painter.drawLine(115,95,570,95);
    painter.drawLine(115,190,570,190);
    painter.drawLine(115,295,570,295);
    painter.drawLine(115,400,570,400);

    //Création des lignes verticales
    painter.drawLine(200,95,200,295);
    painter.drawLine(300,190,300,400);
    painter.drawLine(400,95,400,190);
    painter.drawLine(400,295,400,400);
    painter.drawLine(500,190,500,295);

    //Création des points
    painter.drawPoint(200,95);
    tracerond(painter, QPointF(200, 95));
    painter.drawPoint(200,295);
    tracerond(painter, QPointF(200, 295));
    painter.drawPoint(300,190);
    tracerond(painter, QPointF(300, 190));
    painter.drawPoint(300,400);
    tracerond(painter, QPointF(300, 400));
    painter.drawPoint(400,95);
    tracerond(painter, QPointF(400, 95));
    painter.drawPoint(400,190);
    tracerond(painter, QPointF(400, 190));
    painter.drawPoint(400,295);
    tracerond(painter, QPointF(400, 295));
    painter.drawPoint(400,400);
    tracerond(painter, QPointF(400, 400));
    painter.drawPoint(500,190);
    tracerond(painter, QPointF(500, 190));
    painter.drawPoint(500,295);
    tracerond(painter, QPointF(500, 295));
}


void MaFenetre::on_chiffre1_valueChanged(int arg1)
{

}

void MaFenetre::on_chiffre2_valueChanged(int arg1)
{

}

void MaFenetre::on_chiffre3_valueChanged(int arg1)
{

}

void MaFenetre::on_chiffre4_valueChanged(int arg1)
{

}

void MaFenetre::on_pb_Stocker_released()
{
    int chiffre1 = 0;
    int chiffre2 = 0;
    int chiffre3 = 0;
    int chiffre4 = 0;

    int stock = 0;

    //Récupération des chiffres entrés par l'utilisateur
    chiffre1 = ui->chiffre1->value();
    chiffre2 = ui->chiffre2->value();
    chiffre3 = ui->chiffre3->value();
    chiffre4 = ui->chiffre4->value();

    //Connecteur 1
    if (chiffre1 > chiffre3)
    {
        stock = chiffre3;
        chiffre3 = chiffre1;
        chiffre1 = stock;
    }


    //Connecteur 2
    if (chiffre4 < chiffre2)
    {
        stock = chiffre2;
        chiffre2 = chiffre4;
        chiffre4 = stock;
    }


    //Connecteur 3
    if (chiffre2 < chiffre1)
    {
        stock = chiffre1;
        chiffre1 = chiffre2;
        chiffre2 = stock;
    }


    //Connecteur 4
    if (chiffre3 > chiffre4)
    {
        stock = chiffre4;
        chiffre4 = chiffre3;
        chiffre3 = stock;
    }


    //Connecteur 5
    if (chiffre2 > chiffre3)
    {
        stock = chiffre3;
        chiffre3 = chiffre2;
        chiffre2 = stock;
    }

    //Affichage des chiffres triés
    ui->lcdNumber->display(chiffre1);
    ui->lcdNumber2->display(chiffre2);
    ui->lcdNumber3->display(chiffre3);
    ui->lcdNumber4->display(chiffre4);

}

void MaFenetre::on_pb_Stocker_clicked()
{

}
