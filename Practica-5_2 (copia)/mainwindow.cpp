#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <time.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scena= new QGraphicsScene;   // crea una nueva escena
    timer =new QTimer;          // crea un nuevo objeto tipo timer
    ui->graphicsView->setScene(scena);   // Set del graphisView con la escena creada
    scena->setSceneRect(-500,-250,1000,500); // Set del retangulo de la escena con los parametros (x,y,ancho,alto)
    scena->addRect(scena->sceneRect());    // Adiciona a la escena el rectangulo con las nuevas propiedades
    connect(timer,SIGNAL(timeout()),this,SLOT(mover())); // conexion del timer con el slot mover()
    srand(NULL);
   // rect2= scena->addRect(-300,0,100,0);
   // rect3= scena->addRect(300,0,100,0);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Start_clicked()
{
   float x = -499+rand()%1000;
   float y = 50+rand()%190;
   float v = 0+rand()%300;
   float r = 5+rand()%25;
   float m= 50+rand()%550;
   float vy= -300+rand()%600;
   float f= rand()%10/1000;
   float res=0.5;
   res+=rand()%5/10;
   float vx= -300+rand()%600;



   cuerpo.push_back(new movimiento(x,y,v,r,m,vy,f,res,vx));  // se adiciona un nuevo objeto a la lista y se pone al final de la lista
   cuerpo.back()->ActualizaPos();
   scena->addItem(cuerpo.back());   // se adiciona el ultimo objeto de la lista a la escena
   qDebug() <<x << y<< v <<res << endl ;  // imprime en la consola de QT los datos ingresados por el usuario
   timer->start(10);     //se inicializa el timer con una base de tiempo de 10 ms.
}
void MainWindow::mover()
{

    // con este for se recorre toda la lista y a cada objeto de la lista se le actualiza la posición
    for (list<movimiento*>::iterator it=cuerpo.begin(); it != cuerpo.end(); ++it)
         (*it)->ActualizaPos();

}

void MainWindow::on_pushButton_clicked()
{
  // cierra el widget
    this->close();
}
