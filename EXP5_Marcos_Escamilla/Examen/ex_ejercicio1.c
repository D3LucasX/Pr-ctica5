#include<stdio.h>
#include<stdlib.h>
/*
 * Autores: Marcos Escamilla Ojeda, Jose Maria De Lucas Plata, Iulian Dragoi.
 * Asignatura: Programación.
 * Desarrollo de Aplicaciones Multiplataforma.
 * Practica 5_Ejercicio_1.
 */



int main(){

	int inventario[2][3][4][5][10]={0};
	int imprimir_mas;


	inventario[0][0][0][0][0] = 50;

	inventario[1][1][1][3][2] = 120;

	inventario[0][2][3][4][3] = 300; 

	inventario[1][0][3][4][4] = 100;

	inventario[0][1][0][4][5] = 250;

	//Añadimos las 200 unidades
	inventario[1][1][1][0][9]=200;
	//Y ahora lo imprimimos por pantalla
	printf("Inventario en europa, sede 1, categoría televisores, modelo 0, lote 9 : %d unidades\n", inventario[1][1][1][0][9]); 
	printf("Cuantas unidades quiere incrementar?\n");//Preguntamos cuanto más quiere incrementar
	scanf(" %d",&imprimir_mas);
	imprimir_mas += inventario[1][1][1][0][9]; //Sumamos la cantidad que ingresa el usuario
	printf("Inventario en europa, sede 1, categoria televisores, modelo 0, lote 9: %d unidades\n", imprimir_mas);	//Imprimimos la nueva cantidad
	printf("Inventario en america, sede 0, categoria televisores, modelo 0, lote 0: %d unidades\n", inventario[0][0][0][0][0]);
	printf("Inventario en europa, sede 1, categaria telefonos, modelo 3, lote 2: %d unidades\n", inventario[1][1][1][3][2]);
	printf("Inventario en america, sede 2, categoria ordenadores, modelo 4, lote 3: %d unidades\n", inventario[0][2][3][4][3]);
	printf("Inventario en europa, sede 0, categoria ordenadores, modelo 4, lote 4: %d unidades\n", inventario[1][0][3][4][4]);
	printf("Inventario en america, sede 1, categoria televisores, modelo 4, lote 5: %d unidades\n", inventario[0][1][0][4][5]);

	return 0;

}

