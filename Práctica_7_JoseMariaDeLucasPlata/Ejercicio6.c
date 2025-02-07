#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
 *
 * 	Autor: Jose Maria De Lucas Plata.
 *     	        Marcos Escamilla Ojeda.
 */
int main (){
	int clave;
	char cadena[50];

	printf("Escribe la cadena:\n");
	scanf(" %[^\n]", cadena);
	printf("¿Cual va a ser tu clave?\n");
	scanf(" %d", &clave);
	int longitudCadena = strlen(cadena);
	clave = clave % 26;
	// Con esto nos aseguramos de que cualquier clave, incluso números muy grandes, reduzcan su valor en un rango de 0 - 25, ya que el alfabeto al tener 26 letras, por ejemplo, si nos desplazamos 27 veces, seria igual que 26 (estaríamos en la misma letra) + 1, osea que desplazandonos una vez, nuestro caracter acabaría en la misma posicion que si lo hacemos 27 veces.

	for (int i = 0; i < longitudCadena; i++){
		if(cadena[i] >= 65 && cadena[i] <= 90 ){
		// Si el caracter es mayúscula
			cadena[i] += clave;
			// se le suma lo qu ecointenga clave
			if (cadena[i] > 90 ){
			// Con esto, si el valor del caracter se pasa de 90 al sumarle el incremento, le restamos 26, que es como si las casillas que hubiera avanzado, lo hubiera hecho desde la 'A' otra vez.
				cadena[i] -= 26;
			}else if(cadena[i] < 65){
			// En caso de la clave ser negativa, si llega a la si el valor del caracter fuera inferior a 65, que es menos que la 'A', se le sumarian 26, que seria como si hubiera vuelto a la 'Z' y hubiera seguido avanzando.
				cadena[i] +=26;
			}
		}

		if (cadena[i] >= 97 && cadena [i] <= 122){
			// Si el caracter es miúscula(igual que la mayúscula)
			cadena[i] += clave;
			if (cadena[i] > 122){
			cadena[i] -= 26;
			}else if(cadena[i] < 97){
			cadena[i] += 26;
			}
		}
	}

	printf("La cadena codificada es : %s\n", cadena);

	return EXIT_SUCCESS;

}
