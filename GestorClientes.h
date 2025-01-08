#pragma once
#include "Cliente.h"


class Gestor
{
	Cliente* clientes;
	int size;
public:
	Gestor(); 
	void eliminarUltimo();
	void eliminarPrimero();
	void eliminarCliente(int index);
	void agregarCliente(const Cliente& nuevoCliente);
	void modificarCliente(int index);
	void mostrarClientes();
};
