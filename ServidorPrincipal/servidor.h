#ifndef SERVIDOR_H
#define SERVIDOR_H

#include <logica.h>
#include <pthread.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>

#define puerto 8200
#define bufsize 1024

using namespace std;

class Servidor{

    bool loop = true;
    pthread_t thread_receive;

public:
    Servidor();
    ~Servidor();

private:
    static void * recibir(void * argument);
    void dostuff(int sock);
};

#endif // SERVIDOR_H
