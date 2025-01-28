#include<stdio.h>
#include<stdlib.h>

/*
 *
 * 	Autor: Jose Maria De Lucas Plata.
 *
 */
int main (){
	char tablero[10][10];
	int columnas = 10;
	int filas = 10;
	int x = columnas / 2;
	int y = filas / 2;
	char movimiento = 'n';
	
	 // Llenar el tablero con espacios
	while (movimiento != 'q'){
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
        	if (i == y &&  j == x){
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
    	y--;
    }else if(movimiento == 's' && y < 8){
    	y++;
    }else if(movimiento == 'a' && x > 1){
    	x--;
    }else if (movimiento == 'd' && x < 8){
    	x++;
    }

    if (y == 5 && x == 8){
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