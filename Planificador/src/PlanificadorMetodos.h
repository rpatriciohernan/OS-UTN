/*
 * PlanificadorMetodos.h
 *
 *  Created on: 5/9/2015
 *      Author: utnso
 */

#ifndef PLANIFICADORMETODOS_H_
#define PLANIFICADORMETODOS_H_

//---------------Librerias-------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>
#include <commons/collections/list.h>

#define PACKAGESIZE 1024

//---------------VariablesGlobales----------------
t_list* listaDeSocketsConectados;


//------------------Encabezados----------------------

int escucharCpus();
int	manejoHiloCPU(void* cliente);

#endif /* PLANIFICADORMETODOS_H_ */
