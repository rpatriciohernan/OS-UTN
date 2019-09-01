/*
 * LaMemoriaMetodos.h
 *
 *  Created on: 5/9/2015
 *      Author: utnso
 */

#ifndef LAMEMORIAMETODOS_H_
#define LAMEMORIAMETODOS_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>


// ------------------ FUNCIONES y METODOS --------------
int puertoAdminSwap;
char* ipAdminSwap;
char* buffer;

int conectarseASWAP ();
int escucharCPU ();


#endif /* LAMEMORIAMETODOS_H_ */
