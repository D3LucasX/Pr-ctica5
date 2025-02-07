#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
 *
 * 	Autores: Jose Maria De Lucas Plata,
 			 Marcos Escamilla Ojeda.
 *
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

	for (int i = 0; i < longitudCadena; i++){
		if(cadena[i] >= 65 && cadena[i] <= 90 && (cadena[i] + clave) > 90 && (cadena[i] + clave) < 65){
			cadena[i] += clave;
			cadena[i] -= 26;
		}else if (cadena[i] >= 65 && cadena[i] <= 90 )
			cadena[i] += clave;

		if (cadena[i] >= 97 && cadena [i] <= 122 && (cadena[i] + clave) > 122 && (cadena[i] + clave) < 97){
			cadena[i] += clave;
			cadena[i] -= 26;
		}else if (cadena[i] >= 97 && cadena [i] <= 122){
			cadena[i] += clave;
		}
	}

	printf("La cadena codificada es : %s\n", cadena);

	return EXIT_SUCCESS;

}
