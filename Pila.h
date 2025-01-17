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
	~Pila() { //Destructor para evitar memory leaks
		Nodo<T>* actual = frente;
		while (actual != nullptr) {
			Nodo<T>* next = actual->next;
			actual->dato.~T();// llama al destructor por si el dato t tiene memoria asignada dinamicamente 
			delete actual;
			actual = nullptr;
			actual = next;
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

	T desempilar(){//retorna una referencia al dato T
		if (!vacia()) {
			return frente->dato;
		}
		cout << "Pila vacia\n"; 
	}

	void desempilarCritico() {
		if (!vacia()) {
			Nodo<T>* aux = frente;
			frente = frente->next;
			aux->dato.~T();
			delete aux;
			aux = nullptr;
			return;
		}
		cout << "Pila vacia\n"; 
	}

};