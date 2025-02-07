#include<stdio.h>
#include<stdlib.h>

/*
 *
 * 	Autores: Jose Maria De Lucas Plata.
 *     	     Marcos Escamilla Ojeda.
 */
int main (){

	int n = 3; //filas
	int m = 3; // columnas
	int arr[n][m];
	int suma = 0;
	int temp = 0;
	int aumento = 2;

	//Rellenar los numeros de la matriz.
	for (int i = 0; i < n  ; i++){
		for (int j = 0; j < m  ; j++){
			arr[i][j] = aumento;
			aumento ++;
			printf("%d", arr[i][j]);
		}
		printf("\n");
	}

	//Sumar los numeros del contorno.
	for (int i = 0; i < n  ; i++){
		for (int j = 0; j < m  ; j++){
			if (i == 0 || i == n -1 || j == 0 || j == m -1){
				suma += arr[i][j];
			}else{
				continue;
			}
		}
	}
			printf("El resultado obtenido de la suma de los números del contorno es: %d\n", suma );


	return EXIT_SUCCESS;

}
