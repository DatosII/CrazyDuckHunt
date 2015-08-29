#ifndef VENTANAVISITANTE_H
#define VENTANAVISITANTE_H

#include <QPushButton>
#include <QFont>
#include <QMainWindow>
#include <iostream>
using namespace std;

/**
 * @brief The VentanaVisitante class
 * Clase que visualizara el juego de las demas personas conectadas
 * al servidor.
 */
class VentanaVisitante : public QMainWindow
{
    Q_OBJECT
private:
    char IP;
    int puerto;

public:
    VentanaVisitante(QWidget *parent = 0);
    ~VentanaVisitante();
    void setIP_Puerto(char pIP, int pPuerto);
};

#endif // VENTANAVISITANTE_H
