#include "mainwindow.h"

/**
 * @brief MainWindow::MainWindow
 * @param parent
 * Constructor de la clase MainWindow. Inicializa y define las caracteristicas
 * de los objetos de la interfaz.
 */
MainWindow::MainWindow(QWidget *parent){


//    Inicializamos los objetos GUI de la ventana principal.
    QLabel* fondo = new QLabel(this);

    QPixmap imagenFondo("/home/diego/Escritorio/CrazyDuckHunt/ClientePrincipal-ServidorSecundario/FondoPrincipal.jpg");
    QPixmap imagenSolicitarDatosAlServidor("/home/diego/Escritorio/CrazyDuckHunt/ClientePrincipal-ServidorSecundario/buttonDatosAlServidor.png");
    QPixmap imagenModoJugador("/home/diego/Escritorio/CrazyDuckHunt/ClientePrincipal-ServidorSecundario/buttonModoJugador.png");
    QPixmap imagenModoVisitante("/home/diego/Escritorio/CrazyDuckHunt/ClientePrincipal-ServidorSecundario/buttonModoVisitante.png");
    QPixmap imagenSalir("/home/diego/Escritorio/CrazyDuckHunt/ClientePrincipal-ServidorSecundario/buttonSalir.png");

    QIcon iconoComandos(imagenSolicitarDatosAlServidor);
    QIcon iconoModoJugador(imagenModoJugador);
    QIcon iconoModoVisitante(imagenModoVisitante);
    QIcon iconoSalir(imagenSalir);

    QPushButton* boton_comandos = new QPushButton(this);
    QPushButton* boton_modo_visita = new QPushButton(this);
    QPushButton* boton_modo_jugador = new QPushButton(this);
    QPushButton* boton_salir = new QPushButton(this);

//    Definimos las caracteristicas de cada uno de los objetos de la GUI

//    Colocamos fondo al menu
    fondo->setPixmap(imagenFondo);
    fondo->setMask(imagenFondo.mask());
    fondo->setGeometry(0,0,imagenFondo.width(),imagenFondo.height());
    fondo->show();

    this->resize(imagenFondo.width(),imagenFondo.height());


//    Caracteristicas de los botones
    boton_comandos->setFont(QFont("Times", 18, QFont::Bold));
    boton_comandos->setGeometry(100,100,imagenSolicitarDatosAlServidor.width(),imagenSolicitarDatosAlServidor.height());
    boton_comandos->setIcon(iconoComandos);
    boton_comandos->setIconSize(imagenSolicitarDatosAlServidor.rect().size());

    boton_modo_visita->setFont(QFont("Times", 18, QFont::Bold));
    boton_modo_visita->setGeometry(100,150,imagenModoVisitante.width(),imagenModoVisitante.height());
    boton_modo_visita->setIcon(iconoModoVisitante);
    boton_modo_visita->setIconSize(imagenModoVisitante.rect().size());

    boton_modo_jugador->setFont(QFont("Times", 18, QFont::Bold));
    boton_modo_jugador->setGeometry(100,200,imagenModoJugador.width(),imagenModoJugador.height());
    boton_modo_jugador->setIcon(iconoModoJugador);
    boton_modo_jugador->setIconSize(imagenModoJugador.rect().size());

    boton_salir->setFont(QFont("Times", 18, QFont::Bold));
    boton_salir->setGeometry(100,250,imagenSalir.width(),imagenSalir.height());
    boton_salir->setIcon(iconoSalir);
    boton_salir->setIconSize(imagenSalir.rect().size());

//    Slots y Signals
    QObject::connect(boton_comandos, SIGNAL(clicked()), this, SLOT(newVentanaIP1()));
    QObject::connect(boton_modo_visita, SIGNAL(clicked()), this, SLOT(newVentanaIP2()));
    QObject::connect(boton_modo_jugador, SIGNAL(clicked()), this, SLOT(newVentanaIP3()));
    QObject::connect(boton_salir, SIGNAL(clicked()), this, SLOT(close()));

}

/**
 * @brief MainWindow::newVentanaIP1
 * Accion que realiza el boton conectar con puerto de Administracion.
 * Crea una nueva ventana donde se le solicita el Ip y el puerto al que desea conectarse.
 */
void MainWindow::newVentanaIP1()
{
    ventanaIP* ventana = new ventanaIP();
    ventana->setTipo(1);
    this->close();
    this->deleteLater();
}

/**
 * @brief MainWindow::newVentanaIP2
 * Accion que realiza el boton conectar con Modo Jugador.
 * Crea una nueva ventana donde se le solicita el Ip y el puerto al que desea conectarse.
 */
void MainWindow::newVentanaIP2()
{
    ventanaIP* ventana = new ventanaIP();
    ventana->setTipo(2);
    this->close();
    this->deleteLater();
}

/**
 * @brief MainWindow::newVentanaIP3
 * Accion que realiza el boton conectar con el Modo Visitante.
 * Crea una nueva ventana donde se le solicita el Ip y el puerto al que desea conectarse.
 */
void MainWindow::newVentanaIP3()
{
    ventanaIP* ventana = new ventanaIP();
    ventana->setTipo(3);
    this->close();
    this->deleteLater();
}


MainWindow::~MainWindow()
{

}
