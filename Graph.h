#pragma once
#include "Cola.h"
#define I 3000

class Grafo
{
	int** matrix;//matriz de adyacencia
	int size;//size de la matriz
	string* sucursales;//array de los nombres de las sucursales
	int** edges;//matriz donde se guardaran el resultado de aristas de los algoritmos prim y kruskal
	int edgesSize;//size de aristas para kruskal
	int** edgesK;//aristas para kruskal fila 0 origen fila 1 destino y fila 2 costo
public:

	Grafo(int lenght) :size(lenght)
	{
		// Inicializar la matriz de adyacencia con infinito
		//matrix = new int* [size];
		//for (int i = 0; i < size; i++) {
		//	matrix[i] = new int[size];
		//	for (int j = 0; j < size; j++) {
		//		matrix[i][j] = I; // Costo 0 en la diagonal, INF en el resto
		//	}
		//}

		//// Inicializar nombres de sucursales
		//sucursales = new string[size]{ "A", "B", "C", "D", "E" }; // Puedes cambiarlo

		//// Definir algunas conexiones de ejemplo
		//agregarArista(0, 1, 10);
		//agregarArista(0, 3, 30);
		//agregarArista(0, 4, 100);
		//agregarArista(1, 2, 50);
		//agregarArista(2, 4, 10);
		//agregarArista(3, 2, 20);
		//agregarArista(3, 4, 60);

		//edgesSize = 7;

	}

	/*~Grafo() {
		 
		for (int i = 0; i < size; i++) {
			delete[] matrix[i];
		}
		delete[] matrix;

		for (int i = 0; i < 2; i++) {
			delete[] edges[i];
		}
		delete[] edges;

		for (int i = 0; i < 3; i++) {  
			delete[] edgesK[i];
		}
		delete[] edgesK;
		delete[] sucursales;
	}*/
	void crearMatriz();
	void crearSucursales();
	void BFS(int origen);
	void DFS(int origen, int visitados[]);
	void kruskal();
	void prim();
	void imprimirMST();
	void imprimir();
	void agregarArista(int origen, int destino, int costo);
	void establecerAristas();
	void imprimirSucursales();
	void crearEdgesK();//para crear la matriz ordenada de aristas por origen que se usara en kruskal
	void imprimirKruskal();
};
