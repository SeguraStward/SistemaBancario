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
		Nodo<T>* actual = head;
		while (actual != nullptr) {
			Nodo<T>* next = actual->next; 
			delete actual;
			actual = next;
		}
		head = nullptr;
		last = nullptr;
		size = 0;
	}
	//Para agregar una cuenta primero creo un nuevo nodo, este siempre va a ir de ultimo
	//para no utilizar un while al agregar al final utilice un nodo final en esta lista
	//por lo tanto el nodo que se inserte siempre va a ser el ultimo. El timpo y espacio son constantes ya que siempre realiza solo una operacion-> O(1)
	void abrirCuenta(Cuenta* cuenta)
	{
		Nodo<T>* nuevo	 = new Nodo<T>(nullptr, cuenta);
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
		  
		if(head->cuenta->getIdDelCliente() == idCliente)//si es la cabeza la que se va a eliminar
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
		while (actual != nullptr && actual->cuenta->getIdDelCliente() != idCliente)//se detendra cuando actual sea nulo o cuando la cuenta tenga el id que se busca
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
	void consultarCuenta(int idCliente)
	{
		if (head == nullptr)
		{
			cout << "Lista de cuentas vacia\n";
			return;
		}

		Nodo<T>* actual = head;

		if (head->cuenta->getIdDelCliente() == idCliente)//si es la cabeza la que se va a eliminar
		{
			 
			cout << "Cuenta eliminada exitosamente\n";
			return;
		}
		 
		while (actual != nullptr && actual->cuenta->getIdDelCliente() != idCliente)//se detendra cuando actual sea nulo o cuando la cuenta tenga el id que se busca
		{
			 
			actual = actual->next;
		}
		if (actual == nullptr)//si actual es null entonces no se encontro una cuenta con el id del cliente
		{
			cout << "No se encontro la cuenta con el id -> " << idCliente << "\n";
			return;
		}
		  
		cout << "Cuenta perteneciente al usuario con id -> " << idCliente << "\n";
		cout << "Informacion de la cuenta:\n";
		cout << "Numero de cuenta ->" << actual->cuenta->getNumeroDeCuenta()<<"\n";
		cout << "Saldo de la cuenta ->" << actual->cuenta->getSaldo() << "\n";


	}


};
