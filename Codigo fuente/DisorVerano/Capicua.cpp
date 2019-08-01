#include "stdafx.h"
#include "Capicua.h"
#include "OperacionesSimples.h"

int verificarCapicua(int numero){
	int a = numero, b = 0, c = 0;
	
	while(a != 0) {
		//b=a%10;
		b = residuo(a, 10);
		//a=a/10;
		a = dividir(a, 10);
		//c=c*10+b;
		c = sumar(multiplicar(c, 10), b);
	}

	if(c == numero)
		printf("Es capicua \t");
	else
		printf("NO capicua \t");

	return 0;
}