#include<stdio.h>
#include<stdlib.h>

/*
 *
 * 	Autor: Jose Maria De Lucas Plata.
 *
 */
void EsPrimo(int* array, int num){

	for (int i = 0; i < num; i++){
			if(num <= 1){
				continue;
		for(int j = 2; i * i <= num){
			if(num % i == 0){
				array[i] = num;
			}else{
				continue;
			}
		}

		}
	}
int main (){
	int num = 0;
	while (num < 10){
		printf("Dame un número mayor de 10\n", num);
		scanf("%d", &num);
	}
	int* array = (int*) malloc (num * sizeof(int));
	for(int i = 0; i < num; i++){
		array[i] = i;
	}
	EsPrimo(array, tamano);
	for(int i = 0; i < ){

	}



	return EXIT_SUCCESS;

}