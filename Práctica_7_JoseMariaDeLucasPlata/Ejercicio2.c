#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct 
{

	char nombre [100];
	char apellido [100];
	float nota;


}Estudiante;



void EstudiantesIntroducir(int *total_est){ //total_est lo tengo que pasar por referencia

printf("¿Cuántos estudiantes quieres introducir?\n");
scanf("%d", total_est);
printf("El total de estudiantes es %d\n", *total_est);

}
//Es la estructura para usar el qsort
int CompararApellido (const void *a,const void *b){//Para utilizar el qsort...Se convierte cada uno de estos punteros genéricos al tipo Estudiante *. Usamos el -> para acceder al campo apellido

       return strcmp(((Estudiante *)a)->apellido, ((Estudiante *)b)-> apellido);
       //Obtiene la cadena que contiene el apellido del estudiante al que apunta a, e igual para b.
       //El return de strcmp su valor es < 0 si la primera cadena es alfabeticamente menor que la segunda, = 0 si son iguales, y > 0 si la primera cadena es mayor que la segunda. Es decir, si es negativo, 'a' va antes que 'b'. 0 son iguales. Y positivo 'a' después que 'b'
}


int CompararNota(const void *a, const void *b){
       float notaA = ((Estudiante*)a)->nota; //'a' es un puntero generico, (Estudiante*)a convierte ese puntero genérico a un puntero de tipo Estudiante (el struct)Trata a 'a' como si fuera un puntero a estudiante
       float notaB = ((Estudiante *)b)->nota;//Entonces lo que hace ->nota, accede al campo del struct. almacenamos el valor de la nota del estudiante en la variable notaA. 

       if (notaA < notaB)
       {
              return 1;
       }
       else if (notaA > notaB)
       {
              return -1;
       }
       else{
              return 0;
       }
}



int main(){

int total_est;
EstudiantesIntroducir(&total_est);//Llamamos para obtener num de estudiantes que el usuario desee introducir. Tomamos un puntero, pasamos dir de memoria de la variable con el & la funcion puede modificar directamente el valor de esa variable.

if (total_est <= 0)
{
       printf("El numero de estudiantes debe ser mayor a 0\n");
       return 1;
}

Estudiante * estudiante = (Estudiante*) malloc(total_est * sizeof(Estudiante));

if (estudiante == NULL) {
    printf("Error al asignar memoria.\n");
    return 1;
}

 for (int i = 0; i < total_est; i++) {
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