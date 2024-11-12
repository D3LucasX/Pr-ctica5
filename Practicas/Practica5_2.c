#include<stdio.h>
#include<stdlib.h>
#define NOTA_MINIMA 5.00
/*
 * Autores: Marcos Escamilla, Jose Maria de Lucas , Iulian Dragoi
 * Asignatura: Programación
 * Desarrollo de Aplicaciones Multipilataforma
 * Practica 5_2
 * */
struct Estudiante{
	char nombre[50];	//*Declaro un struct con los valores que quiero que guarde de cada estudiante
	float nota_final;
};
int main(){
	int num_alumnos, i, aprobados = 0, suspensos = 0, posicion_nota_maxima = 0, posicion_nota_minima = 0;
	float promedio = 0, nota_maxima = 0, nota_minima = 0;

	printf("Ingresa la cantidad de alumnos; \n");	//Pido la cantidad de alumnos que tendra la clase/grupo.	
	scanf("%d", &num_alumnos);

	if (num_alumnos <= 0){
		printf("Valor introducido no válido."); //Me cercioro de que introduzca siempre valores positivos.
		return 1;
	}
	struct Estudiante alumnos [num_alumnos];	//Inicializo el struct, de tipo estudiante, que guardara alumnos con argumento del numero/cantidad de alumnos.
	for(i = 0; i < num_alumnos; i++ ){	
		printf("Alumno %d\n",i + 1);	//Hago un print de la posición derl alumno, que como siempre la primera posición sera la 0, en los argumentos del print, le sumo 1 para que 
						//en el print salga que el primer alumno es el 1 y no el 0.

		printf("Nombre: ");			//Pido que introduzca el nombre, y lo guardo en el struct de tipo estudiante, que se llama alumnos, en la variable nombre.
		scanf(" %[^\n]", alumnos[i].nombre);	// %[^\n] sirve para poder introducir cualquier nombre o texto con espacios.
		
		printf("Nota Final: ");		//Aqui pido que introduzca la nota final que la guardaremos en el struct de tipo Estudiante, que se llama alumno, que guardara el valor en la variable nota_final
		scanf("%f", &alumnos[i].nota_final);	//Acuerdate del &

		promedio += alumnos[i].nota_final;	//sumamos todas las notas finales sumando el valor de promedio con el valor de la nota final del alumno, 
							//y el resultado lo guardamos en la variable pro0medio.
	}
		promedio /= num_alumnos;	//Aquí calculamos el promedio de las notass de los alumnos dividiendo el valor de promedio entre el numero de alumnos,
						//y guardaremos el resultado en la variable promedio. 
		printf("La nota promedio de los alumnos del grupo es: %.2f\n", promedio);

	for(i = 0; i < num_alumnos; i++ ){
		if(alumnos[i].nota_final >= NOTA_MINIMA){ 	//Creamos otro bucle con un contador en la que iniciaremos una condición en la que si la nota final del alumno de la posicion 'i' es
								//mayor o igual a la NOTA_MINIMA, que es un #Dejine que creamos al inicio, con un valor constante para todo el programa, y si se cumple
								//la condicion, la variable aprobados que esta iniciada en 0, va incrementando en 1.
			aprobados++;
	}else{
			suspensos++;		//Por lo contrario si no se cumple la condición, indica que el alumno no ha aprobado, entonces la variable suspensos, que esta iniciada en 0, aumentara en 1.
	}
}

			printf("EL número total de aprobados es: %d\n", aprobados);
			printf("EL número total de suspensos es: %d\n", suspensos);
	nota_maxima = alumnos[0].nota_final;	//para comparar las notas, creamos una variable nota_maxima, a la que le asignaremos el valor que tiene la nota final del alumno en la posicion 0.
	nota_minima = alumnos[0].nota_final;	//Para comparar la nota minima hacemos lo mismo
	for(i = 1; i < num_alumnos; i++){	//Creaqmos otro bucle en el que creamos otro contador para que vayamos recorriendo todos los alumnos.
		if (alumnos[i].nota_final > nota_maxima){	//aqui creamos dentro del bucle una condicion en la que comparamos el alumno en la posicion 1, con la nota_maxima que guarda el valor
								// del alumno en la posicion 0, y la que sea mayor, la guardara en nota_maxima.
			nota_maxima = alumnos[i].nota_final;
			posicion_nota_maxima = i;		//La posicion siempre sera igual que la i, ya que al comparar el alumno posicion i, i tendra el valor del número de la vuelta, si esta en la 
								//vuelta 3, comparando el tercer alumno, i sera = 3.
		}
		if (alumnos[i].nota_final <  nota_minima){	
			nota_minima = alumnos[i].nota_final;
			posicion_nota_minima = i;
		}
	}

		printf("La nota mas alta es %.2f. (Estudiante en la posicion %d)\n",nota_maxima, posicion_nota_maxima + 1 );
		printf("La nota mas baja es %.2f.(Esudiante en la posicion %d)\n", nota_minima, posicion_nota_minima + 1);
		printf("Notas por encima del promedio:\n");
	for(i = 0; i < num_alumnos; i++){	//aqui comparamos que la nota de los alumnos sea mayor que la del promedio, y si es asi, que lo imprima.
		if (alumnos[i].nota_final > promedio){
			printf("Estudiante en la posicion %d: %.2f\n", i + 1, alumnos[i].nota_final);
		}
	}	
return 0; 
}
