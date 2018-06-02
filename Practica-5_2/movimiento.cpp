#include "movimiento.h"
#define dt 0.1
#define G 10
#include "mainwindow.h"



double movimiento::getPosx()
{
    return posx;
}

void movimiento::setPosx(double value)
{
    posx = value;
}

double movimiento::getPosy()
{
    return posy;
}

void movimiento::setPosy(double value)
{
    posy = value;
}
double movimiento::getFriccion() const
{
    return friccion;
}

void movimiento::setFriccion(double value)
{
    friccion = value;
}

double movimiento::getRestitucion() const
{
    return restitucion;
}

void movimiento::setRestitucion(double value)
{
    restitucion = value;
}

QRectF movimiento::boundingRect() const
{
   return QRectF(-r,-r,2*r,2*r); // crea un rectangulo

}

void movimiento::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::blue);        //asigna el color
    painter->drawEllipse(boundingRect()); // dibuja una elipse con base en el rectagulo creado
}
movimiento::movimiento()
{
    angulo=0;
    posx=0;
    posy=0;
    vel_ini=0;
    vy=0;
    vx=0;
    r=5;
    magnitud=0;
    ax=0;
    ay=0;
}

movimiento::movimiento( double x, double y, double v,double rad,double _masa,double vy_,double friccion_,double restitucion_,double vx_)
{
    //angulo=a;
    posx=x;
    posy=y;
    vel_ini=v;
    r=rad;
    masa= _masa;
    friccion=friccion_;
    restitucion=restitucion_;
    vy=vy_;
    vx=vx_;
}

void movimiento::ActualizaPos()
{
    CalculaVelocidad();
// condiciones para simular las coliciones con los ejes coordenados y con las paredes del rectanguo de la escena
    if(posy<-250)
        posy=-250;


        if(posx+r>=500 || posx-r<=-500)
            vx=-restitucion*vx;

        if(posy+r>=250 || posy-r<=-250)
            vy=-restitucion*vy;


    //ay = -(((friccion*(magnitud*magnitud)))*((r*r)/masa )*sin(angulo))-G;
  // ecuaciones que actulizan la posición del cuerpo
    posx=posx+((vx*(dt*dt))+ (ax*(dt*dt)))*0.5;
    posy=posy+((vy*(dt*dt))+ (ay*(dt*dt)))*0.5;


    // condición que simula cuando la particula toca el suelo


   // modifica la posición del objeto gráfico
    setPos(posx,-posy);

}

void movimiento::CalculaVelocidad()
{
    angulo=atan2(vy,vx);
    magnitud= pow((vx*vx)+(vy*vy),2);
    ax = -(((friccion*(magnitud)))*((r*r)/masa )*cos(angulo));
    ay = -(((friccion*(magnitud)))*((r*r)/masa )*sin(angulo))-G;
    vy=vy+ay*dt;
    vx=vx+ax*dt;

}
