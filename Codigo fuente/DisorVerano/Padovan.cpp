#include "stdafx.h"
#include "Padovan.h"
#include "OperacionesSimples.h"
#include <vector>

std::vector<int> numeros;

std::vector<int> sucesionPadovan(int numero) { 
    int prevPrev = 1, previo = 1, actual = 1, siguiente = 1; 
  
	//printf("%d",prevPrev);
	numeros.push_back(prevPrev);
	//printf("-%d",actual);
	numeros.push_back(actual);
    for (int i = 3; i <= numero; i++) { 
		siguiente = sumar(prevPrev, previo);
        prevPrev = previo; 
        previo = actual; 
		actual = siguiente; 
		//printf("-%d", previo);
		numeros.push_back(previo);
    } 
 
	return numeros; 
} 