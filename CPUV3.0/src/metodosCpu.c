/*
 * metodosCpu.c
 *
 *  Created on: 5/9/2015
 *      Author: utnso
 */
#include "metodosCpu.h" //

#define PACKAGESIZE 1024

/*
int conectarPlanificador(){
	struct sockaddr_in direccionPlanif;
	direccionPlanif.sin_family = AF_INET;
	direccionPlanif.sin_addr.s_addr = inet_addr("127.0.0.1");
	direccionPlanif.sin_port = htons(puertoPlanificador);

	int sock_Planif = socket(AF_INET, SOCK_STREAM, 0);
	if (connect(sock_Planif, (void*) &direccionPlanif, sizeof(direccionPlanif)) != 0){
		perror("No se pudo conectar a Planificador!");
		return 1;
	}

	while(1){
		//Envio mensaje
		char* mensaje = malloc(1000);
		printf("Ingrese un mensaje: \n");
		fgets(mensaje, PACKAGESIZE, stdin);

		send(sock_Planif, mensaje, strlen(mensaje)+1, 0);

		//Recibo mensaje
		buffer = malloc(1000);
		int bytesRecibidos = recv(sock_Planif, buffer, 1000, 0);
		if(bytesRecibidos <= 0){
			printf("Se desconectó el cpu");
			return 1;
		}

		buffer[bytesRecibidos] = '\0';
		printf("Me llegaron %d bytes con %s\n", bytesRecibidos, buffer);




	// IMPORTANTE
		// a Continuacion el filtro por cada tipo de instruccion que puede recibir el CPU

/*
		char* instruccionAEjecutar = malloc(100);
		fgets(instruccionAEjecutar, PACKAGESIZE, stdin);
		if (*instruccionAEjecutar == "iniciar") {
			void instruccionIniciar(int valor_retorno);
			printf("Se ejecuta la instruccion iniciar/n");
		}
		else {
			if (*instruccionAEjecutar == "leer") {
				void instruccionLeer(int valor_retorno);
				printf("Se ejecuta la instruccion leer/n");
			}
			else {
				if (*instruccionAEjecutar == "escribir"){
					void instruccionEscribir(int valor_retorno);
					printf("Se ejecuta la instruccion escribir/n");
				}
				else {
					if (*instruccionAEjecutar == "entrada-salida"){
						void instruccionEntradaSalida(int valor_retorno);
						printf("Se ejecuta la instruccion Entrada-Salida/n");
					}
					else {
						if (*instruccionAEjecutar == "finalizar") {
							void instruccionFinalizar(int valor_retorno);
							printf("Se ejecuta la instruccion finalizar/n");
						}
						else {printf("No conozco la instrucción/n");}
					}
				}
			}
		}
*/



void* manejoHiloCPU(void* socket){

/*	while(1){
		char* mensaje = malloc(1000);
		printf("Ingrese un mensaje: \n");
		fgets(mensaje, PACKAGESIZE, stdin);

		send(socket, mensaje, strlen(mensaje)+1, 0);
		return 1;
		free(mensaje);
}
*/    int socketPlanificador = *(int*)socket;

	char* letra = malloc(sizeof(char));
	letra = "a";
	send(socketPlanificador,(void*)letra,1,0);

	conectarAdminMemoria();

	return 0;

}




int conectarAdminMemoria(){
	struct sockaddr_in direccionAdmMemoria;
	direccionAdmMemoria.sin_family = AF_INET;
	direccionAdmMemoria.sin_addr.s_addr = inet_addr(ipAdminMemoria);
	direccionAdmMemoria.sin_port = htons(puertoAdminMemoria);

	int sock_AdmMem = socket(AF_INET, SOCK_STREAM, 0);
	if (connect(sock_AdmMem, (void*) &direccionAdmMemoria, sizeof(direccionAdmMemoria)) != 0){
		perror("No se pudo conectar a Administrador de Memoria!");
		return 1;
	}

	while(1){
		/*char* mensaje = malloc(1000);
		printf("Ingrese un mensaje: \n");
		fgets(mensaje, PACKAGESIZE, stdin);*/

		send(sock_AdmMem, buffer, strlen(buffer)+1, 0);
		return 1;
	}
}
