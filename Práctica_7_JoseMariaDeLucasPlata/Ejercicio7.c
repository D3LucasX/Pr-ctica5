#include<stdio.h>
#include<stdlib.h>

/*
 *
 * 	Autores: Jose Maria De Lucas Plata,
 			  Marcos Escamilla Ojeda.
 *
 */


int * EsPrimo(int num, int* contador);

int main (){

	int num = 0;
	int contador = 0;

	while (num <= 1){
		printf("Dame un número mayor que 1 \n");
		scanf("%d", &num);
	}

	int* array = (int*) malloc (num * sizeof(int));
	// Reserva de memoria para el Array con los valores que ha indicado el Usuario.

	if (array == NULL){
		printf("Error al asignar memoria.\n");
		return 1;
	}
	printf("Lista de números proporcionados por el usuario.\n");
	for(int i = 0; i < num; i++){
	// Inicializamos 
		array[i] = i;
	}

	for(int i = 0; i < num; i++ ){
		printf("%d", array[i]);
		if (i < num - 1){
			printf(" - ");
		}
	}
	printf("\n");
	
	printf("Este es el array de números primos.\n");
	int * arrayPrimos = EsPrimo(num, &contador);
	// Inicializamos El array con los números primos.

	for (int i = 0; i < contador; i++){
		printf("%d", arrayPrimos[i]);
		if (i < contador - 1){
			printf(" - ");
		}
	}
	printf("\n");

// Liberamos memoria,.
free(array);
free(arrayPrimos);
	return 0;

}
// Función para saber que números de la lista son primos y guardarlos en otro array.
int * EsPrimo(int num, int* contador){
	int* arrayPrimos = (int*) malloc (sizeof(int));
	// Reservamos memoria para un int.

	arrayPrimos[0] = 2;
	// Inicializamos la primera posición del array con 2,
	// que es el primer número primo.
	*contador = 1;
	// Inicializamos el contenido de contador a 1.

	for (int i = 3 ; i <= num; i++){
	// Bucle for que recorre los números desde el principio hasta
	// el número que nos indicó el usuario.
		int esPrimo = 1; 
		// Variable bandera, si es uno es verdadero, si es 0 es falso.
		// Partimos de la base de que es verdadero.

		for(int j = 2; j * j <= i; j++){
		// Comprobamos si es primo, si no lo es, sale del bucle 
		// y la variable esPrimo pasaría a valer 0.
			if(i % j == 0){
				esPrimo = 0;
				break;
			}
		}
		if(esPrimo){
		// Esto quiere decir que si la variable esPrimo es algo positivo que no sea
		// 0, hara esto, si no, vuelve al primer bucle for.
				(*contador)++;
				// Incremento la variable contador, necesario para hacer el realloc,
				// lo usaremos como tamaño del realoc.
				int* temp = (int*) realloc(arrayPrimos, *contador * sizeof(int));
				// Hacemos el realloc para redimensionar el array, añadiendole una posicion para añadir el nuevo
				// número. Lo hacemos con otro nombre, porque si no hay memoria, no perderemos la dirección de memoria
				// de arrayPrimos ya que si al hacer el realloc, no encuentra espacio, devolvería NULL,
				// entonces no podríamos hacer el free.
				if(temp == NULL){
					printf("No hay memoria\n");
					free(arrayPrimos);
					exit(1);
				}
				arrayPrimos = temp;
				arrayPrimos[*contador - 1] = i;
		}
	}
	return arrayPrimos;

}