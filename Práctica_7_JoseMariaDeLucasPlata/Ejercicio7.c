#include<stdio.h>
#include<stdlib.h>

/*
 *
 * 	Autor: Jose Maria De Lucas Plata.
 *
 */


int * EsPrimo(int*array, int num, int contador){
	int* arrayPrimos = (int*) malloc (contador * sizeof(int));
	if(arrayPrimos == NULL){
		printf("No hay memoria\n");
		exit(1);
	}
	arrayPrimos[0] = 2;

	for (int i = 1 ; i <= num; i++){
		if (i <= 1){
			continue;
		}
		for(int j = 2; j * j <= i; j++){
			if(i % j == 0){
				break;
			}else{
				contador++;
				int* temp = (int*) realloc(arrayPrimos, contador * sizeof(int));
				if(temp == NULL){
					printf("No hay memoria\n");
					exit(1);
				}
				int* arrayPrimos = temp;
				arrayPrimos[contador - 1] = i;
			}
		}

	}
	return arrayPrimos;

}

int main (){

	int num = 0;
	int contador = 1;
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
	for(int i = 0; i < num; i++){
		array[i] = i;
	}

	for(int i = 0; i < num; i++ ){
		printf("%d - ", array[i]);

	}

free(array);
	return 0;

}