#include "fileutil.c"
//libreria fileutil que tendra dentro de ella dos metodos esenciales para la realizacion de los programas io e iofork
//bytes es una funcion que retorna el numero de bytes de un archivo
int bytes(char *nombre);
//listar ers una funcion que retorna un arreglo con los archivos que esten dentro de un directorio
char **listar(DIR *directorio, int *nArchivos);