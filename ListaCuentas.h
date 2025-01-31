#pragma once
#include <iostream>

#include "Cuenta.h"
#include "Nodo.h"
using namespace std;

template<typename T>
class ListaCuentas
{
	Nodo<T>* head;
	Nodo<T>* last;
	int size;
public:
	ListaCuentas()
	{
		head = nullptr;
		last = nullptr;
		size = 0;
	}
	~ListaCuentas() {
		 
		while (head != nullptr) {
			Nodo<T>* temp = head; 
			head = head->next; 
			delete temp;
		}
		head = nullptr;
		last = nullptr;
		size = 0;
	}
	//Para agregar una cuenta primero creo un nuevo nodo, este siempre va a ir de ultimo
	//para no utilizar un while al agregar al final utilice un nodo final en esta lista
	//por lo tanto el nodo que se inserte siempre va a ser el ultimo. El timpo y espacio son constantes ya que siempre realiza solo una operacion-> O(1)
	void abrirCuenta(Cuenta& cuenta)
	{
		Nodo<T>* nuevo = new Nodo<T>(cuenta);
		if(head == nullptr) 
		{ 
			head = nuevo; 
		}
		else
		{  
			last->next = nuevo; 
		}
		last = nuevo;
		size++;
		 
	}


	//Para cerrar cuenta pues entendi que era como eliminar un nodo de la lista entonces lo hice con el id del cliente
	//se busca de esa manera y se borra
	void cerrarCuenta(int idCliente)
	{
		 if(head == nullptr)
		 {
			  cout << "Lista de cuentas vacia\n";
			  return;
		 }

		 Nodo<T>* actual = head;
		  
		if(head->dato.getIdDelCliente() == idCliente)//si es la cabeza la que se va a eliminar
		{
			head = head->next;//movemos la cabeza
			delete actual;//eliminamos cabeza anterior

			if(head == nullptr)//si la cabeza queda null entonces no hay elementos y colocamos last como null 
			{
				last = nullptr;
			}
			size--;
			cout << "Cuenta eliminada exitosamente\n";
			return;
		}
		Nodo<T>* previo = nullptr;
		while (actual != nullptr && actual->dato.getIdDelCliente() != idCliente)//se detendra cuando actual sea nulo o cuando la cuenta tenga el id que se busca
		{
			previo = actual;
			actual = actual->next;
		}
		if(actual == nullptr)//si actual es null entonces no se encontro una cuenta con el id del cliente
		{
			cout << "No se encontro la cuenta con el id -> " << idCliente << "\n";
			return;
		}
		previo->next = actual->next; //vinculamos los nodos que estan a la par del nodo que se quiere eliminar

		if(actual == last)//si el nodo a eliminar es el ultimo entonces colocamos el previo como el ultimo
		{
			last = previo;
		}
		delete actual;//eliminamos actual
		actual = nullptr;
		size--;
		cout << "Cuenta eliminada exitosamente\n";

	}
	T* consultarCuenta(int numeroDeCuenta, bool imprimir)
	{
		if (head == nullptr)
		{
			cout << "Lista de cuentas vacia\n";
			return nullptr;
		}

		Nodo<T>* actual = head;

		if (head->dato.getNumeroDeCuenta() == numeroDeCuenta) 
		{ 
			return &head->dato;
		}
		 
		while (actual != nullptr && actual->dato.getNumeroDeCuenta() != numeroDeCuenta)//se detendra cuando actual sea nulo o cuando la cuenta tenga el id que se busca
		{
			 
			actual = actual->next;
		}
		if (actual == nullptr)//si actual es null entonces no se encontro una cuenta con el id del cliente
		{
			cout << "No se encontro la cuenta con el numero de cuenta -> " << numeroDeCuenta << "\n";
			return nullptr;
		}
		if(imprimir)
		{
			cout << "-----------------------------------------------------\n";
			cout << "Cuenta perteneciente al usuario con id -> " << actual->dato.getIdDelCliente() << "\n";
			cout << "Informacion de la cuenta:\n";
			cout << "Numero de cuenta ->" << actual->dato.getNumeroDeCuenta() << "\n";
			cout << "Saldo de la cuenta ->" << actual->dato.getSaldo() << "\n";
			cout << "-----------------------------------------------------\n";
		}
		

		return &actual->dato;//se retorna la cuenta del usuario
	}


	void probarListaCuentas() {
		ListaCuentas<Cuenta> listaDeCuentas;
	 

		Cuenta* cuenta1 = new Cuenta(1, 1, 1000);
		Cuenta* cuenta2 = new Cuenta(2, 2, 2000);
		Cuenta* cuenta3 = new Cuenta(3, 3, 3000);

		listaDeCuentas.abrirCuenta(*cuenta1);
		listaDeCuentas.abrirCuenta(*cuenta2);
		listaDeCuentas.abrirCuenta(*cuenta3);

		cout << "tamanio de la lista -> " << listaDeCuentas.getSize() << "\n";

		listaDeCuentas.consultarCuenta(2,true);
		listaDeCuentas.cerrarCuenta(2);
		cout << "tamanio despues de borrar ->" << listaDeCuentas.getSize() << "\n";
		listaDeCuentas.consultarCuenta(2,true);

		listaDeCuentas.cerrarCuenta(1);
		listaDeCuentas.cerrarCuenta(3);

		cout << "tamanio despues de borrar todo ->" << listaDeCuentas.getSize() << "\n";

		try {
			listaDeCuentas.cerrarCuenta(4); // intenta borrar una cuenta que no existe
		}
		catch (const runtime_error& e) {
			cerr << " fallo al intentar borrar cuenta inexistente: " << e.what() << endl;
		}
	}

	int getSize()
	{
		return size;
	}


	Nodo<T>* getNodo(int index)
	{
		if(index > size && index < 0)
		{
			throw out_of_range("fuera de rango");
		}

		Nodo<T>* actual = head;
		int i = 0;
		while(actual != nullptr && index != i)
		{
			actual = actual->next;
			i++;
		}

		if(actual != nullptr)
		{
			return actual;
		}
		
		throw out_of_range("fuera de rango");
	}

	Nodo<T>* getHead()
	{
		if(head == nullptr)
		{
			cout << "Lista vacia\n";
		}
		return head;
	}

	void setHead(Nodo<T>* nodo)
	{
		head = nodo;
	}

	void imprimirCuentasDelUsuarioId(int id)
	{
		Nodo<T>* actual = head;
		if (head == nullptr)return;

		cout << "Cuentas del usuario con id: " << id<<"\n";
		while(actual != nullptr)
		{
		
			if(actual->dato.getIdDelCliente() == id)
			{
				actual->dato.imprimirCuenta();
			}
			actual = actual->next;
		}
	}

	void imprimirCuentasExcepto(int id)
	{
		Nodo<T>* actual = head;
		if (head == nullptr)return;

		cout << "Todas las cuentas a las que puedes realizar transferencias\n\n";
		while (actual != nullptr)
		{

			if (actual->dato.getIdDelCliente() != id)
			{
				cout << "Numero de cuenta: " << actual->dato.getNumeroDeCuenta() << "\n";
			}
			actual = actual->next;
		}
	}
	void imprimirCuentas()
	{
		Nodo<T>* actual = head;
		if (head == nullptr)return;

		cout << "Todas las cuentas a las que puedes realizar transferencias\n\n";
		while (actual != nullptr)
		{ 
			 cout <<"Id del cliente: "<<actual->dato.getIdDelCliente() <<" Numero de cuenta: " << actual->dato.getNumeroDeCuenta() << "\n";
			 actual = actual->next;
		}
	}
	 
};
