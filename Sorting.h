#pragma once
#include "Cliente.h"
#include "ListaCuentas.h"


void swap(Cliente& a, Cliente& b) noexcept;
void swapCuenta(Nodo<Cuenta>* nodo1, Nodo<Cuenta>* nodo2);

void bubbleSort(ListaCuentas<Cuenta>& cuentas);
void insertionSort(ListaCuentas<Cuenta>& cuentas);
void selectionSort(ListaCuentas<Cuenta>& cuentas);

void Merge(Cliente A[], int low, int mid, int high);

void RecursiveMergeSort(Cliente A[], int low, int high);


int partition(Cliente A[], int low, int high);

void QuickSort(Cliente A[], int low, int high);
 
//Heap sort
void Insert(Cliente A[], int n);
 
Cliente Delete(Cliente clientes[], int n);
 

void HeapSort(Cliente clientes[], int n);

 