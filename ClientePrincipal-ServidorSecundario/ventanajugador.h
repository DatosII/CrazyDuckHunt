#ifndef VENTANAJUGADOR_H
#define VENTANAJUGADOR_H

#include <QPushButton>
#include <QFont>
#include <QMainWindow>
#include <iostream>
#include <QMouseEvent>
#include <QMessageBox>
#include <QLabel>
#include <QPixmap>
#include <pthread.h>
using namespace std;

/**
 * @brief The VentanaJugador class
 * Ventana en la que el usuario podra interactuar con los graficos
 * que proporciona el juego, que a su vez envia y obtiene los datos
 * del servidor(maneja la logica del juego).
 */
class VentanaJugador : public QMainWindow
{
    Q_OBJECT
private:
    char IP;
    int puerto;
    pthread_t recibo;
    pthread_t envio;
    QLabel* mira;
    QPixmap mapa;
public:
    VentanaJugador(QWidget *parent = 0);
    ~VentanaJugador();
    void setIP_Puerto(char pIP, int pPuerto);
private:
    void mouseMoveEvent(QMouseEvent* e);
    void iniciarThreadsCliente();
    static void* envios(void * argument);
    static void* recibidos(void * argument);
};

#endif // VENTANAJUGADOR_H
