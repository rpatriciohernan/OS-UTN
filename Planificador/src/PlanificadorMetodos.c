/*
 * PlanificadorMetodos.c
 *
 *  Created on: 5/9/2015
 *      Author: utnso
 */

#include "PlanificadorMetodos.h"

int escucharCpus(){
//	listaDeSocketsConectados = list_create();

	//genero dirección
			struct sockaddr_in direccionServidor;
			direccionServidor.sin_family = AF_INET;
			direccionServidor.sin_addr.s_addr = INADDR_ANY;
			direccionServidor.sin_port = htons(8080);

			//genero socket
			int servidor = socket(AF_INET, SOCK_STREAM, 0);

			int activado = 1;
			setsockopt(servidor, SOL_SOCKET, SO_REUSEADDR, &activado, sizeof(activado)); // si se cae la conexion podes mantener el puerto

			//asocio socket con la dirección antes configurada
			if(bind(servidor, (void*) &direccionServidor, sizeof(direccionServidor)) != 0){
				perror("Fallo el bind");
				return 1;
			}

			printf("Hola soy el Planificador!\n");
			printf("Estoy escuchando\n");
			//pongo a escuchar el socket y le pongo el número máximo de conexiones a aceptar
			listen(servidor, 100);


			struct sockaddr_in direccionCPU;			// Esta estructura contendra los datos de la conexion del cliente. IP, puerto, etc.
			socklen_t tamanioDireccion = sizeof(direccionCPU);

			while(1){

			int cliente = accept(servidor, (struct sockaddr *) &direccionCPU, &tamanioDireccion);

			pthread_t sniffer_thread; //para poder crear varios hilos con una sola variable
		    int* clientePersistido;
		    clientePersistido = malloc(sizeof(int));
		    *clientePersistido = cliente;

		    if( pthread_create( &sniffer_thread , NULL , (void*)manejoHiloCPU , (void*)clientePersistido ) < 0)
		    		    				puts("Fallo creacion del hilo");

			}

};


int	manejoHiloCPU(void* cliente){

	int clienteBis = *(int*)cliente;

		printf("Recibi una conexión en %d!!\n", clienteBis);

		//Recibo mensaje
		char* buffer = malloc(sizeof(char));

		//while(1){
			int bytesRecibidos = recv(clienteBis, buffer, 1, 0);
			if(bytesRecibidos <= 0){
				printf("Se desconectó el cpu");
				return 1;
			}

			buffer[bytesRecibidos] = '\0';
			printf("Me llegaron %d bytes con %s\n", bytesRecibidos, buffer);


			char* mensaje = malloc(1000);
			printf("Ingrese un mensaje: \n");
			//scanf(mensaje);
			fgets(mensaje, PACKAGESIZE, stdin);

			send(clienteBis, mensaje, strlen(mensaje)+1, 0);
		//}

		free(buffer);

		return 0;
}
