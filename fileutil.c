#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>

int bytes(char *nombre){
	FILE *archivo;
	int contador = 0;
        //abrimos el archivo como un archivo en formato binario de lectura
	archivo = fopen(nombre, "rb");
        //mientras no se llegue al final del archivo EOF(en of file) se le sumara 1 al contador dando como resultado el tamaño del archivo
  	while(fgetc(archivo) != EOF){
  		contador++;
  	}
        //cerramos el archivo
  	fclose(archivo);
        //retornamos el numero de bytes
  	return contador;
}

char **listar(DIR *directorio, int *nArchivos) {
    //arreglo encarfado de alamacenar dentro de cada posicion un archivo que este denrto del directorio
    char **arreglo = (char **) malloc(sizeof (char *));
    //contador que servira como ayuda para contar la cantidad de archivos que se encuentren dentro de el archivo
    int contador = 0;
    struct dirent *entrada;
    while ((entrada = readdir(directorio)) != NULL) {
        if ((strcmp(entrada->d_name, ".") != 0) && (strcmp(entrada->d_name, "..") != 0)) {
            FILE *archivo;
            //abrimos el archivo en formato de lectura
            archivo = fopen(entrada->d_name, "r");
            //si es un archivo entonces arreglo se posicionara en otra posicion de memoria con el objetivo de almacenar el nuevo arreglo
            //luego se almacenara dentro de arreglo y por ultimo se aumenta contador con el objetivo de llevar la cuenta de cuantos archivos se anleido
            if (archivo) {
                arreglo = (char **) realloc(arreglo, (sizeof (char *) * (contador + 1)));
                arreglo[contador] = (char *) malloc(sizeof (entrada->d_name) * sizeof (char));
                strcpy(arreglo[contador], entrada->d_name);
                contador++;
            }
            //se cierra el archivo
            fclose(archivo);
        }
    }
    //cerramos el directorio
    closedir(directorio);
    //almacenamos el nuemro de archivos leidos dentro de *nArchivos
   *nArchivos = contador;
   //retornamos el arreglo
    return arreglo;
}