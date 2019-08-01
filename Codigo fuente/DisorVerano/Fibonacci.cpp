#include "stdafx.h"
#include "Fibonacci.h"
#include <iostream>
#include "Conversiones.h"

using namespace std;

int indice, suma, a, b; 
std::vector<int> numerosF;

/*int secuenciaFibonacci(int numero) {
    if(numero == 0 || numero == 1){
		return numero;
	}
    else
		return secuenciaFibonacci(numero - 2) + secuenciaFibonacci(numero - 1);
}*/

std::vector<int> calcularSecuenciaFibonacci(int numero) {
    /*for(int i = 0; i < numero; i++) {
		if(secuenciaFibonacci(i) != 0)
			printf("\t"); 
		if(i == numero)
			printf(" ");
		cout << secuenciaFibonacci(i);
    }
	printf("\n");*/
	a = 0; 
	b = 1; 
	for(indice = 0; indice < numero; indice++) { 
		suma = a + b; 
		a = b; 
		b = suma; 
		//cout<< a <<" "; 
		numerosF.push_back(a);
	}
	return numerosF;
}