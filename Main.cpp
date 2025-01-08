#include <iostream>
#include "GestorClientes.h"

using namespace std;


int main()
{
	Gestor gestor;

	bool terminar = false;
	string nombre;
	string direccion;
	string numeroContacto;
	int id = 0;
	string finalizar;
	while(!terminar)
	{
		cout << "Ingrese nombre: ";
		cin >> nombre;
		cout << endl;
		cout << "Ingrese direccion: ";
		cin >> direccion;
		cout << endl;
		cout << "Ingrese numero: ";
		cin >> numeroContacto;
		cout << endl;

		id++;
		Cliente cliente = Cliente(nombre, id, direccion, numeroContacto);

		gestor.agregarCliente(cliente);


		cout << "Desea continuar, si o no?" << endl;
		cin >> finalizar;
		if(finalizar == "no")
		{
			terminar = true;
		}
	}
	gestor.eliminarUltimo();
	gestor.mostrarClientes();



	return 0;
}