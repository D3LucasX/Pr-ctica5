#include<stdio.h>
#include<stdlib.h>

/*
 *
 * 	Autor: Jose Maria De Lucas Plata.
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

	if (array == NULL)
	{
		printf("Error al asignar memoria.\n");
		return 1;
	}
	printf("Lista de números proporcionados por el usuario.\n");
	for(int i = 0; i < num; i++){
		array[i] = i;
	}

	for(int i = 0; i < num; i++ ){
		printf("%d - ", array[i]);

	}
	printf("\n");
	
	printf("Este es el array de números primos.\n");
	int * arrayPrimos = EsPrimo(num, &contador);

	for (int i = 0; i < contador; i++){
		printf("%d - ", arrayPrimos[i]);
	}
	printf("\n");


free(array);
free(arrayPrimos);
	return 0;

}

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
		// Comprobamos si es primo con 
			if(i % j == 0){
				esPrimo = 0;
				break;
			}
		}
		if(esPrimo){
				(*contador)++;
				int* temp = (int*) realloc(arrayPrimos, *contador * sizeof(int));
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