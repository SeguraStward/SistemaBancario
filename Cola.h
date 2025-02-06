#pragma once

#include <iostream>
#include <string>
#include "Nodo.h"
using namespace std;

template <typename T>
class Cola {
	Nodo<T>* firstOut;
		Nodo<T>* last;
public:
    
    Cola()
    {
        firstOut = nullptr;
        last = nullptr;
    }
    ~Cola() {  //para evitar fugas de memoria
        while (firstOut != nullptr) {
            Nodo<T>* temp = firstOut; 
            firstOut = firstOut->next;
            delete temp;
        }
    }

    void encolar(const T& dato) { 
        Nodo<T>* nuevo = new Nodo<T>(dato);

        if (vacia()) {
            firstOut = last = nuevo;
        }
        else {
            last->next = nuevo;
            last = nuevo;
        }
    }
  
    T desencolar() {
        if (vacia()) {
            throw runtime_error("Cola vacia");
        }

        Nodo<T>* temp = firstOut;
        T valor = temp->dato;  
        firstOut = firstOut->next;
        delete temp;

        if (firstOut == nullptr) { 
            last = nullptr;
        } 
        return valor;
    }

    bool vacia()
    {
        return firstOut == nullptr;
    }

    void probarCola(T datos[], int tamano) {
        Cola<T> miCola;
        cout << "encolando: ";
        for (int i = 0; i < tamano; ++i) {
            miCola.encolar(datos[i]);
            cout << datos[i] << " ";
        }
        cout << endl;

         cout << "desencolando: ";
        try {
            while (!miCola.vacia()) {
                 cout << miCola.desencolar() << " ";
            }
             cout << endl;

            miCola.desencolar(); // desencolando cuando ya esta vacia para ver la excepcion
        }
        catch (const runtime_error& e) {
           cerr << "exceptionnn: " << e.what() << endl;
        }
         cout << "\n----------------------------------\n";
    }
};