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

	arrayPrimos[0] = 2;
	*contador = 1;

	for (int i = 3 ; i <= num; i++){
		int esPrimo = 1;

		for(int j = 2; j * j <= i; j++){
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
					exit(1);
				}
				arrayPrimos = temp;
				arrayPrimos[*contador - 1] = i;
		}
	}
	return arrayPrimos;

}