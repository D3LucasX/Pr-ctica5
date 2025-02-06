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
	char lista_palabras[40][20] = { //Declaramos un array de arrays de char con las palabras que queramos.
		"casa","arbol","perro","gato","auto","bicicleta","sol", "luna","estrella","montaña","rio","mar","tierra", "agua", "aire", "metal", "bosque", "flor", "lluvia", "trueno", "viento","tormenta","nieve","campo","ciudad", "puente", "edificio","escalera", "pintura","escultura"
	};
	for(int i = 0; i < 5; i++){  //Bucle para que recorra cada palabra.
		int con_e = 0;	//Variable que utilizaremos como confirmacion de que hay una letra 'e'.
		int con_g = 0; //Variable que utilizaremos como confirmación de que hay una letra 'g'.
		for(int j = 0; j < strlen(lista_palabras[i]); j++){  //Bucle interno para recorrer cadaa caracter de cada palabra.
			if(lista_palabras[i][j] == 'e'){  
				con_e != 1;  //Si la palabra contiene una e, con_e sera = a 1 y saldra del bucle interno.
				break; 
			}
		}

		for(int k = 0; k < strlen(lista_palabras[i]); k++){  //Bucle interno para recorrer cadaa caracter de cada palabra.
			if(lista_palabras[i][k] == 'g'){  
				con_g == 1;  //Si la palabra contiene una g, con_g sera = a 1 y saldra del bucle interno.
				break; 
			}
		}


		if(con_e == 1){	 // si la variable con_g es distinto a 1, continue, por lo que saltara esa palabra.
			continue;
		}
		printf(" %s\n", lista_palabras[i]);
	}
}


