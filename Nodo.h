#pragma once

template <typename T>
class Nodo {
public:
	T dato;
	int prioridad;
	Nodo<T>* next;
	Nodo(T valor) :dato(valor), next(nullptr), prioridad(0) {}
};