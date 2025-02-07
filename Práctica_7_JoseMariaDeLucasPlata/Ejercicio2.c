#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Autores: Jose María de Lucas Plata
            Marcos Escamilla Ojeda*/


//Struct para guardar informacion de cada estudiante
typedef struct 
{

	char nombre [100];//Con su nombre
	char apellido [100];//Apellido
	float nota;//Y su nota


}Estudiante;


//Función para introducir el número de estudiantes que quieres agregar
void EstudiantesIntroducir(int *total_est){ //total_est lo tengo que pasar por referencia, lo que me permite modificar directamente en el main

printf("¿Cuántos estudiantes quieres introducir?\n");
scanf("%d", total_est);//Leemos el numero de estudiantes
printf("El total de estudiantes es %d\n", *total_est);//Y los mostramos

}
// Función para comparar los apellidos de dos estudiantes
// Necesaria para usar qsort, que requiere una función de comparación
//Es la estructura para usar el qsort
int CompararApellido (const void *a,const void *b){//Para utilizar el qsort...Se convierte cada uno de estos punteros genéricos al tipo Estudiante *. Usamos el -> para acceder al campo apellido
       //Comparamos los apellidos del estudiante a con el del estudiante b 
       return strcmp(((Estudiante *)a)->apellido, ((Estudiante *)b)-> apellido);
       //Obtiene la cadena que contiene el apellido del estudiante al que apunta a, e igual para b.
       //El return de strcmp su valor es < 0 si la primera cadena es alfabeticamente menor que la segunda, = 0 si son iguales, y > 0 si la primera cadena es mayor que la segunda. Es decir, si es negativo, 'a' va antes que 'b'. 0 son iguales. Y positivo 'a' después que 'b'
}


// Función para comparar las notas de dos estudiantes (mayor a menor)
int CompararNota(const void *a, const void *b){
       //Obtenemos las notas de ambos estudiantes
       float notaA = ((Estudiante*)a)->nota; //'a' es un puntero generico, (Estudiante*)a convierte ese puntero genérico a un puntero de tipo Estudiante (el struct)Trata a 'a' como si fuera un puntero a estudiante
       float notaB = ((Estudiante *)b)->nota;//Entonces lo que hace ->nota, accede al campo del struct. almacenamos el valor de la nota del estudiante en la variable notaA. 

       if (notaA < notaB)    // Si la nota de A es menor que la de B, A va después de B

       {
              return 1;
       }
       else if (notaA > notaB)    // Si la nota de A es mayor que la de B, A va antes de B

       {
              return -1;
       }
       else{  //Si son iguales, no cambia el orden
              
              return 0;
       }
}


int main(){

// Variable para guardar el número total de estudiantes
int total_est;
EstudiantesIntroducir(&total_est);//Llamamos a la función para obtener num de estudiantes que el usuario desee introducir. Tomamos un puntero, pasamos dir de memoria de la variable con el & la funcion puede modificar directamente el valor de esa variable.

if (total_est <= 0)//Para verificar que el numero de estudiantes que ha ingresado sea mayor que 0
{
       printf("El numero de estudiantes debe ser mayor a 0\n");
       return 1;//Termina el programa con un error.
}

Estudiante * estudiante = (Estudiante*) malloc(total_est * sizeof(Estudiante));

if (estudiante == NULL) {
    printf("Error al asignar memoria.\n");
    return 1;
}

 for (int i = 0; i < total_est; i++) {//bucle que recorre todos los estudiantes para introducir todos sus datos
        printf("Introduce los datos del estudiante %d:\n", i + 1);
        printf("Nombre: ");
        scanf("%s", estudiante[i].nombre);
        printf("Apellido: ");
        scanf("%s", estudiante[i].apellido);
        printf("Nota: ");
        scanf("%f", &estudiante[i].nota);
    }



qsort(estudiante/*puntero al primer elemento del array que queremos ordenar*/,total_est/*numero total de elementos, cuantos elementos queremos ordenar*/,sizeof(Estudiante)/*tamaño de cada elemento del array, le permite a qsort saber cuanto espacio ocupa cada struct para poder desplazarse de un elemento al siguiente*/,CompararApellido/*funcion que se encarga de comparar dos elementos del array*/);

printf("Estudiantes ordenados por apellido(alfabeticamente):\n");
for (int i = 0; i < total_est; ++i)
{
	 printf("Estudiante %d: %s %s, Nota: %.2f\n", i+1, estudiante[i].nombre, estudiante[i].apellido, estudiante[i].nota);
}

qsort(estudiante,total_est,sizeof(Estudiante), CompararNota);//Exactamente igual que en qsort de arriba, solo que cambiando la funcion por la de comparar la nota

printf("\n Estudiantes ordenados por nota (mayor a menor):\n");
for (int i = 0; i < total_est; ++i)
{
       printf("Estudiante %d: %s %s, Nota: %.2f\n", i +1, estudiante[i].nombre, estudiante[i].apellido, estudiante[i].nota);
}

free(estudiante);

return 0;
}
