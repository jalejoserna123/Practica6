#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QGraphicsRectItem>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>
#include <movimiento.h>
#include <list>

using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QGraphicsRectItem* rect2;
    QGraphicsRectItem* rect3;

private slots:
    void on_Start_clicked();     // slot del boton que inica la simulacion
    void on_pushButton_clicked();// slot del boton cierra la el widget
    void mover();                // slot que ejecuta el timer y actualiza el movimiento de los cuerpos

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scena;    // crea la escena donde se observara la simulación
    QTimer *timer;            // crea el timer que permite la actualización de los frame
    list < movimiento*> cuerpo; // crea una lsita de objetos de la clase movimiento

};

#endif // MAINWINDOW_H
