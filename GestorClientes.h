#pragma once
#include "Cliente.h"


class Gestor
{
	Cliente* clientes;
	int size;
public:
	Gestor();
	//destructor
	~Gestor();
	Cliente* getCliente(int id);
	void eliminarUltimo();
	void eliminarPrimero();
	void eliminarCliente(int index);
	void agregarCliente(Cliente& nuevoCliente);
	void modificarCliente(int index);
	void mostrarClientes();
	void mostrarAllInfoClientes();
	int contadorDeClientes(Gestor* gestor);
	Cliente* getClientes()
	{
		return clientes;
	}
	int getSize() const
	{
		return size;
	}
	int recursiveMethod(int min, int max);
};
