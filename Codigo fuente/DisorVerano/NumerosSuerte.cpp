#include "stdafx.h"
#include "OperacionesSimples.h"
#include "NumerosSuerte.h"
#include <vector>
#include <iostream>

using namespace std;

std::vector<int> almacen;
std::vector<int>::const_iterator index;

std::vector<int> calcularNumerosDeSuerte(int tope){
	llenarVector(tope);
	
	std::vector<int>::iterator itera = almacen.begin();
	std::vector<int>::iterator iterafin = almacen.end();
	while (itera != almacen.end()) {
        if (residuo(*itera, 2) == 0) //Verifica si es par.
			itera = almacen.erase(itera); //Elimina los pares.
        else
           ++itera;
    }

	//imprimirVector();
	return almacen;
}

std::vector<int> llenarVector(int tope){
	for(int tam = 1; tam <= tope; tam++)
		almacen.push_back(tam);
	return almacen;
}

int imprimirVector(){
	for(index = almacen.begin(); index != almacen.end(); ++index)
		cout<<(*index)<<"\t";
	return 0;
}