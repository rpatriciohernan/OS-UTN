/*
 * swap_metodos.c
 *
 *  Created on: 5/9/2015
 *      Author: utnso
 */
#include "swap_metodos.h"


int escucharConexionAdminMemoria()	{

	//genero dirección
	struct sockaddr_in direccionServidor;
	direccionServidor.sin_family = AF_INET;
	direccionServidor.sin_addr.s_addr = INADDR_ANY;

	direccionServidor.sin_port = htons(8200);



	//genero socket
	int servidor = socket(AF_INET, SOCK_STREAM, 0);

	int activado = 1;
	setsockopt(servidor, SOL_SOCKET, SO_REUSEADDR, &activado, sizeof(activado));

	//asocio socket con la dirección antes configurada
	if(bind(servidor, (void*) &direccionServidor, sizeof(direccionServidor)) != 0){
		perror("Fallo el bind");
		return 1;
	}

	printf("Estoy escuchando\n");
	//pongo a escuchar el socket y le pongo el número máximo de conexiones a aceptar
	listen(servidor, 100);


	struct sockaddr_in direccionCliente;			// Esta estructura contendra los datos de la conexion del cliente. IP, puerto, etc.
	socklen_t tamanioDireccion = sizeof(direccionCliente);
	int socl_AdmMem= accept(servidor, (struct sockaddr *) &direccionCliente, &tamanioDireccion);

	printf("Recibi una conexión en %d!!\n", socl_AdmMem);

	//Recibo mensaje
	buffer = malloc(1000);

	while(1){
		int bytesRecibidos = recv(socl_AdmMem, buffer, 1000, 0);
		if(bytesRecibidos <= 0){
			printf("Se desconectó el cliente!");
			return 1;
		}

		buffer[bytesRecibidos] = '\0';
		printf("Me llegaron %d bytes con %s\n", bytesRecibidos, buffer);

	}

	free(buffer);

	return 0;

}

