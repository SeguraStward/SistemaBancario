// Pruebas del HashMap de contraseñas.
// Compilar y ejecutar:  g++ -std=c++17 -I. tests/test_hashmap.cpp HashMap.cpp -o test_hashmap && ./test_hashmap
#include <cassert>
#include <iostream>
#include "HashMap.h"

int main()
{
	// Tabla pequeña para forzar colisiones.
	HashMap tabla(5);
	tabla.insert("ana", "clave-ana");
	tabla.insert("luis", "clave-luis");

	assert(tabla.search("ana", "clave-ana"));
	assert(tabla.search("luis", "clave-luis"));
	assert(!tabla.search("ana", "clave-luis"));   // no se puede entrar con la contraseña de otro
	assert(!tabla.search("pedro", "clave-ana"));  // usuario inexistente

	tabla.insert("ana", "nueva");                 // actualizar no duplica
	assert(tabla.search("ana", "nueva"));
	assert(!tabla.search("ana", "clave-ana"));

	// Muchas llaves en una tabla grande: ninguna se sobrescribe.
	HashMap grande(101);
	for (int i = 0; i < 50; i++) grande.insert("usuario" + std::to_string(i), "pw" + std::to_string(i));
	for (int i = 0; i < 50; i++) assert(grande.search("usuario" + std::to_string(i), "pw" + std::to_string(i)));

	std::cout << "Todas las pruebas del HashMap pasaron\n";
	return 0;
}
