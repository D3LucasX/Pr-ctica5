#include<stdio.h>
#include<stdlib.h>
	


	int main(){

	int inventario[2][3][4][5][10]={0};



	inventario[0][0][0][0][0] = 50;

	inventario[1][1][1][3][2] = 120;

	inventario[0][2][4][4][3] = 300; 

	inventario[1][0][3][5][4] = 100;

	inventario[0][1][0][6][5] = 250;

printf("Inventario en america,sede 1,categoria televisores,modelo 0,lote 0:%d unidades\n",inventario[0][0][0][0][0]);
printf("Inventario en europa,sede 2,categaria telefonos,modelo 3,lote 2:%d unidades\n",inventario[1][1][1][3][2]);
printf("Inventario en america ,sede 3,categoria ordenadores,modelo 4,lote 3:%d unidades\n",inventario[0][2][4][4][3]);
printf("Inventario en europa ,sede 4,categoria electrodomesticos,modelo 5,lote 4:%d unidades\n",inventario[1][0][3][5][4]);
printf("Inventario en america ,sede 5,categoria telefonos,modelo 6,lote 5: %d unidades\n",inventario[0][1][0][6][5]);

return 0;

}
