#include "servidor.h"
#include <iostream>

Servidor::Servidor(){

    Logica* logica = new Logica();

//    pthread_create(&thread_receive,NULL,recibir,&loop);
//    pthread_create(&thread_receive,NULL,enviar,&loop);


    while (loop){
        int clientes, servidor, pid; //sockets
        bool salir=false; //Bandera para mantener el ciclo del chat
        char* buffer=new char(bufsize); //Char que se van a enviar por medio de las funciones send y recv

        struct sockaddr_in direc;
        socklen_t tamano;

        if ((clientes=socket(AF_INET,SOCK_STREAM,0))<0){ /*Creamos el socket de dominio: AF_INET(protocolo TCP)
        tipo: SOCK_STREAM (orientado a la conexion,  el 0 se usa para escojer el protocolo adecuado*/
            cout<<"Se presento un error al crear el socket"<<endl;
            exit(1); //Se sale del programa si no se puede crear la conexion bind
        }

        cout<<"Servidor ha sido creado"<<endl;

        direc.sin_family=AF_INET; //se asigna a la estructura sockaddr_in un dominio, una ip, y un puerto.
        direc.sin_addr.s_addr=htons(INADDR_ANY); // Inaddr_any es asignarle automaticamente una direccion local.
        direc.sin_port=htons(puerto); //sin_addr y sin_port deben convertirse a network byte para ello usamos htons.

        if ((bind(clientes,(struct sockaddr*)&direc,sizeof(direc)))<0){/*bind: creamos la conexion con el puerto y el socket creando clientes,
        clientes es el socket a conectar, &direc es una estructura donde guardamos la IP local y el puerto, tamano de
        la estructura direc*/
            cout<<"Error en la conexion por Bind"<<endl;
        }
        else{
            cout<<"Conecte el cliente...../..\../..\../..\....."<<endl;
            listen(clientes,1);/*Esta funcion escucha si algun cliente se quiere conectar, el segundo parametro
            es el numero de clientes en cola*/
            tamano=sizeof(direc);

            while(loop){
                servidor=accept(clientes,(struct sockaddr *)&direc,&tamano);
                strcpy(buffer,"Conexion con cliente exitosa");
                send(servidor,buffer,bufsize,0);
                cout<< "Conexion con el cliente exitosa"<<endl;
                if(servidor<0)
                    cout<<"ERROR en aceptar"<<endl;
                pid = fork();
                if(pid == 0){
                    close(clientes);
                    dostuff(servidor);
                    exit(0);
                }

            }
        }
        close(clientes);
    }
}

void * Servidor::recibir(void * argument){
    while (*((bool*) argument))
        cout << "Estoy en el thread recibir" <<endl;
}

void Servidor::dostuff(int sock){
    while(loop){
        int n;
        char buffer[256];
        bzero(buffer,256);
        n =read(sock,buffer,255);
        if (n<0)
            cout<<"Error al leer el socket "<<endl;
        cout<< "Aqui esta el mensaje: "<<buffer<<endl;
        n = write(sock, "Tengo el mensaje",18);
        if(n<0)
            cout<<"Error al escribir el mensaje"<<endl;
    }
}


Servidor::~Servidor(){
}
