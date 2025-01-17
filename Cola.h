#pragma once

#include <iostream>
#include <string>
#include "Nodo.h"
using namespace std;

template <typename T>
class Cola {
	Nodo<T>* firstOut;
		Nodo<T>* lastOut;
public:
     
	bool vacia()
	{
		return firstOut == nullptr;
	}


    ~Cola() { // Destructor para evitar fugas de memoria
        while (firstOut != nullptr) {
            Nodo<T>* temp = firstOut;
            firstOut = firstOut->next;
            delete temp;
        }
    }

    void encolar(T& dato) { // Recibe una const referencia
        Nodo<T>* nuevo = new Nodo<T>(dato);

        if (vacia()) {
            firstOut = lastOut = nuevo;
        }
        else {
            lastOut->next = nuevo;
            lastOut = nuevo;
        }
    }

    bool vacia() const {
        return firstOut == nullptr;
    }

    T desencolar() {
        if (vacia()) {
            throw std::runtime_error("Error: Cola vacia. No se puede desencolar.");
        }

        Nodo<T>* temp = firstOut;
        T valor = temp->dato;  
        firstOut = firstOut->next;
        delete temp;

        if (firstOut == nullptr) { 
            lastOut = nullptr;
        } 
        return valor;
    }
};