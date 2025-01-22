#include<stdio.h>
#include<stdlib.h>

/*
 *
 * 	Autor: Jose Maria De Lucas Plata.
 *
 */
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
		}elseif (numerosAordenar != null){

		}
		PedirNumeros(numerosAordenar, total_numeros);
		printf("¿Desea volver a comparar una serie de números?");
		scanf(" %[^\n]" volverAcomparar);
	}
	while (strcmp(volverAcomparar, "si") == 0){
    }



	return EXIT_SUCCESS;

}

void CantidadNumeros(int* total_numeros){


	printf("¿Cuantos números desea ordenar?.\n");
	scanf("%d", total_numeros);
	printf("%d", *total_numeros);
}
void PedirNumeros(int* numerosAordenar, int tamaño){
	printf("Introduzca la serie de números\n.");
	for (i = 0; i < total_numeros ; i++);
		scanf("%d", numerosAordenar[i]);
}
void OrdenarNumeros(int* numerosAordenar, int total_numeros){
	int i,j, temporal;
	for(i = 0; i < total_numeros ; i++){
		temporal = numerosAordenar[i];
			for(j = 1; j < total_numeros ; j++){
				if (temporal > numerosAordenar[j]){
					temporal = numerosAordenar[j];
					printf("%d es menor que %d.\n", temporal, numerosAordenar[j]);
				}
			}
			printf("%dº - %d", i, temporal);
		}	
	}

	/* To do:
		-Hacer el realloc.
		-ordenar el dowhile
		-Probar
