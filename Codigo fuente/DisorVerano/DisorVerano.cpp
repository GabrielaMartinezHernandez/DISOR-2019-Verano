// DisorVerano.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <vector>
#include "OperacionesSimples.h"
#include "NumeroFeliz.h"
#include "Fibonacci.h"
#include "Ulam.h"
#include "Padovan.h"
#include "Capicua.h"
#include "Fibonacci.h"
#include "Conversiones.h"
#include "NumerosSuerte.h"

using namespace std;

int imprimeFibonacci(int tope);
int imprimePadovan(int tope);
int imprimeUlam(int tope);
int imprimeNumerosDeSuerte(int tope);
int avanzar(int conta);
int retroceder(int conta);

std::vector<int>::const_iterator iter; //Se crea un iterador para poder recorrer el vector.
std::vector<int> valoresFibonacci, valoresPadovan, valoresUlam, valoresSuerte;

int contador = 0, numero, opcion;
	
int main(){
	printf("Introduce las iteraciones a imprimir: ");
	scanf_s("%i", &numero);
	
		if (numero < 0)
			printf("No son validos numeros negativos.\n");
		else{
			imprimeFibonacci(numero);
			printf("\n");	
			imprimePadovan(numero);
			printf("\n");	
			imprimeUlam(numero);
			printf("\n");
			imprimeNumerosDeSuerte(numero);
		}
	do{ 
		printf("\nSeleccione una opcion: \t1. Avanzar \t2.Retroceder \t3.Salir\n");
		scanf_s("%i", &opcion);
		switch (opcion) {
			case 1: contador++;
				system("cls");
				avanzar(contador);
				break;
			case 2: contador--;
				system("cls");
				retroceder(contador);
				break;
			case 3:
				system("pause");
				return 0; 
			break;
		default:
			break;
		}
	}while(opcion !=3);
	
	//SUCESIÓN DE PADOVAN
		//sucesionPadovan(numero);

	//SUCESIÓN DE ULAM
		//secuenciaUlam(numero);

	//NÚMERO FELIZ
		//verificarEsFeliz(numero);

	//CAPICUA
		//verificarCapicua(numero);

	//convertirABinario(4);
	//numeroANombre(1463);
	printf("\n");
	system("pause");
    return 0; 
}

int avanzar(int cont){
	//Suma los últimos dos elementos y el resultado lo vuelve a almacenar en el vector.
	int aux1 = valoresFibonacci.size(),  aux2 = valoresFibonacci.size() - 1, sumaElementos;
	sumaElementos = sumar(valoresFibonacci[aux1],valoresFibonacci[aux2]) ;
	valoresFibonacci.push_back(sumaElementos);
	for(int i = cont; i < valoresFibonacci.size(); i++)
		cout << valoresFibonacci[i] << " \t";
	return 0;
}

int retroceder(int cont){
	//Borra último elemento.
	std::vector<int>::iterator iteration = valoresFibonacci.begin();
	while (iteration != valoresFibonacci.end()) {
		iteration++;
    }
	iteration = valoresFibonacci.erase(iteration); 
	return 0;
}

int imprimeFibonacci(int tope){
	printf("FIBONACCI\n");
	valoresFibonacci = calcularSecuenciaFibonacci(tope);
	cout << "Decimal: \t";
	for(iter = valoresFibonacci.begin(); iter != valoresFibonacci.end(); ++iter)
		cout << (*iter)<<"\t";
	printf("\n"); cout << "Binario: \t";
	for(iter = valoresFibonacci.begin(); iter != valoresFibonacci.end(); ++iter)
		convertirABinario(*iter);
	printf("\n"); cout << "Hexadecimal: \t";
	for(iter = valoresFibonacci.begin(); iter != valoresFibonacci.end(); ++iter)
		convertirAHexadecimal(*iter);
	printf("\n"); cout << "Nombre: \t";
	for(iter = valoresFibonacci.begin(); iter != valoresFibonacci.end(); ++iter)
		numeroANombre(*iter);
	printf("\n"); cout << "Es feliz? \t";
	for(iter = valoresFibonacci.begin(); iter != valoresFibonacci.end(); ++iter)
		verificarEsFeliz(*iter);
	printf("\n"); cout << "Es capicua? \t";
	for(iter = valoresFibonacci.begin(); iter != valoresFibonacci.end(); ++iter)
		verificarCapicua(*iter);
	return 0;
}

