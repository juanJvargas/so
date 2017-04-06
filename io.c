#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <sys/wait.h>
#include "fileutil.h"   
//este programara se encargara de contar los bytes de un directorio 

int main(int argc, char **argv) {
    //nos aseguramos que el usuario halla suministrado la direccion
    if (argc != 2) {

        printf("Has olvidado introducir la ruta del directorio.\n");
        return 1;
    }
    //definimos 4 variables necesarias para el uso del programa mas adelante
    int numeroArchivos = 0, tamanoTotal = 0, contador = 0;
    //se define un arreglo que almacenara los nombres de los archivos que se encuentren dentro del directorio
    //listar en una funcion definida dentro de la cabezera fileutil.h
    char **archivos = listar(argv[1], &numeroArchivos);

    printf("Estudiante_1: 201523382.\n");
    printf("Estudiante_2: 201526750.\n");
    printf("Total archivos: %d.\n", numeroArchivos);

    // Calcular el tamaño en bytes de cada archivo encontrado.
    while (numeroArchivos--) {
        //bytes es una funcion que esta en la libreria fileutil.h
        tamanoTotal += bytes(archivos[contador]);
        contador++;
    }

    printf("Total bytes: %d.\n", tamanoTotal);

    return 0;
}
