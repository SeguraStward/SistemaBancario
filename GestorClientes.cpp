#include "GestorClientes.h"


Gestor::Gestor()
{
	size = 0;
	clientes = new Cliente[size];
}
  
void Gestor::agregarCliente(const Cliente& nuevoCliente)
{
	size++;
	Cliente* auxiliar = new Cliente[size];

	 int i = 0;
	 for(;i<size-1;i++)
	 {
		 auxiliar[i] = clientes[i];
	 }
	 auxiliar[i] = nuevoCliente;
	  
	 delete[] clientes;
	 clientes = nullptr; 
	 clientes = auxiliar;

}

void Gestor::eliminarPrimero()
{
	if(size <= 0)
	{
		cerr << "No hay elementos para eliminar.";
		return;
	}
	size--;
	Cliente* auxiliar = new Cliente[size];

	for(int i = 0; i < size;i++)
	{
		auxiliar[i] = clientes[i+1];
	}

	delete[] clientes;
	clientes = nullptr;
	clientes = auxiliar; 
}

void Gestor::eliminarUltimo()
{
	if (size <= 0)
	{
		cerr << "No hay elementos para eliminar.";
		return;
	}
	size--;
	Cliente* auxiliar = new Cliente[size];

	for (int i = 0; i < size; i++)
	{
		auxiliar[i] = clientes[i];
	}

	delete[] clientes;
	clientes = nullptr;
	clientes = auxiliar;
}

void Gestor::eliminarCliente(int index)
{
	if (size <= 0)
	{
		cerr << "No hay elementos para eliminar.";
		return;
	}
	size--;
	Cliente* auxiliar = new Cliente[size];

	int j = 0;

	for (int i = 0; i < size; i++)
	{
		if (i == index)j++; 
		auxiliar[i] = clientes[j];
	}

	delete[] clientes;
	clientes = nullptr;
	clientes = auxiliar;
}




void Gestor::mostrarClientes()
{
	for(int i= 0; i< size;i++)
	{
		cout << "Indice: " << i << " Cliente -> " << clientes[i].getNombreCompleto() << endl;
	}
	 
}
