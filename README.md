TORRES CAÑON JUAN DAVID 201526750
VARGAS VARGAS JUAN JOSE 201523382

En total se manejaran 4 archivos io.c, ioforck.c, fileutil.h y fileutil.c:

	fileutil.h: Sera una libreria que se encarga de alamacenar dentro de ella dos funciones que seran usadas por io.c 
	e iofork.c donde cada una sera "bytes" y "listar" donde:
	
		bytes: bytes es un metodo que con base a un nombre de un archivo se encargara de calcular el tamaño del archivo 
		
		listar: listar es otro metodo que recive un arreglo, al cual se procedera a añadirle todods los archivos que 
		se encuentren dentro de un directorio suministrado por el usuario
		
	fileutil.c: Este archivo contendra la implementacion de los metodos bytes y listar que estan definidos dentro de
	fileutil.h
	
	io.c: Este archivo contiene la implementacion de un programa se encarga de sacar en el tamaño de todos los elementos
	dentro de un directorio proporcionado por el usuarario. Para esta implementacion se usa a listar de fileutil.h para
	obtener el arreglo con los archivosy proceder a sacar el tamaño de cada archivo en als posiciones del arreglo usando la
	funcion bytes de fileutil.h
	
	iofork.c: Este archivo contiene un codigo de la implementacion del codigo de io.c pero esta ves usando la funcion fork 
	para creardos procesos padre e hijo que se encargan cada uno se sacar el tamaño de los bytes de los archivos que estan 
	alamacenados en un segmento del arreglo que retorna listar.el proceso hijo se encarga de hallar y comunicar al padre la 
	cantidad de bytes que hay dentro de la primera mitad del arreglo mientras que padre calcula la otra mitad y espera a 
	que hijo le envie la informacion necesaria para obtener el tamaño total de los elementos en el arreglo.
