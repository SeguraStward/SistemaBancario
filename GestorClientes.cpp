#include "GestorClientes.h"


Gestor::Gestor()
{
	size = 0;
	clientes = new Cliente[size];
}
  
void Gestor::agregarCliente(const Cliente& nuevoCliente)
{
	size++;
	Cliente* auxiliar = new Cliente[size];//creando un nuevo array dinamico con mayor size

	 int i = 0;
	 for(;i<size-1;i++)//O(n) se itera n veces y espacio O(n) tambien son n elementos
	 {
		 auxiliar[i] = clientes[i];
	 }
	 auxiliar[i] = nuevoCliente;
	  
	 delete[] clientes;//liberando memoria
	 clientes = nullptr; //desocupando direccion de memoria
	 clientes = auxiliar;//ahora clientes apunta a la misma direccion de auxiliar que es el vector actualizado

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
		auxiliar[i] = clientes[i+1];//se copian desde la posicion 1 del array de clientes entonces asi se evita copiar la posicion 0 
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

	for (int i = 0; i < size; i++)//con la reduccion de size basta para no copiar el ultimo
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
		if (i == index)j++; //la posicion que no se copiara se salta 
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
