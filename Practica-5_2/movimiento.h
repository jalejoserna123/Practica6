#ifndef MOVIMIENTO_H
#define MOVIMIENTO_H
#include <math.h>
#include <QGraphicsItem>
#include <QPainter>


#define g -9.8
#define delta 0.01
#define pi 3.141598


// se hace que la clase movimiento herede la clase QGraphicsItem
class movimiento : public QGraphicsItem
{

  double angulo,posx,posy,vx,vy,vel_ini,masa,friccion,restitucion,magnitud,ax,ay;
  int r;

public:
    //
    QRectF boundingRect() const;    //necesario definirla, devuelve el rectangulo que encierra el objeto
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //define como se pintara el objeto

    movimiento();
    movimiento(double x, double y, double v, double rd, double _masa, double vy_, double friccion_, double restitucion_, double vx);
    void ActualizaPos();
    void CalculaVelocidad();
    double getPosx() ;
    void setPosx(double value);
    double getPosy() ;
    void setPosy(double value);
    double getFriccion() const;
    void setFriccion(double value);
    double getRestitucion() const;
    void setRestitucion(double value);
};

#endif // MOVIMIENTO_H
