#include <chrono>
#include <iostream> 

#include "Cola.h"
#include "ColaPrioritaria.h"
#include "GestorClientes.h"
#include "ListaCuentas.h"
#include "Pila.h"
#include "SistemaBancario.h"
#include "Transaccion.h"

using namespace std;

  
void probarMergeSort(int n)//n la cantidad de datos que quiera ordena
{
	Gestor gestor;
	for (int i = n; i > 0; i--)
	{
		Cliente* cliente = new Cliente("aux", i, "fsdafs", "3424242"); 
		gestor.agregarCliente(*cliente);
	}

	//for (int i = 0; i < gestor.getSize(); i++)
	//{
	//	cout << "identificacion del cliente numero: " << i << "->" << gestor.getClientes()[i].getIdentificacion() << "\n";
	//}
	auto start = chrono::high_resolution_clock::now();
	RecursiveMergeSort(gestor.getClientes(), 0, gestor.getSize()-1);
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duration = end - start;
	cout << "____________________________________________\n";
	/*for (int i = 0; i < gestor.getSize(); i++)
	{
		cout << "identificacion del cliente numero: " << i << "->" << gestor.getClientes()[i].getIdentificacion() << "\n";
	}*/
	cout << "Tiempo de ejecucion de MergeSort: " << duration.count() << " ms\n";
}

void probarHeapSort(int n)//n la cantidad de datos que quiera ordena
{
	Gestor gestor;
	for (int i = n; i > 0; i--)
	{
		Cliente* cliente = new Cliente("aux", i, "fsdafs", "3424242");
		gestor.agregarCliente(*cliente);
	}

	//for (int i = 0; i < gestor.getSize(); i++)
	//{
	//	cout << "identificacion del cliente numero: " << i << "->" << gestor.getClientes()[i].getIdentificacion() << "\n";
	//}
	auto start = chrono::high_resolution_clock::now();
	HeapSort(gestor.getClientes(),gestor.getSize() - 1);
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duration = end - start;
	cout << "____________________________________________\n";
	/*for (int i = 0; i < gestor.getSize(); i++)
	{
		cout << "identificacion del cliente numero: " << i << "->" << gestor.getClientes()[i].getIdentificacion() << "\n";
	}*/
	cout << "Tiempo de ejecucion de HeapSort: " << duration.count() << " ms\n";
}

void probarQuickSort(int n)//n la cantidad de datos que quiera ordena
{
	Gestor gestor;
	for (int i = n; i > 0; i--)
	{
		Cliente* cliente = new Cliente("aux", i, "fsdafs", "3424242");
		gestor.agregarCliente(*cliente);
	}

	/*for (int i = 0; i < gestor.getSize(); i++)
	{
		cout << "identificacion del cliente numero: " << i << "->" << gestor.getClientes()[i].getIdentificacion() << "\n";
	}*/
	 
	auto start = chrono::high_resolution_clock::now(); 
	QuickSort(gestor.getClientes(), 0, gestor.getSize()-1);
	auto end = chrono::high_resolution_clock::now();  

	// Calcular la duracion en milisegundos
	 chrono::duration<double, milli> duration = end - start;

	
	cout << "____________________________________________\n";
	/*for (int i = 0; i < gestor.getSize(); i++)
	{
		cout << "identificacion del cliente numero: " << i << "->" << gestor.getClientes()[i].getIdentificacion() << "\n";
	}*/

	cout << "Tiempo de ejecucion de QuickSort: " << duration.count() << " ms\n";
}

