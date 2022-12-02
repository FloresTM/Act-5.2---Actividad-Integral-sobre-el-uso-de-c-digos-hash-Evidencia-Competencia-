// =================================================================
//
// File: main.cpp
// Author:
// Date:
//
// =================================================================
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "exception.h"
#include "hash.h"

using namespace std;

//g++ -std=c++11 main.cpp -o app

unsigned int myHash1(const string s) {
	unsigned int acum = 0;
	for (unsigned int i = 0; i < s.size(); i++) {
		acum += (int) s[i];
	}
	return acum;
}

unsigned int myHash2(const string s) {
	return (unsigned int) s[0];
}

int main(int argc, char* argv[]) {

    // creamos archivo de input y output
  ifstream archivo1(argv[1]); 
  ofstream archivo2(argv[2]);

  int palabras_diccionario, descripciones_puestos, valor_dolares, suma_total;
  string palabra, descripcion_puesto;

  archivo1 >> palabras_diccionario >> descripciones_puestos;

	HashTable<string, int> hash(palabras_diccionario, string("empty"), myHash1);
  
  for(int i = 0; i < palabras_diccionario; i++){
    archivo1 >> palabra >> valor_dolares;
    hash.put(string(palabra), valor_dolares);
  }

	archivo2 << hash.toString() << "\n\n";
  
  for(int i = 0; i < descripciones_puestos; i++){
    archivo1 >> descripcion_puesto;
  }

  /*
  for(int j = 0; j < descripcion_puesto.size(); j++){
    archivo2 << descripcion_puesto << "\n.";
  }
  */

  archivo1.close();
  archivo2.close();
  
	return 0;
}