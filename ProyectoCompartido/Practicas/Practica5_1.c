#include<stdio.h>
#include<stdlib.h>

int main(){
	/*
	 * Autor: Marcos Escamilla, Jose María de Lucas, Iulian Dragoi
	 * Asignatura: Programación
	 * Desarrollo de Aplicaciones Multiplataforma
	 * Practica 5_1
	 * */

	float promedio = 0, maxima, minima;
	int contador;
	float temp_semana[7];
	char Dias_semana[7][11] = {
		"Lunes",
		"Martes",
		"Miércoles",
		"Jueves",
		"Viernes",
		"Sábado",
		"Domingo"
	};

	// En Dias_semana[ponemos la cantidad de valores que guardara][ponemos
	// la longitud de caracteres que tendra cada valor]
	
	for(contador = 0; contador <= 6; contador++){

	//usamos un ciclo for para utilizar un contador, que nos permita 
	//cuardar el valor de cada dia de la semana en
	//cada posicion del array.
	//
		printf("Ingrese la temperatura promedio del dia %s\n", Dias_semana[contador]);
		scanf("%fl", &temp_semana[contador]);
		promedio += temp_semana[contador];
	}
	printf("El promedio de las temperaturas es: %2.f\n", promedio / contador);
	contador = 0;

	maxima = temp_semana[contador];
	int dia_maxima = 0;
	for(contador = 1; contador <= 6; contador++){
		if (maxima < temp_semana[contador]){
			maxima = temp_semana[contador];
			dia_maxima = contador;
		}
	}

	//Igualamos la Variable maxima a la temp_semana[contador], que en este
	//caso, contador es =0, asi que maxima = temp_semana[0].
	//
	//Luego creamos una variable dia_minima donde guardaremos el valor de 
	//contador.
	//
	//Creamos un bucle for para programar el contador.
	//
	//Creamos una condicion que compara la primera temperatura = maxima = 
	//temp_semana[0], con la segunda temperatura que guarda el array 
	//temp_semana[1], y si se cumple la condicion, maxima albergara el mayor
	//y lo comparara con el siguiente, al igual que si se da la condicion
	//dia_maxima albergara el valor de contador que tenga en ese momento,
	//que utilizaremos luego a la hora de imprimir en pantalla el dia de 
	//la semana relacionado con el valor de temperatura mas alto.
	
	contador = 0;
	minima = temp_semana[contador];
	int dia_minima = 0;
	for(contador = 1; contador <= 6; contador++){
		if (minima > temp_semana[contador]){
			minima = temp_semana[contador];
			dia_minima = contador;
		}
	}

	// Y con la temperatura minima hacemos lo mismo, que hemos hecho 
	// en la temperatura maxima, solo que modificamos al reves la condición.
	
	  printf("La temperatura máxima sera el dia %s con %.2f grados\n", Dias_semana[dia_maxima],  maxima);

	  // Aqui es donde llamamos al dia de la semana utilizando el array
	  // de Dias_semana[dia_maxima], donde dia_maxima alberga el valor 
	  // que tenia contador cuando se cumplio la condicion del
	  // if.

	  printf("La temperatura mínima es del dia %s con %.2f grados\n", Dias_semana[dia_minima], minima);
	  promedio = promedio/ contador;
	for(contador = 0; contador <= 6; contador++){
		if (temp_semana[contador] > promedio){
			dia_maxima = contador;
			printf("El día %s tiene una temperatura mayor a la media con una temperatura de %.2f grados\n", Dias_semana[dia_maxima], temp_semana[contador]);
	  // Para registrar los dias que tienen una temperatura mas alta que 
	  // la media, debemos de crear un bucle que iniciaremos a 0, y 
	  // una condicion en la que compararemos el promedio con cada uno de
	  // los valores de temp_semana, y si se cumple la condición, 
	  // imprimira el valor que sea mayor a el promedio y 
	  // dia_maxima volvera a guardar el valor de contador, para imprimir
	  // el dia de la semana.
	  
	 
		}
	}

	for(contador = 0; contador <= 6; contador++){
		if (temp_semana[contador] < promedio){
			dia_minima = contador;
			printf("El día %s tiene una temperatura menor a la media con una temperatura de %.2f grados\n", Dias_semana[dia_minima], temp_semana[contador]);
		}
	}
	//* Hacemos lo mismo para determinar que dias son los que tienen una temperatura inferior a la 
	//minima. lo unico que cambiando el signo de la condición y asignando el valor de contador a dia_minima.

	return EXIT_SUCCESS;
}