int imprimePadovan(int tope){
	printf("\nPADOVAN\n");
	valoresPadovan = sucesionPadovan(tope);
	cout << "Decimal: \t";
	for(iter = valoresPadovan.begin(); iter != valoresPadovan.end(); ++iter)
		cout << (*iter)<<"\t";
	printf("\n"); cout << "Binario: \t";
	for(iter = valoresPadovan.begin(); iter != valoresPadovan.end(); ++iter)
		convertirABinario(*iter);
	printf("\n"); cout << "Hexadecimal: \t";
	for(iter = valoresPadovan.begin(); iter != valoresPadovan.end(); ++iter)
		convertirAHexadecimal(*iter);
	printf("\n"); cout << "Nombre: \t";
	for(iter = valoresPadovan.begin(); iter != valoresPadovan.end(); ++iter)
		numeroANombre(*iter);
	printf("\n"); cout << "Es feliz? \t";
	for(iter = valoresPadovan.begin(); iter != valoresPadovan.end(); ++iter)
		verificarEsFeliz(*iter);
	printf("\n"); cout << "Es capicua? \t";
	for(iter = valoresPadovan.begin(); iter != valoresPadovan.end(); ++iter)
		verificarCapicua(*iter);
	return 0;
}

int imprimeUlam(int numero){ //Apartir del número da la secuencia
	printf("\nULAM\n");
	valoresUlam = secuenciaUlam(numero);
	cout << "Decimal: \t";
	for(iter = valoresUlam.begin(); iter != valoresUlam.end(); ++iter)
		cout<<(*iter)<<"\t";
	printf("\n"); cout << "Binario: \t";
	for(iter = valoresUlam.begin(); iter != valoresUlam.end(); ++iter)
		convertirABinario(*iter);
	printf("\n"); cout << "Hexadecimal: \t";
	for(iter = valoresUlam.begin(); iter != valoresUlam.end(); ++iter)
		convertirAHexadecimal(*iter);
	printf("\n"); cout << "Nombre: \t";
	for(iter = valoresUlam.begin(); iter != valoresUlam.end(); ++iter)
		numeroANombre(*iter);
	printf("\n"); cout << "Es feliz? \t";
	for(iter = valoresUlam.begin(); iter != valoresUlam.end(); ++iter)
		verificarEsFeliz(*iter);
	printf("\n"); cout << "Es capicua? \t";
	for(iter = valoresUlam.begin(); iter != valoresUlam.end(); ++iter)
		verificarCapicua(*iter);
	return 0;
}

int imprimeNumerosDeSuerte(int tope){
	printf("\nNUMEROS DE LA SUERTE\n");
	valoresSuerte = calcularNumerosDeSuerte(tope);
	cout << "Decimal: \t";
	for(iter = valoresSuerte.begin(); iter != valoresSuerte.end(); ++iter)
		cout <<(*iter)<<"\t";
	printf("\n"); cout << "Binario: \t";
	for(iter = valoresSuerte.begin(); iter != valoresSuerte.end(); ++iter)
		convertirABinario(*iter);
	printf("\n"); cout << "Hexadecimal: \t";
	for(iter = valoresSuerte.begin(); iter != valoresSuerte.end(); ++iter)
		convertirAHexadecimal(*iter);
	printf("\n"); cout << "Nombre: \t";
	for(iter = valoresSuerte.begin(); iter != valoresSuerte.end(); ++iter)
		numeroANombre(*iter);
	printf("\n"); cout << "Es feliz? \t";
	for(iter = valoresSuerte.begin(); iter != valoresSuerte.end(); ++iter)
		verificarEsFeliz(*iter);
	printf("\n"); cout << "Es capicua? \t";
	for(iter = valoresSuerte.begin(); iter != valoresSuerte.end(); ++iter)
		verificarCapicua(*iter);
	return 0;
}