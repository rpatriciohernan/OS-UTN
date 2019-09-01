/*
 ============================================================================
 Name        : CPU.c
 Author      : Overhead
 Version     :
 Copyright   : Property of Overhead Team
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "metodosCpu.h"

int main(void) {
//Estas variables luego se van a cargar desde el archivo de configuracion
	cantidadDeHilosCPU = 12;
	puertoPlanificador = 8080;
	puertoAdminMemoria = 8081;
	ipAdminMemoria= "127.0.0.1";



	pthread_t vec[cantidadDeHilosCPU];

//Carga estructuras para conectarse al Planificador
		struct sockaddr_in direccionServidor;
		direccionServidor.sin_family = AF_INET;
		direccionServidor.sin_addr.s_addr = inet_addr("127.0.0.1");
		direccionServidor.sin_port = htons(puertoPlanificador);
//Genera tantos hilosCPU como pida el archivo de config
		int i =0;
		for(i=0 ;i<cantidadDeHilosCPU; i++){

		int cliente = socket(AF_INET, SOCK_STREAM, 0);
		if (connect(cliente, (void*) &direccionServidor, sizeof(direccionServidor)) != 0){
			perror("No se pudo conectar a Planificador!");
			return 1;
		}else{
			int* socket = malloc(sizeof(int));
			*socket = cliente;
			//pthread_t sniffer_thread; //para poder crear varios hilos con una sola variable
			pthread_create(&vec[i],NULL,manejoHiloCPU,(void*)socket);
		}


		}
//Espera a que cada hilo termine
		for (i=0;i<cantidadDeHilosCPU;i++ ){
			pthread_join(vec[i],NULL);

		}


	return 0;
}


