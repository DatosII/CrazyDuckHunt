#include "ventanaip.h"

/**
 * @brief ventanaIP::ventanaIP
 * @param parent
 * Constructor que inicializa las parte grafica de la ventana
 * e indica los slot apropiados
 */
ventanaIP::ventanaIP(QWidget *parent){
    //    Instanciamos los objetos de la GUI de la ventana de comandos.
        QLabel* fondo = new QLabel(this);
        QPixmap imagenFondo("/home/diego/Escritorio/CrazyDuckHunt/ClientePrincipal-ServidorSecundario/FondoPrincipal.jpg");
        QPixmap imagenButton("/home/diego/Escritorio/CrazyDuckHunt/ClientePrincipal-ServidorSecundario/buttonSolicitarPeticion.png");
        QIcon iconoComandos(imagenButton);
        QPushButton* enviarPeticion = new QPushButton(this);
        pBarraIP = new QLineEdit("Escriba la IP del servidor", this);
        pBarraPuerto = new QLineEdit("Escriba el numero de puerto", this);

    //    Definimos caracteristicas de los objetos de la GUI

        this->resize(imagenFondo.width(),imagenFondo.height());

        fondo->setGeometry(0,0,imagenFondo.width(),imagenFondo.height());
        fondo->setPixmap(imagenFondo);



        pBarraIP->setGeometry(100, 100, 300, 50);
        pBarraPuerto->setGeometry(100, 200, 300, 50);

        enviarPeticion->setFont(QFont("Times", 18, QFont::Bold));
        enviarPeticion->setGeometry(250,270,imagenButton.width(),imagenButton.height());
        enviarPeticion->setIcon(iconoComandos);
        enviarPeticion->setIconSize(imagenButton.rect().size());

//        cout << pBarraIP->text().toStdString() << pBarraPuerto->text().toStdString() <<endl;


        QObject::connect(enviarPeticion, SIGNAL(clicked()), this, SLOT(newVentana()));

        this->show();
}

/**
 * @brief ventanaIP::setTipo
 * @param i
 */
void ventanaIP::setTipo(int i){
    this->tipo = i;
}

/**
 * @brief ventanaIP::newVentana
 * Metodo que abre cada una de las diferentes opciones del juego. Si es uno abre la
 * ventana de comandos. Si es dos abre la ventana de visitante.
 * Si es tres abre la ventana JUgador
 */
void ventanaIP::newVentana(){
    if(this->tipo == 1 ){

        VentanaComandos* ventana = new VentanaComandos();
        ventana->setIP_Puerto(this->pBarraIP->text().toStdString().c_str(),atoi(pBarraPuerto->text().toStdString().c_str()));
    }
    if(this->tipo == 2 )
        VentanaVisitante* ventana = new VentanaVisitante();
    if(this->tipo == 3 )
        VentanaJugador* ventana = new VentanaJugador();

//    cout << pBarraIP->text().toStdString() << pBarraPuerto->text().toStdString() <<endl;
    this->close();
}

/**
 * @brief ventanaIP::~ventanaIP
 *Desructor por defecto
 */
ventanaIP::~ventanaIP()
{

}
