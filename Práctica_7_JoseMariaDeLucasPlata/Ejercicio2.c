#include <stdio.h>
#include <stdlib.h>



typedef struct 
{

	char nombre [100];
	char apellido [100];
	int nota;


}Estudiante;



void EstudiantesIntroducir(int * total_est){

printf("¿Cuántos estudiantes quieres introducir?\n");
scanf("%d", total_est);
printf("El total de estudiantes es %d", *total_est);

}


int main{

Estudiante * estudiante = (Estudiante*) malloc(total_est * sizeof(Estudiante));

 for (int i = 0; i < total_est; i++) {
        printf("Introduce los datos del estudiante %d:\n", i + 1);
        printf("Nombre: ");
        scanf("%s", estudiante[i].nombre);
        printf("Apellido: ");
        scanf("%s", estudiante[i].apellido);
        printf("Nota: ");
        scanf("%f", &estudiante[i].nota);
    }



printf("Estudiante:\n");
for (int i = 0; i < total_est; ++i)
{
	 printf("Estudiante %d: %s %s, Nota: %.2f\n", i+1, estudiante[i].nombre, estudiante[i].apellido, estudiante[i].nota);
}


free(estudiante);

return 0;
}
