#include "stdafx.h"
#include <iostream>
#include <sstream> 
#include "Fibonacci.h"
#include "OperacionesSimples.h"

using namespace std;

int convertirABinario(int numero) {
	int dividendo, resto, divisor = 2;
	string binario = "", ordenado = "";
	stringstream stream; // convertidor de int a string
	dividendo = numero; //se le asigna al dividendo el valor que resulte de la secuencia.
	while(dividendo >= divisor) {
		//resto = dividendo % 2;
		resto = residuo(dividendo, 2);
		stream << resto; // almacena el resto de las divisiones concatenandolas en el objeto stream.
		//dividendo = dividendo/divisor;
		dividendo = dividir(dividendo, divisor);
	}
	stream << dividendo;
	binario = stream.str(); //almacena en binario de tipo string los valores concatenados del objeto stream.
	for(unsigned int i = 0; i < binario.size(); i++)//se ordenan los bits
		ordenado = binario[i] + ordenado;
	cout <<  ordenado << "\t "; //imprime el numero convertido
	return 0;
}

int convertirAHexadecimal(int numero){
	char numHexa[100];
	int i = 1, temp, cociente;
	cociente = numero;
	while(cociente != 0) {
		//temp = cociente % 16;
		temp = residuo(cociente, 16);
		//convierte entero a caracter
		if(temp > 10)// si el numero es mayor a 10 se le aumenta 55 para que lo tome como letra
			//temp = temp + 55;
			temp = sumar(temp, 55);
		else
			//temp = temp + 48;//si es menor a 10 entonces se toman como numeros normales
			temp = sumar(temp, 48);
		numHexa[i++] = temp;// se agrega el caracter/numero al arreglo
		//cociente = cociente/ 16;
		cociente = dividir(cociente, 16);
	}
    //imprime los numeros de la serie
	for(int j = i -1 ;j > 0; j--)
		cout<<numHexa[j] << "\t";
    //cout << " ";
	return 0;
}

int numeroANombre(int numero){
	int dMil, uMil, centenas, decenas, unidades;
	dMil = dividir(numero, 10000); //Decenas de mil.
	uMil = residuo(dividir(numero, 1000), 10); //Unidades de mil.
	centenas = residuo(dividir(numero, 100), 10); //Centenas.
	decenas = residuo(dividir(numero, 10), 10); //Decenas
	unidades = residuo(numero, 10); //Unidades
 
   if(numero > 10000)
      cout<<" ";
   else{
      if(dMil == 1)
      cout<<"Diez mil";
      
      //Sentencia para determinar los miles
      if(uMil == 1){
         cout<<"MIL ";
      }else if(uMil == 2){
         cout<<"DOS MIL ";
      }else if(uMil == 3){
         cout<<"TRES MIL ";
      }else if(uMil == 4){
         cout<<"CUATRO MIL ";
      }else if(uMil == 5){
         cout<<"CINCO MIL ";
      }else if(uMil == 6){
        cout<<"SEIS MIL ";
      }else if(uMil == 7){
         cout<<"SIETE MIL ";
      }else if(uMil == 8){
         cout<<"OCHO MIL ";
      }else if(uMil == 9){
         cout<<"NUEVE MIL ";
      }
      //Setencia para determinar los cientos
      if(centenas == 1 && decenas == 0 && unidades == 0){
         cout<<"CIEN";
      }else if(centenas == 1){
         cout<<"CIENTO ";
      }else if(centenas == 2){
         cout<<"DOSCIENTOS ";
      }else if(centenas == 3){
         cout<<"TRESCIENTOS ";
      }else if(centenas == 4){
         cout<<"CUATROCIENTOS ";
      }else if(centenas == 5){
         cout<<"QUINIENTOS ";
      }else if(centenas == 6){
         cout<<"SEISCIENTOS ";
      }else if(centenas == 7){
         cout<<"SETECIENTOS ";
      }else if(centenas == 8){
         cout<<"OCHOCIENTOS ";
      }else if(centenas == 9){
         cout<<"NOVECIENTOS ";
      }
      //Setencia para determinar las decenas
      if(decenas == 1 && unidades == 0){
         cout<<"Diez";
      }else if(decenas == 1 && unidades == 1){
         cout<<"ONCE";
      }else if(decenas == 1 && unidades == 2){
         cout<<"DOCE";
      }else if(decenas == 1 && unidades == 3){
         cout<<"TRECE";
      }else if(decenas == 1 && unidades == 4){
         cout<<"CATORCE";
      }else if(decenas == 1 && unidades == 5){
         cout<<"QUINCE";
      }else if(decenas == 1){
         cout<<"DIECI";
      }
      if(decenas == 2 && unidades == 0){
         cout<<"VEINTE";
      }else if(decenas == 2){
         cout<<"VEINTI";
      }else if(decenas == 3 && unidades == 0){
         cout<<"TREINTA";
      }else if(decenas == 3){
         cout<<"TREINTA Y ";
      }else if(decenas == 4 && unidades == 0){
         cout<<"CUARENTA";
      }else if(decenas == 4){
         cout<<"CUARENTA Y ";
      }else if(decenas == 5 && unidades == 0){
         cout<<"CINCUENTA";
      }else if(decenas == 5){
         cout<<"CINCUENTA Y ";
      }else if(decenas == 6 && unidades == 0){
         cout<<"SESENTA";
      }else if(decenas == 6){
         cout<<"SESENTA Y ";
      }else if(decenas == 7 && unidades == 0){
         cout<<"SETENTA";
      }else if(decenas == 7){
         cout<<"SETENTA Y ";
      }else if(decenas == 8 && unidades == 0){
         cout<<"OCHENTA";
      }else if(decenas == 8){
         cout<<"OCHENTA Y ";
      }else if(decenas == 9 && unidades == 0){
         cout<<"NOVENTA";
      }
      else if(decenas == 9){
         cout<<"NOVENTA Y ";
      }
      //Sentencia para determinar las unidades 
	  if(unidades == 0 && decenas == 0 && centenas == 0 && uMil == 0 && dMil == 0)
		  cout << "CERO";
      if(unidades == 1 && decenas > 1){
         cout<<"UNO";
      }else if(unidades == 1 && decenas == 0){
         cout<<"UNO"; 
      }else if(unidades == 2 && decenas > 1){
         cout<<"DOS";
      }else if(unidades == 2 && decenas == 0){
         cout<<"DOS";
      }else if(unidades == 3 && decenas > 1){
         cout<<"TRES";
      }else if(unidades == 3 && decenas == 0){
         cout<<"TRES"; 
      }else if(unidades == 4 && decenas > 1){
         cout<<"CUATRO";
      }else if(unidades == 4 && decenas == 0){
         cout<<"CUATRO"; 
      }else if(unidades == 5 && decenas > 1){
         cout<<"CINCO";
      }else if(unidades == 5 && decenas == 0){
         cout<<"CINCO";
      }else if(unidades == 6){
         cout<<"SEIS";
      }else if(unidades == 7){
         cout<<"SIETE";
      }else if(unidades == 8){
         cout<<"OCHO";
      }else if(unidades == 9){
         cout<<"NUEVE";
      }
   }
   printf("\t");
   return 0;
}