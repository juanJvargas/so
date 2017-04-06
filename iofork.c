#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <sys/wait.h>
#include "fileutil.h"
//funcion io fork que busca el tama�o total de todos los archivos dentro de un directrio suministrado por el usuario usando dos procesos
int main(int argc, char **argv){
  	//nos aseguramos que el usuario halla suministrado la direccion
  	if(argc != 2){
  		
    	printf("Has olvidado introducir la ruta del directorio.\n");
    	return 1;
    }
	//definimos 4 variables necesarias para el uso del programa mas adelante
    int numeroArchivos = 0, tamanoTotal = 0, contador = 0, mitad = 0;
    //se define un arreglo que almacenara los nombres de los archivos que se encuentren dentro del directorio
    //listar en una funcion definida dentro de la cabezera fileutil.h
	char **archivos = listar(directorio, &numeroArchivos);
	//hallamos la mitad de el arreglo archivos
	mitad = ((numeroArchivos / 2.0) + 1);
	//definimos un canal de comunicacion
	int canal[2];
	//definimos un pid que sirve de identificacion para el proceso hijo
	int pid = 0;
	pipe(canal);
	//si el proceso que se esta ejecutando es el padre
	printf("Estudiante_1: 201523382.\n");
	printf("Estudiante_2: 201526750	.\n");
	printf("Total archivos: %d.\n", numeroArchivos);
	if((pid = fork())){
		//variable que almacena el valor total de los bytes contado por el proceso hijo
		int tamanoHijo = 0;
		close(canal[1]);
		//alamcenamos los bytes encontrados 
		while(mitad--){
			
			tamanoTotal += bytes(archivos[contador]);
			contador++;
		}
		//espera por lso bytes que halla el hijo
		read(canal[0], &tamanoHijo, sizeof(tamanoHijo));
		printf("Total bytes: %d.\n", (tamanoTotal + tamanoHijo));
	}
	
	else {
		close(canal[0]);
		contador = mitad;
		mitad = (numeroArchivos - mitad);
		//sumamos el tama�o total de bytes en los archivos
		while(mitad--){

			tamanoTotal += bytes(archivos[contador]);
			contador++;
		}
		write(canal[1], &tamanoTotal, sizeof(tamanoTotal));	
	}
  	
  	return 0;
}
