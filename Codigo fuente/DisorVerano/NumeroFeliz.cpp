#include "stdafx.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "NumeroFeliz.h"
#include "OperacionesSimples.h"

int numeros[10] = {0}; //Acepta un número de hasta 10 dígitos.
int i = 0, sum = 0, z = 0;

int verificarEsFeliz(int numero) {
	if(numero == 0 || numero == 1 || numero == 7)
		printf("Feliz \t");
	else{
		while (z < 20) { //Cuando el número no es feliz entra en un bucle infinito, si se pasa de 20 ciclos se sale.
			digitosNumeros(numero); //Se separa en dígitos los números.
			sum = 0;
			for (i = 0; i < 10; i++) 
					sum = sumar(sum,numeros[i]);

			if (sum == 1) {
				printf("Feliz \t");
				return 0;
			}
			sum = 0;
			for (i = 0; i < 10; i++)
				sum = sumar(sum,_Pow_int(numeros[i], 2)); //Se suma la operación anterior más el número al cuadrado.
 
			numero = sum;
			memset(numeros,0,40);
			z++;
		}
		printf("Triste \t");
	}
    return 0;
}

int digitosNumeros(int numeroDigitos){
    int i = 0;
    int n;
    while(numeroDigitos > 0) {
        //numeros[i]  = numeroDigitos % 10;
		numeros[i] = residuo (numeroDigitos, 10);
        //numeroDigitos = numeroDigitos / 10;
		numeroDigitos = dividir(numeroDigitos, 10);
        i++;
    }
    return 0;
}