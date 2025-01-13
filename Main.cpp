#include <iostream>
#include "GestorClientes.h"
 
using namespace std;


void limpiarPantalla() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

void modificarOEliminarCliente(Gestor& gestor)
{
	int indice = -1;
	int choose = -1;
	gestor.mostrarClientes();
	cout << "Ingrese el indice del cliente que desea modificar o eliminar: ";

	cin >> indice;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "1-Modificar cliente  2-Eliminar cliente";
	cin >> choose;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	switch (choose)
	{
	case 1://caso 1 para modificar el cliente se valida el indice y se utiliza el metodo para modificar
		if (indice < gestor.getSize() && indice >= 0)
		{
			gestor.modificarCliente(indice);
		}
		else
		{
			cout << "Indice invalido\n";
		}
		break;
	case 2: //caso 2 igual que el uno solo que elimina el indice
		if (indice < gestor.getSize() && indice >= 0)
		{
			gestor.eliminarCliente(indice);
		}
		else
		{
			cout << "Indice invalido\n";
		}
		break;
	default:
		cout << "No elegiste una opcion valida...\n";
		break;
	}

}

void registrarClientes(Gestor &gestor)
{
	 
	string nombre;
	string direccion;
	string numeroContacto;
	static int id = 0;
	string finalizar;
	   
		cout << "Ingrese nombre: ";
		getline(cin, nombre);
		cout << "\n";
		cout << "Ingrese direccion: ";
		getline(cin, direccion);
		cout << "\n";
		cout << "Ingrese numero: ";
		getline(cin, numeroContacto);
		cout << "\n";

		id++;
		Cliente cliente = Cliente(nombre, id, direccion, numeroContacto);//creando cliente

		gestor.agregarCliente(cliente);//agregando al registro


		cout << "Desea continuar, si o no?" << endl;
		getline(cin, finalizar);
		if (finalizar != "no")//se pregunta si se quiere seguir,  si es diferente de no entonces se llama el metodo recursivamente para ingregar otro cliente 
		{ 
			registrarClientes(gestor);
		}
		else
		{
			limpiarPantalla();
		}  
}

void menuPrincipal(Gestor &gestor)
{
	
	int eleccion = -1;
	cout << "Elige que deseas hacer \n1-Registrar clientes\n2-Modificar o eliminar clientes"
		 "\n3-Usar metodo recursivo\n4-Mostrar todos los clientes registrados\notra tecla para salir...\n"; 
	cin >> eleccion;
	
	cout << "\n";
	switch (eleccion)
	{
		
	case 1: //para registrar los clientes
		cin.ignore(numeric_limits<streamsize>::max(), '\n');// estaba teniendo un error con los cin y getline y tuve que usar esto que ignora el caracter "\n" que deja cin
		registrarClientes(gestor);
		limpiarPantalla();
		menuPrincipal(gestor);
		break;
	case 2: //para eliminar o modificar
		modificarOEliminarCliente(gestor);
		limpiarPantalla();
		menuPrincipal(gestor);
		break;
	case 3://usamos el metodo recursivo para contar
		cout<<"La cantidad de clientes registrados es: "<<gestor.contadorDeClientes(&gestor)<<"\n"; 
		menuPrincipal(gestor);
		break;
	case 4://mostramos todos los clientes y todos sus datos
		gestor.mostrarAllInfoClientes();
		menuPrincipal(gestor);
		break;
	default:

		break;
	}
}



int main()
{
	Gestor gestor;

	menuPrincipal(gestor);
	 
	return 0;
}