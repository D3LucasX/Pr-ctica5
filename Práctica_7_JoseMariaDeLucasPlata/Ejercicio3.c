#include<stdio.h>
#include<stdlib.h>

/*
 *
 * 	Autor: Jose Maria De Lucas Plata.
 * 	       Marcos Escamilla Ojeda.
 *
 */
int main (){
    //Definimos tablero de 10x10 y las variables
	char tablero[10][10];
	int columnas = 10;
	int filas = 10;
	int x = columnas / 2;
	int y = filas / 2;
	char movimiento = 'n';//Inicializamos con valor cualquiera
	
	 // Llenar el tablero con espacios
	while (movimiento != 'q'){//Se ejecuta hasta que el usuario presione 'q'

    //rellenamos tablero con espacios en blanco y colocamos el jugador '#'
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
        	if (i == y &&  j == x){//si es la posicion del jugador, es x 
        	tablero[i][j] = '#';
        	}else{
            tablero[i][j] = ' ';  // Espacio vacío
        	}
        }
    }

    // Colocar '*' en el borde
    for (int i = 0; i < 10; i++) {
        // Borde superior e inferior
        tablero[0][i] = '*';  // Borde superior
        tablero[9][i] = '*';  // Borde inferior

        // Bordes izquierdo y derecho
        tablero[i][0] = '*';  // Borde izquierdo
        tablero[i][9] = '*';  // Borde derecho
    }

    // Imprimir el tablero
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%c ", tablero[i][j]);
        }
        printf(" \n");  // Nueva línea al final de cada fila

    }
    scanf(" %c", &movimiento);
    if(movimiento == 'w' && y > 1){
    	y--;  // Si marcamos la 'w' avanzara una fila hacia adelante
	      // hasta que llegue a la fila 1, que como no va a ser mayo, no se va a mover haca 
	      // arriba.
    }else if(movimiento == 's' && y < 8){
    	y++;  // Si marcamos la 's', retrocedera una fila hacia abajo,
	      // hasta que y < 8, que cuando llegue ahi, como no va a ser 
	      // menor, no se moverá más hacia abajo.
    }else if(movimiento == 'a' && x > 1){
    	x--;  // Si marcamos la 'a' se movera hacia la izquierda hasta que 
	      // este en la posicion 1, cuando llegue ahi,
	      // al no ser menor que 1, no sse desplazara mas columnas
	      // hacia la izquierda.
    }else if (movimiento == 'd' && x < 8){
    	x++;  // Si marcamos la 'd', se movera el cursor hacia la derecha,
	      // hasta que x sea 8, ya que cuando llegue ahí,
	      // no va a ser menor, asi que no se movera más columnas 
	      // hacia la derecha.
    }

    if (y == 5 && x == 8){ // Tonterias mías.
    	printf("YO YA HE ESTADO EN ESTOS JUEGOS!!!!\n\
SIGUEME, SE LA SALIDA!!\n\
(el jugador se ha salvado)\n)");
    	break;
    }else if (y == 3 && x == 2){
    	printf("TE HAN DISPARADO EN LA CABEZA, HAS MUERTO\n");
    	break;
    }

    system("clear");
}

	return 0;
}
