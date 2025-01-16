#pragma once

template <typename T>
class Nodo {
public:
	T dato;
	Nodo<T>* next;
	Nodo(T valor) :dato(valor), next(nullptr) {}
};