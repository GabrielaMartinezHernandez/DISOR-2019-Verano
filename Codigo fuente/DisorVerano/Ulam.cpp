#include "stdafx.h"
#include <conio.h>
#include <stdio.h>
#include "Ulam.h"
#include "OperacionesSimples.h"
#include <vector>

std::vector<int> numerosU;

std::vector<int> secuenciaUlam(int numero){
	do{
		if(residuo(numero, 2) == 0)
			numero = dividir(numero, 2);
		else {
			numero = multiplicar(numero, 3);
			numero = sumar(numero, 1);
		}
		//printf("-%d",numero);
		numerosU.push_back(numero);
	} while(numero != 1);
	return numerosU;
}