/*
 * LaMemoriaMetodos.c
 *
 *  Created on: 5/9/2015
 *      Author: utnso
 */

#include "LaMemoriaMetodos.h"

int conectarseASWAP () {


	struct sockaddr_in direccionAdminSwap;
	direccionAdminSwap.sin_family = AF_INET;
	direccionAdminSwap.sin_addr.s_addr = inet_addr(ipAdminSwap);
	direccionAdminSwap.sin_port = htons(puertoAdminSwap);

	int sock_AdminSwap = socket(AF_INET, SOCK_STREAM, 0);
	if (connect(sock_AdminSwap, (void*) &direccionAdminSwap, sizeof(direccionAdminSwap)) != 0){
		perror("No se pudo conectar con Administrador Swap\n");
		return 1;
	}

	while(1){
		send(sock_AdminSwap, buffer, strlen(buffer)+1, 0);
		return 1;
	}



			return 0;
		}



int escucharCPU () {
	//genero dirección Servidor
	struct sockaddr_in direccionServidor;
	direccionServidor.sin_family = AF_INET;
	direccionServidor.sin_addr.s_addr = INADDR_ANY;
	direccionServidor.sin_port = htons(8100);


	//genero socket servidor
	int servidor = socket(AF_INET, SOCK_STREAM, 0);

	int activado = 1;
	setsockopt(servidor, SOL_SOCKET, SO_REUSEADDR, &activado, sizeof(activado));

	//asocio socket con la dirección antes configurada
	if(bind(servidor, (void*) &direccionServidor, sizeof(direccionServidor)) != 0){
		perror("Fallo el bind");
		return 1;
	}

	printf("Administrador de Memoria escuchando\n");
	//pongo a escuchar el socket y le pongo el número máximo de conexiones a aceptar
	listen(servidor, 100);

	struct sockaddr_in direccionCliente;			// Esta estructura contendra los datos de la conexion del cliente. IP, puerto, etc.
	socklen_t tamanioDireccion = sizeof(direccionCliente);
	int sock_CPU = accept(servidor, (struct sockaddr *) &direccionCliente, &tamanioDireccion);

	printf("Recibi una conexión en %d!!\n", sock_CPU);

	//Recibo mensaje
	buffer = malloc(1000);
	int bytesRecibidos = recv(sock_CPU, buffer, 1000, 0);
	if(bytesRecibidos <= 0){
		printf("Se desconectó el cpu");
		return 1;
	}

	buffer[bytesRecibidos] = '\0';
	printf("Me llegaron %d bytes con  %s\n", bytesRecibidos, buffer);

	free(buffer);

	return 0;
}

