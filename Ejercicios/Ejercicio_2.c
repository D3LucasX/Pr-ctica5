#include <stdio.h>
#include <stdlib.h>
#include<string.h>
/*
 * Autores: Marcos Escamilla Ojeda, Jose Maria De Lucas Plata, Iulian Dragoi.
 * Asignatura: Programación.
 * Desarrollo de Aplicaciones Multiplatforma.
 * Practica 5_Ejercicio_2
 */



int main(){
	char lista_palabras[5][20] = { //Declaramos un array de arrays de char con las palabras que queramos.
		"hola",
		"cuatro",
		"ocho",
		"adios",
		"coco"
	};
	for(int i = 0; i < 5; i++){  //Bucle para que recorra cada palabra.
		int con_a = 0;  //Variable que utilizaremos como confirmacion de que hay una a.
		for(int j = 0; j < strlen(lista_palabras[i]); j++){  //Bucle interno para recorrer cadaa caracter de cada palabra.
			if(lista_palabras[i][j] == 'a'){  
				con_a = 1;  //Si la palabra contiene una a, con_a sera = a 1 y saldra del bucle interno.
				break; 
			}
		}

		if(con_a == 1){	 // si la variable con_a es igual a 1, continue, por lo que saltara esa palabra.
			continue;
		}
		printf(" %s\n", lista_palabras[i]);
	}
}


