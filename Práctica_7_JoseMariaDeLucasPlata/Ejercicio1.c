#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
 *
 * 	Autor: Jose Maria De Lucas Plata.
 *              Marcos Escamilla Ojeda.
 */
//Funcion para preguntar cuántos numeros va a ordenar el usuario
void CantidadNumeros(int* total_numeros);

// Función para pedirle los números al usuario y guardarlos en un array
void PedirNumeros(int* numerosAordenar, int total_numeros);

// Función para ordenar los números de mayor a menor
void OrdenarNumeros(int* numerosAordenar, int total_numeros);

int main (){
	char volverAcomparar [2];//Variable para saber si el usuario quiere repetir
	int total_numeros;//Cantidad de numeros a ordenar
	printf("Bienvenido\n"); 
	int* numerosAordenar = NULL; // La inicializamos a NULL, para que luego en la condición dentro del do,
				     // si la variable no esta inicializada, que haga un malloc, y si esta 
				     // inicializada que haga un realloc.

	do{
		CantidadNumeros(&total_numeros); // Pasamos por referencia el total de números que vamos a ordenar.
		if (numerosAordenar == NULL){    // Al entrar al do por primera vez, numerosAordenar es == NULL, así que hara el malloc.
						 // Si se cumple la condición del while, al entrar en el do otra vez, numerosAordenar no sera
						 // igual a NULL, por lo que se hara el realloc.
			numerosAordenar = (int *) malloc (total_numeros * sizeof(int));
			if(numerosAordenar == NULL){
    		printf("ERROR, NO HAY MEMORIA\n");
    		return EXIT_FAILURE;
    		} //Si no hay espacio para hacer la reserva de la memória, entonces se cancelara.
		}else if (numerosAordenar != NULL){//Comprobamos si el realloc ha fallado
			numerosAordenar = (int*) realloc(numerosAordenar,(total_numeros * sizeof(int)));
		}

		PedirNumeros(numerosAordenar, total_numeros);//Pedimos los numeros al usuario
		OrdenarNumeros(numerosAordenar, total_numeros);//Los ordenamos de mayor a menor
		printf("¿Desea volver a comparar una serie de números?");
		scanf(" %[^\n]", volverAcomparar);
	}
	while (strcmp(volverAcomparar, "si") == 0);//Si contesta con si, repetimos el proceso


	free (numerosAordenar); // Liberamos memoria.
	return EXIT_SUCCESS;

}

//Funcion que pregunta al usuario cuantos numeros quiere ordenar
void CantidadNumeros(int* total_numeros){

	printf("¿Cuantos números desea ordenar?.\n");
	scanf(" %d", total_numeros);//los guardamos en la variable
	printf("El total de números es %d\n", *total_numeros);
}
//Funcion que pide al usuario que introduzca los numeros 1 por 1
void PedirNumeros(int* numerosAordenar, int total_numeros){
	int i = 0;
	printf("Introduzca la serie de números de uno en uno.\n");
	for (i = 0; i < total_numeros ; i++){
		scanf("%d", &numerosAordenar[i]);//Guardamos cada numero en el array
	}
}

//Funcion que ordena los numeros de mayor a menor
void OrdenarNumeros(int* numerosAordenar, int total_numeros){
	int i,j, box;
	for(i = 0; i < total_numeros ; i++){

			// Ordenamos de mayor a menor, de tal manera, que en la primera vuelta
			// de el segundo bucle, ya habremos sacado el numero mas grande, que lo guardaremos
			// en la primera posición, en la segunda vuelta empezaremos a comparar a poartir 
			// de la siguiente, por lo que ese nprimer número ya no lo tocaremos más,
			// y en las siguientes vueltas pasara lo mismo.
			

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
		printf(" %d\n",numerosAordenar[i]);//Imprimimos numeros ordenados ya
	}
	}
