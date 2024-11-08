#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define PRODUCTO_MAX 10
#define EXIST_MIN 5

struct Productos{
	char nombre[20];
	int cantidad_stock;

};
int main(){
	int cantidad_productos, i, reabastecer = 0, agregar_cant = 0, encontrado = 0;
	char nombre_producto[20];//Para almacenar el producto que escriba el usuario
	char busqueda[20];

	printf("Intrege la cantidad de productos que desea gestionar: \n");
	scanf("%d", &cantidad_productos);

	if(cantidad_productos < 0 || cantidad_productos > PRODUCTO_MAX){
		printf("El valor introducido no es válido.");
		return 1;
	}
	struct Productos Informatica[cantidad_productos];

	for(i = 0; i < cantidad_productos; i++){
		printf("Producto %d\n", i + 1);

		printf("Nombre: ");
		scanf(" %[^\n]", Informatica[i].nombre); //Con %[^\n] permitimos introducir un nombre usando espacios, dejamos un espacio antes de 
							 //'%' para evitar errores.

		printf("Cantidad: ");
		scanf(" %d",&Informatica[i].cantidad_stock);
	}

	printf("Inventario completo: \n"); //Mostramos el inventario completo
	for (i = 0; i < cantidad_productos; i++){
		printf("Producto %d: %s - %d unidades\n", i + 1, Informatica[i].nombre, Informatica[i].cantidad_stock);
	}

	printf("Si desea reabastecer algún producto, pulse 1, si no pulse 2:\n");
	scanf(" %d", &reabastecer);
	if (reabastecer != 1){
		printf("Perfecto, hasta la proxima!\n"); // retornamos 1 si es distinto de 1, asi sale del programa.
	}

	while(reabastecer == 1){ //Haacemos un bucle while y no un do while para que primero lea la condicion, antes que las instrucciones.

		printf("¿Que producto quiere reabastecer?\n");
		scanf(" %[^\n]", nombre_producto);

		for(i = 0; i < cantidad_productos; i++){

			if (strcmp(nombre_producto, Informatica[i].nombre) == 0) {
				printf("Producto encontrado: %s - %d unidades en stock.\n", Informatica[i].nombre, Informatica[i].cantidad_stock);

				printf("¿Que cantidad quiere añadir de %s?\n",Informatica[i].nombre);
				scanf(" %d", &agregar_cant);

				Informatica[i].cantidad_stock += agregar_cant;
				printf("El producto ha sido actualizado, la nueva cantidad en stock es: %d\n", Informatica[i].cantidad_stock);

				printf("Si desea reabastecer otro producto, pulse 1, si no pulse 2:\n");
				scanf(" %d", &reabastecer);
				if (reabastecer != 1){

					printf("Perfecto, hasta la proxima!\n");
				}
				break; //Este break lo ponemos para que si encuentra el producto que queremos modificar no siga dando vueltas comparando con el resto de productos.
			}
		}
	}


	printf("Productos en baja existencia\n");
	for(i = 0; i < cantidad_productos; i++){
		if(Informatica[i].cantidad_stock < EXIST_MIN){
			printf("%s - %d unidades\n", Informatica[i].nombre, Informatica[i].cantidad_stock);
		}
	}	

	printf("Introduzca el nombre del producto que quiere buscar.\n");
	scanf(" %[^\n]", busqueda); //%[^\n], nos permite introducir un nombre usando espacios pero hay que dar un espacio antes del '%' para evitar posibles errores.
	getchar(); //Con esto limpiamos el buffer de entrada para que lea lo que queremos que lea.

	for(i = 0; i < cantidad_productos; i++){


		if (strcmp(busqueda, Informatica[i].nombre) == 0) {
			printf("Producto encontrado: %s - %d unidades en stock.\n", Informatica[i].nombre, Informatica[i].cantidad_stock);
			encontrado = 1;

		break;

		}
		}
		if (!encontrado){	
			printf("Lo sentiomos, ese producto no se encuentra en el sistema.\n");
		}
		return 0;
	}



