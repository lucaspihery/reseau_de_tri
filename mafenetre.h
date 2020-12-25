#ifndef MAFENETRE_H
#define MAFENETRE_H

#include <QMainWindow>
#include <QList>
#include <QLabel>
#include <QApplication>
#include <QWidget>
#include <QtGui>


QT_BEGIN_NAMESPACE
namespace Ui { class MaFenetre; }
QT_END_NAMESPACE

class MaFenetre : public QMainWindow
{
    Q_OBJECT
private:
    void tracerond(QPainter &paint, QPointF p);
public:
    MaFenetre(QWidget *parent = nullptr);
    ~MaFenetre();

    Ui::MaFenetre *ui;

    void paintEvent(QPaintEvent *);

private slots:
    void on_chiffre1_valueChanged(int arg1);
    void on_chiffre2_valueChanged(int arg1);
    void on_chiffre3_valueChanged(int arg1);
    void on_chiffre4_valueChanged(int arg1);
    void on_pb_Stocker_clicked();

    void on_pb_Stocker_released();
};


#endif // MAFENETRE_H
