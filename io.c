#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include "fileutil.h"
//este programara se encargara de contar los bytes de un directorio 

int main(int argc, char **argv) {
    //el directorio sera usado como una estructura DIR
    DIR *directorio;
    //nos aseguramos que el usuario halla suministrado la direccion
    if (argc != 2) {

        printf("Has olvidado introducir la ruta del directorio.\n");
        return 1;
    }
    //abrimos el archivo suministrado por el usuario con opendir
    directorio = opendir(argv[1]);
    //si opendir retorno un NULL entonces se sabe que es imposible abrie el directorio
    if (directorio == NULL) {

        printf("No se puede abrir el directorio especificado.\n");
        return 1;
    }
    //definimos 4 variables necesarias para el uso del programa mas adelante
    int numeroArchivos = 0, tamanoTotal = 0, contador = 0;
    //se define un arreglo que almacenara los nombres de los archivos que se encuentren dentro del directorio
    //listar en una funcion definida dentro de la cabezera fileutil.h
    char **archivos = listar(directorio, &numeroArchivos);

    printf("Estudiante_1: 201523382.\n");
    printf("Estudiante_2: 201526750.\n");
    printf("Total archivos: %d.\n", nArchivos);

    // Calcular el tamaño en bytes de cada archivo encontrado.
    while (numeroArchivos--) {
        //bytes es una funcion que esta en la libreria fileutil.h
        tamanoTotal += bytes(archivos[contador]);
        contador++;
    }

    printf("Total bytes: %d.\n", tamanoTotal);

    return 0;
}