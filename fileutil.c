#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <sys/wait.h>
#include "fileutil.h"

int bytes(char *nombre){
	FILE *archivo;
	int contador = 0;
        //abrimos el archivo como un archivo en formato binario de lectura
	archivo = fopen(nombre, "r");
        //mientras no se llegue al final del archivo EOF(en of file) se le sumara 1 al contador dando como resultado el tamaño del archivo
  	while(fgetc(archivo) != EOF){
  		contador++;
  	}
        //retornamos el numero de bytes
  	return contador;
}

char **listar(char *ruta, int *numeroArchivos) {
    DIR *directorio;
    //abrimos el directorio
    directorio=opendir(ruta);
    //arreglo encarfado de alamacenar dentro de cada posicion un archivo que este denrto del directorio
    char **arreglo = (char **) malloc(sizeof (char *));
    //tamaño de la ruta
    int tamano=sizeof(ruta)+1;
    // Comprobamos que se pudo abrir el directorio.
    if (dir == NULL){
        printf("No se puede abrir el directorio especificado.\n");
	return arreglo;
	}
    //contador que servira como ayuda para contar la cantidad de archivos que se encuentren dentro de el archivo
    int contador = 0;
    struct dirent *entrada;
    //se leen todos los archivos 
    while((entrada = readdir(dir)) != NULL){
  		if(entrada->d_type != DT_DIR){
			//redimencionamos el arreglo y le asignamos un nuevo tamaño en memoria para alamcenar el nombre del archivo
  			arreglo = (char **)realloc(arreglo, (sizeof(char *) * (contador + 1)));
            arreglo[contador] = (char *)malloc((sizeof(entrada->d_name) * sizeof(char)) + tamanoRuta);
			//guardamos el nombre del archivo
			strcpy(arreglo[contador], ruta);
			strcat(arreglo[contador], "/");
			strcat(arreglo[contador], entrada->d_name);
			contador++;		
    	}
	}	
    
    // Cerramos el directorio.
	closedir (dir);
    
	// Guardamos la cantidad de archivos encontrados.
    *numeroArchivos = contador;
    
    return arreglo;
}
