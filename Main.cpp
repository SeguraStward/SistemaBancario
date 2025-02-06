#include <chrono>
#include <iostream> 

#include "Cola.h"
#include "ColaPrioritaria.h"
#include "GestorClientes.h"
#include "Graph.h"
#include "HashMap.h"
#include "ListaCuentas.h"
#include "Pila.h"
#include "SistemaBancario.h"
#include "Transaccion.h"

using namespace std;
 
int main()
{
	/* 
     SistemaBancario sistema;
	 sistema.menuPrincipal(); 
		*/

	 
	Grafo g(5);
	g.crearSucursales();
	g.establecerAristas();
	g.prim();
    g.kruskal();
	g.BFS(0);
	 
	g.imprimir();

	g.BFS(0);
	int visited[5] = {0,0,0,0,0};

	cout << "\nDepth first search\n";
	g.DFS(0, visited);





	return 0;
}