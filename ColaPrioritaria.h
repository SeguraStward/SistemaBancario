#pragma once
#include <iostream>
#include <string>
#include "Nodo.h"

using namespace std;

template <typename T>
class ColaPrioritaria {
 
    Nodo<T>* frente;

public:
    ColaPrioritaria() : frente(nullptr) {}

    ~ColaPrioritaria() {
        while (frente != nullptr) {
            Nodo<T>* temp = frente;
            frente = frente->next;
            delete temp;
        }
    }
    //dato const para poder agregar "A" ...
    void insertar(const T dato, int prioridad) {
        Nodo<T>* nuevo = new Nodo<T>(dato);
        nuevo->prioridad = prioridad;
        if (frente == nullptr || prioridad > frente->prioridad) {//se desplaza frente si se cumple la condicion porque llego uno con mayor prioridad
            nuevo->next = frente;
            frente = nuevo;
        }
        else {  
            Nodo<T>* actual = frente;
            while (actual->next != nullptr && prioridad <= actual->next->prioridad) { //si resulta que frente tenia mayor prioridad ahora se chequean los demas, el ciclo stops
                //cuando se encuentra que el nuevo tiene mayor prioridad que el que sigue en la lista
                actual = actual->next;
            }
            nuevo->next = actual->next;//ahora se hace el ajuste colocando el que tiene mayor prioridad delante del que es siguiente al actual y colocando el nuevo como el siguiente de actual
            actual->next = nuevo;
        }
    }

    T extraer() {
        if (estaVacia()) {
            throw runtime_error("cola vacia, en metodo extraer");
        }

        Nodo<T>* temp = frente;
        T valor = temp->dato;
        frente = frente->next;
        delete temp;
        return valor;
    }

    bool estaVacia() const {
        return frente == nullptr;
    }

    void imprimir() const {
        if (estaVacia()) {
            cout << "cola vacia, imprimiendo\n";
            return;
        }
        Nodo<T>* actual = frente;
          cout << "Cola prioritaria (Prioridad: Dato): ";
        while (actual != nullptr) {
            cout << "(" << actual->prioridad << ": " << actual->dato << ") ";
            actual = actual->next;
        }
         cout << "\n";
    }


void probarColaPrioritaria() {
    ColaPrioritaria<string> cp;

    cp.insertar("A", 3);
    cp.insertar("N", 1);
    cp.insertar("D", 5);
    cp.insertar("B", 2);
    cp.insertar("V", 4);
    cp.imprimir();

     cout << "Extrayendo:\n";
    while (!cp.estaVacia()) {
         cout << cp.extraer() << "\n";
    }

    try {
        cp.extraer();
    }
    catch (const runtime_error& e) {
          cerr << "excepcion capturada: " << e.what() << "\n";
    }

    cp.imprimir();
}
};