void probarBubbleSort(int n)//n la cantidad de datos que quiera ordenar
{
	ListaCuentas<Cuenta> cuentas;
	for (int i = n; i > 0; i--)
	{
		Cuenta* cuenta = new Cuenta(1, i, i);
		cuentas.abrirCuenta(*cuenta);
	}

	/*for (int i = 0; i < cuentas.getSize(); i++)
	{
		cout << "Monto de la cuenta: " << i << "->" << cuentas.getNodo(i)->dato.getSaldo() << "\n";
	}*/
	auto start = chrono::high_resolution_clock::now();
	bubbleSort(cuentas);
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duration = end - start;
	cout << "____________________________________________\n";
	/*for (int i = 0; i < cuentas.getSize(); i++)
	{
		cout << "Monto de la cuenta: " << i << "->" <<  cuentas.getNodo(i)->dato.getSaldo() << "\n";
	}*/
	cout << "Tiempo de ejecucion de BubbleSort: " << duration.count() << " ms\n";
}
void probarInsertionSort(int n)//n la cantidad de datos que quiera ordenar
{
	ListaCuentas<Cuenta> cuentas;
	for (int i = n; i > 0; i--)
	{
		Cuenta* cuenta = new Cuenta(1, i, i);
		cuentas.abrirCuenta(*cuenta);
	}

	/*for (int i = 0; i < cuentas.getSize(); i++)
	{
		cout << "Monto de la cuenta: " << i << "->" << cuentas.getNodo(i)->dato.getSaldo() << "\n";
	}*/
	auto start = chrono::high_resolution_clock::now();
	insertionSort(cuentas);
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duration = end - start;
	cout << "____________________________________________\n";
	/*for (int i = 0; i < cuentas.getSize(); i++)
	{
		cout << "Monto de la cuenta: " << i << "->" << cuentas.getNodo(i)->dato.getSaldo() << "\n";
	}*/
	cout << "Tiempo de ejecucion de InsertionSort: " << duration.count() << " ms\n";
}
void probarSelectionSort(int n)//n la cantidad de datos que quiera ordenar
{
	ListaCuentas<Cuenta> cuentas;
	for (int i = n; i > 0; i--)
	{
		Cuenta* cuenta = new Cuenta(1, i, i);
		cuentas.abrirCuenta(*cuenta);
	}

	/*for (int i = 0; i < cuentas.getSize(); i++)
	{
		cout << "Monto de la cuenta: " << i << "->" << cuentas.getNodo(i)->dato.getSaldo() << "\n";
	}*/
	auto start = chrono::high_resolution_clock::now();
	selectionSort(cuentas);
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duration = end - start;
	cout << "____________________________________________\n";
	/*for (int i = 0; i < cuentas.getSize(); i++)
	{
		cout << "Monto de la cuenta: " << i << "->" << cuentas.getNodo(i)->dato.getSaldo() << "\n";
	}*/
	cout << "Tiempo de ejecucion de SelectionSort: " << duration.count() << " ms\n";
}
 
int main()
{
	 
	//Entregable 3

	//probe con 20 mil 10 mil 5 mil y 4 mil pero no me funciono se termina el programa
	//talvez se requiera cuantiosos elementos para que brillen los algoritmos que tienen tiempo de complejidad O(n log n)
	//me sorprendio insertionsort mucho 

	//probarQuickSort(2000);//0.1862 ms con 90 elementos; con 2000 elementos 7.8003 ms; con 3000 elementos 12.4636 ms
	//cout << "-------------------------------------\n";
	//probarBubbleSort(2000);//0.0933 ms con 90 elementos;  con 2000 elementos 46.5918 ms; con 3000 elementos 97.2895 ms
	//cout << "-------------------------------------\n";
	//probarHeapSort(2000);//0.6243 ms con 90 elementos; con 2000 elementos 17.8081 ms; con 3000 elementos 27.4459 ms
	//cout << "-------------------------------------\n";
	//probarMergeSort(2000);//2.8412 ms con 90 elementos; con 2000 elementos 1216.8 ms; con 3000 elementos  2932.96 ms
	//cout << "-------------------------------------\n";
	//probarSelectionSort(2000);//0.0364 ms con 90 elementos; con 2000 elementos 7.6234 ms; con 3000 elementos 17.7438 ms
	//cout << "-------------------------------------\n";
	//probarInsertionSort(2000);//0.0011ms con 90 elementos; con 2000 elementos 0.0088 ms; con 3000 elementos 0.0123 ms

	//Con 90 elementos 1-insertionsort 2-quicksort 3-selectionsort 4-bubblesort 5-heapsort
	//Con 2000 elementos 1-insertionsort 2-selectionsort 3-quicksort 4-heapsort 5-bubblesort 6-mergesort
	//Con 3000 elementos 1-insertionsort 2-quicksort 3-selectionsort 4-heapsort 5-bubblesort 6-mergesort

	 
	//entregable 4
	// Sistema bancario funcional
	//
 //   SistemaBancario sistema;
	//sistema.menuPrincipal(); 



	/*BST<int> tree;  Probando el arbol binario con int

	tree.insert(100);
	tree.insert(70);
	tree.insert(7);
	tree.insert(700);
	tree.insert(50);
	tree.insert(24);
	tree.insert(44);
	cout << "Preorden: ";
	tree.preorder(tree.getRoot());
	cout << "\nInOrden: ";
	tree.inorder(tree.getRoot());
	cout << "\nPostorden: ";
	tree.postorder(tree.getRoot());*/

	 

	return 0;
}