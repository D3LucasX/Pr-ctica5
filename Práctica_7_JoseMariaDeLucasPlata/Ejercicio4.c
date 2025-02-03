#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h> // Necesaria para poder comparar dos caracteres
                   // dando igual si son mayúsculas o minúsculas.
/*
 *
 * 	Autor: Jose Maria De Lucas Plata.
 *	        Marcos Escamilla Ojeda.
 */
void esPalindromo(char* cadena, int tamaño){
    tamaño = tamaño - 1; // quitamos el \0.

    if (tamaño <= 1){  // Caso base. Cuando el tamaño, sea < que uno o igual a uno, saldra,
                       // porque eso indicara o que la palabra que queda ya no tiene con quien
                       // compararse, o que ya no hay mas palabras y por lo tanto todas las 
                       // comparaciones han sido validas.
        
        printf("Es un palíndromo\n"); 
        return;
    }

    if (tolower(cadena[0]) == tolower(cadena[tamaño])){ // tolower a la hora de comparar dos caracteres
							// no hace distincion entre si está en mayúsculas o 
							// minúsculas.

        esPalindromo(cadena +1, tamaño-1); // Acotamos el rango de comparacion en la nueva llamada 
					   // recursiva a la función.

    }else{
        
        printf("No es u palíndromo.\n"); 
    }
}

int main (){
char cadena[50];
printf("Introduzca una palabra para identificar si es un palíndromo.\n");
scanf("%s", cadena);
int tamaño = strlen(cadena);
esPalindromo(cadena, tamaño);



	return EXIT_SUCCESS;

}
