#pragma once

#include <string>
#include <iostream>

using namespace std;


// Tabla hash con direccionamiento abierto (sondeo lineal) para guardar usuario -> contraseña.
// Cada casilla guarda la llave y la contraseña, para que al buscar se compare el usuario correcto.
class HashMap
{
	string* keys;      // usuario guardado en cada casilla ("" = casilla vacia)
	string* array;     // contraseña de ese usuario
	int size;
	int elements;
public:
	HashMap(int lenght):size(lenght), elements(0)
	{
		keys = new string[size];
		array = new string[size];
	}
	~HashMap()
	{
		delete[] keys;
		delete[] array;
	}
	HashMap(const HashMap&) = delete;            // la tabla maneja memoria propia: no se copia
	HashMap& operator=(const HashMap&) = delete;
	int probe(string key);
	unsigned long hash(string key);
	void insert(const string key,const string password);
 
	bool search(string key, string password);

};