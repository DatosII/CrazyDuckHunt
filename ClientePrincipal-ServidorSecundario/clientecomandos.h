#ifndef CLIENTECOMANDOS_H
#define CLIENTECOMANDOS_H

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <string.h>
#include <pthread.h>

using namespace std;

/**
 * @brief The clienteComandos class
 * Clase que se dedicara a enviar y recibir mensajes
 * en el puerto de administracion (Solicita informacion
 * al servidor acerca del juego y sus conexiones).
 */
class clienteComandos{

    const char *IP;
    int puerto;
    string mensaje;
    pthread_t thread1;

public:
    clienteComandos();
    void enviar_y_recibir(const char *pIP, int pPuerto, string pMensaje);
private:
    static void * threadMensaje(void * argument);
};

#endif // CLIENTECOMANDOS_H

