#include "clientecomandos.h"

/**
 * @brief clienteComandos::clienteComandos
 * Constructor de clienteComandos. No ejecuta ninguna accion.
 * Solo sirve para instanciar.
 */
clienteComandos::clienteComandos()
{
}

/**
 * @brief clienteComandos::enviar_y_recibir
 * @param pIP sera el IP que el usuario digita en el QLineEdit de la ventana.
 * @param pPuerto sera el puerto que el usuario digita en el QLineEdit de la ventana
 * @param pMensaje es el mensaje que el usuario desea enviar al servidor.
 * Basicamente el metodo setea las caracteristicas basicas necesarias para el mensaje
 * dentro de sus atributos. Crea un thread para crear la conexion y enviar el mensaje
 * de manera que no quede ininterrumpida la ejecucion de la interfaz (ventana).
 */
void clienteComandos::enviar_y_recibir(const char* pIP, int pPuerto, string pMensaje)
{
    this->IP = pIP;
    this->puerto = pPuerto;
    this->mensaje = pMensaje;
    pthread_create(&thread1,NULL,threadMensaje,this);
}

/**
 * @brief clienteComandos::threadMensaje
 * @param estaClase es un puntero que apunta a un objeto del tipo
 * clienteComandos.
 * @return un puntero tipo void.
 * El metodo es ejecutado por un thread creado en el metodo enviar_recibir.
 * Basicamente el thread envia un mensaje y espera por una respuesta antes de cerrarse.
 */
void * clienteComandos::threadMensaje(void * estaClase){
    int cliente;
    int puerto=8200;
    int bufsize=1024;
    char* buffer=new char(bufsize);
    bool salir =false;
    const char* ip = "192.168.254.7";

    struct sockaddr_in direc;
    if ((cliente=socket(AF_INET,SOCK_STREAM,0))<0){
        cout<<"Error al crear el socket cliente"<<endl;
        exit(0);
    }
    cout<<"Escriba # para acabar la comunicacion"<<endl;
    cout<<"\t\t\t[s] para empezar"<<endl;

    cout<<"Socket creado"<<endl;
    direc.sin_family=AF_INET;
    direc.sin_port=htons(puerto);
    inet_pton(AF_INET,ip,&direc.sin_addr);

    if (connect(cliente,(struct sockaddr *)&direc,sizeof(direc))==0){
        cout<<"Conexion con el servidor"<<inet_ntoa(direc.sin_addr)<<endl;
    }

    cout<<"Esperando confirmacion del servidor"<<endl;
    recv(cliente,buffer,bufsize,0);

    cout<<"Respuesta recibida: "<<buffer;
    cout<<"\nRecuerde poner asterisco al final para mandar un mensaje *\nEscriba # para terminar la conexion"<<endl;

    buffer = "Hola Gerald";
    send(cliente,buffer,bufsize,0);
    recv(cliente,buffer,bufsize,0);
    cout<<buffer<<endl;
//     do{
//         cout<<"Escribir un mensaje: ";
//         do{
//             cin>>buffer;
//             send(cliente,buffer,bufsize,0);
//             if (*buffer=='#'){
//                 send(cliente,buffer,bufsize,0);
//                 *buffer='x';
//                 salir=true;
//             }
//         }while(*buffer!=42);

//         cout<<"Mensaje recibido: ";
//         do{
//             recv(cliente,buffer,bufsize,0);
//             cout<<buffer;
//             if (*buffer=='#'){
//                 *buffer='*';
//                 salir=true;
//             }
//         }while(*buffer !=42);
//         cout<<endl;
//     }while(!salir);
//     cout<<"Conexion terminada. Programa finalizado\n\n";
//    close(cliente);
}

