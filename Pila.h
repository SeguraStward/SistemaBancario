#pragma once
 
#include <iostream>
#include "Nodo.h"


using namespace std;
 
template<typename T>
class Pila//LIFO -> Last in first out
{
	Nodo<T>* frente;

public:
	Pila()
	{
		frente = nullptr;
	}
	~Pila() { //destructor para evitar fugas de memoria 
		while (frente != nullptr) {
			Nodo<T>* temp = frente;
			frente = frente->next;
			delete temp;  
		}
	}

	void empilar(T& dato)
	{ 
		Nodo<T>* nuevo = new Nodo<T>(dato); 
		nuevo->next = frente;
		frente = nuevo;
	}

	bool vacia()
	{
		return frente == nullptr;
	}
	 
	T desempilar() {  
		if (vacia()) {
			throw runtime_error("Pila vacia");
		}
		Nodo<T>* temp = frente;
		T valor = temp->dato;  
		frente = frente->next;
		delete temp;
		return valor; 
	}

	void probarPila(T datos[], int tamano) {
		Pila<T> miPila;
		 cout << "desempilando: ";
		for (int i = 0; i < tamano; ++i) {
			miPila.empilar(datos[i]);
			 cout << datos[i] << " ";
		}
		 cout << endl;

		 cout << "desempilando: ";
		try {
			while (!miPila.vacia()) {
				 cout << miPila.desempilar() << " ";
			}
			 cout << endl;
			miPila.desempilar(); // desempilando para probar
		}
		catch (const runtime_error& e) {
			 cerr << "excepcion al desempilar: " << e.what() << endl;
		}
		 cout << "----------------------------------\n";
	}


	void imprimirPila()
	{
		Nodo<T>* actual = frente;
		while (actual != nullptr) {

			actual->dato.imprimir();
			actual = actual->next;
		}
		cout << "Historial de transacciones de la cuenta mostrado.\n";
	}

	
};