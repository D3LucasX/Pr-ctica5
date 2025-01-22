#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
 *
 * 	Autor: Jose Maria De Lucas Plata.
 *
 */
void CantidadNumeros(int* total_numeros);
void PedirNumeros(int* numerosAordenar, int total_numeros);
void OrdenarNumeros(int* numerosAordenar, int total_numeros);

int main (){
	char volverAcomparar [2];
	int total_numeros;
	printf("Bienvenido\n"); 
	int* numerosAordenar = NULL; // La inicializamos a NULL, para que luego en la condición dentro del do,
								 // si la variable no esta inicializada, que haga un malloc, y si esta 
								 // inicializada que haga un realloc.

	do{
		CantidadNumeros(&total_numeros);
		if (numerosAordenar == NULL){
			numerosAordenar = (int *) malloc (total_numeros * sizeof(int));
			if(numerosAordenar == NULL){
    		printf("ERROR, NO HAY MEMORIA\n");
    		return EXIT_FAILURE;
    		} //Si no hay espacio para hacer la reserva de la memória, entonces se cancelara.
		}else if (numerosAordenar != NULL){
			numerosAordenar = (int*) realloc(numerosAordenar,(total_numeros * sizeof(int)));
		}
		PedirNumeros(numerosAordenar, total_numeros);
		OrdenarNumeros(numerosAordenar, total_numeros);
		printf("¿Desea volver a comparar una serie de números?");
		scanf(" %[^\n]", volverAcomparar);
	}
	while (strcmp(volverAcomparar, "si") == 0);


	free (numerosAordenar);
	return EXIT_SUCCESS;

}

void CantidadNumeros(int* total_numeros){


	printf("¿Cuantos números desea ordenar?.\n");
	scanf(" %d", total_numeros);
	printf("El total de números es %d\n", *total_numeros);
}
void PedirNumeros(int* numerosAordenar, int total_numeros){
	int i = 0;
	printf("Introduzca la serie de números de uno en uno.\n");
	for (i = 0; i < total_numeros ; i++){
		scanf("%d", &numerosAordenar[i]);
	}
}
void OrdenarNumeros(int* numerosAordenar, int total_numeros){
	int i,j, box;
	for(i = 0; i < total_numeros ; i++){
		
			for(j = i + 1; j < total_numeros ; j++){
				if (numerosAordenar[i] < numerosAordenar[j]){
					box = numerosAordenar[i];
					numerosAordenar[i] = numerosAordenar[j];
					numerosAordenar[j] = box;
				}
			}
			//printf("%dº - %d , ", i +1, numerosAordenar[i]);
		}	
		for (i = 0 ; i < total_numeros; i++){
		printf(" %d\n",numerosAordenar[i]);
	}
	}
