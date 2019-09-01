/*
 * metodosCpu.h
 *
 *  Created on: 5/9/2015
 *      Author: utnso
 */

#ifndef METODOSCPU_H_
#define METODOSCPU_H_

// ------------- BIBLIOTECAS ----------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <sys/socket.h>

//--------------Variables----------
int cantidadDeHilosCPU;
int puertoAdminMemoria;
int puertoPlanificador;
char* ipAdminMemoria;
char* buffer;

// ------------------ FUNCIONES y METODOS --------------

void* manejoHiloCPU();
/*int conectarPlanificador();
int conectarAdminMemoria(); */


#endif /* METODOSCPU_H_ */
