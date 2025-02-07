#include "Graph.h"

#include <iomanip>

#include "SistemaBancario.h"




void Grafo::crearMatriz()
{
	matrix = new int* [size];//matriz del grafo 

	for (int i = 0; i < size; i++)
	{
		matrix[i] = new int[size];
		for (int j = 0; j < size; j++)
		{
			matrix[i][j] = I;
		}
	}
 

}
void Grafo::crearSucursales()
{ 

	cout << "Elige la cantidad de sucursales que deseas abrir.\n";
	size = leerNumero();

	if (size < 3)
	{
		cout << "La cantidad minima de sucursales es 3, ingresa un numero mayor.\n";
		return crearSucursales();
	}
	sucursales = new string[size];
	crearMatriz(); 
	for (int i = 0; i < size; i++)
	{
		string sucursal;
		cout << "Escribe el nombre de la sucursal numero: " << i << "\n";
		getline(cin, sucursal);
		sucursales[i] = sucursal;
	}

}

void Grafo::BFS(int origen)
{
	Cola<int> cola;
	int a = origen;

	int* visitados = new int[size];
	for (int i = 0; i < size; i++)
	{
		visitados[i] = 0;
	}
	visitados[a] = 1;//marcamos como visitado el nodo origen
	cola.encolar(a);//lo encolamos
	cout << " raiz -> " << a;
	while (!cola.vacia())// repetimos <------------------------------------------------------------------------------- <-                  jajaj
	{
		a = cola.desencolar();//desencolamos el nodo                                                                    ^
		for (int j = 0; j < size; j++)
		{
			if (matrix[a][j] != I && visitados[j] == 0)//visitamos los nodos vecinos que no hayan sido visitados          ^
			{
				cout << " -> " << j;//imprimimos                                                                          ^


				visitados[j] = 1;//marcamos como visitado
				cola.encolar(j);//lo encolamos para visitar sus vecinos despues                                         ^
			}
		}
	}//>--------------------------------------------------------------------------------------------------------------->^


}
void Grafo::DFS(int origen, int visitados[])
{
	if (visitados[origen] == 0)//si no ha sido visitado entonces entra
	{
		cout << origen << " -> ";
		visitados[origen] = 1;//se marca como visitado

		for (int j = 0; j < size; j++)
		{    //si existe un costo y el nodo j no ha sido visitado entonces se llama recursivamente
			//y se repite el proceso yendo en profundidad por los nodos
			if (matrix[origen][j] != I && visitados[j] == 0)

				DFS(j, visitados);
		}
	}
}
//uniendo dos conjuntos
//ejemplo [ -1, -1] voy a unir estos dos conjuntos
//u=0 v=1, pasamos por los if y vemos que son iguales entonces tomaremos el v como padre
//s[v] pasa a ser -2 y s[u] pasa a ser 1(indice del padre)
void Union(int u, int v, int s[]) {
	if (s[u] < s[v]) {
		s[u] += s[v];
		s[v] = u;
	}
	else {
		s[v] += s[u];
		s[u] = v;
	}
}
//encuentra el padre en el conjunto
//ejemplo: [ -1, 3, 3, -2 ] el indice 1 y 2 tienen como valor 3 ese valor representa el indice del padre al que pertenecen
//y el indice 3 contiene el -2, el - indica que es un conjunto y numero la cantidad de valores que tiene ese conjunto
int encontrarPadre(int u, int s[]) {
	int x = u;
	int v;

	while (s[x] > 0) {
		x = s[x];
	}

	while (u != x) {
		v = s[u];
		s[u] = x;
		u = v;
	}
	return x;
}

void Grafo::kruskal()
{

	 //lleva un seguimiento de las aristas, las que ya estan dentro de la solucion(true) y las no(false)
	bool* track = new bool[edgesSize]; 
	 for(int i = 0; i< edgesSize; i++)
	 {
		 track[i] = false;
	 }
	// array para encontrar ciclos, conjunto se inicializa con -1 indicando que cada indice es un conjunto
	int* set = new int[size];
	for(int i = 0; i < size; i++)
	{
		set[i] = -1;
	}

	//aqui se guardara la solucion(el camino)
	edges = new int* [2]; 
	for (int i = 0; i < 2; i++) {
		edges[i] = new int[size - 1];
		
		for (int j = 0; j < size - 1; j++)
		{
			edges[i][j] = 0;
		}
	}
	 
	int i = 0;
	while (i < size -1) {
		int min = I;
		int u = 0;
		int v = 0;
		int k = 0;

		// encontrando la arista con menor costo
		for (int j = 0; j < edgesSize; j++) {
			if (track[j] == false && edgesK[2][j] < min) {
				min = edgesK[2][j];
				u = edgesK[0][j];
				v = edgesK[1][j];
				k = j;
			}
		}

		// verificando que el padre de u y v no sea el mismo(que no haya ciclo)
		int padreU = encontrarPadre(u, set);
		int padreV = encontrarPadre(v, set);
		if (padreU != padreV) {
			edges[0][i] = u;
			edges[1][i] = v;
			Union(padreU, padreV, set);
			i++;
		}
		//se marca como incluido
		track[k] = true;
	}
	
	imprimirMST();

}

void Grafo::prim()
{
	int u = -1;
	int v = -1;
	int min = I;
	//llevara el seguimiento de el camino mas cercano entre vertices
	//se ira actualizando a medida que se encuentre un camino menos costoso
	int* track = new int[size];
	edges = new int* [2];// aqui se guardara la solucion

	for (int i = 0; i < 2; i++) {
		edges[i] = new int[size - 1];
		for (int j = 0; j < size - 1; j++)
		{
			edges[i][j] = 0;
		}
	} 

	//encontramos la arista con menor costo
	for (int i = 0; i < size; i++) {
		track[i] = I;  // inicializamos el array de seguimiento en infinito
		for (int j = i; j < size; j++) {//aqui recorremos la matriz buscando la arista con menor costo
			if (matrix[i][j] < min) {//si el nodo i y el nodo j tienen un peso de 3 y el minimo era 4 entonces entra el if
				//y aqui se asigna a min el nuevo costo minimo y se asignan u y v como los nodos de la arista de menor costo
				min = matrix[i][j];
				u = i;
				v = j;
			}
		}
	}
	edges[0][0] = u;//agregamos los nodos que estan enlazados con la arista de menor costo
	edges[1][0] = v;//
	track[u] = track[v] = -1;//los establecemos como visitados en el array de seguimiento

	//ahora buscamos los nodos adyacentes a (u y v) y vamos colocando a cual de estos nodos es mas cercano el tercer nodo que se esta evaluando con (u y v) en este caso el nodo es i
	for (int i = 1; i < size; i++) {
		if (track[i] != -1) {

			if (matrix[i][u] < matrix[i][v]) {
				track[i] = u;
			}
			else {
				track[i] = v;
			}
		}
	}

	//ahora sigue el proceso repetitivo hasta lograr el mst
	for (int i = 1; i < size - 1; i++) {
		int k = -1;
		min = I;
		for (int j = 1; j < size; j++) {
			//si track[j] no es cero o sea que no es un nodo visitado
			//entonces evaluamos el nodo j con el nodo 
			if (track[j] != -1 && matrix[j][track[j]] < min) {
				//buscamos cual nodo tiene el menor costo que no ha sido visitado y es cercano a los ya visitados
				k = j;
				min = matrix[j][track[j]];
			}
		}
		if (k != -1) {
			edges[0][i] = k;//se encontro el nodo k que es el nodo que era adyacente y tenia el menor coste
			edges[1][i] = track[k];//este nodo era ya uno visitado
			track[k] = -1;// nodo k se establece como visitado en en el array traking
			for (int j = 1; j < size; j++) {//se actualiza el array tracking por el nuevo nodo visitado que es k, se ve si el costo de entre
				//el nodo cambiante j y el nuevo nodo visitado k es menor al costo del nodo cambiante j y el nodo que estaba anteriormente, si es menor
				//el array tracking es actualizado pues entre el nodo k y j hay un costo menor que en el nodo j y el que estaba anteriormente en el array tracking 
				if (track[j] != -1 && matrix[j][k] < matrix[j][track[j]]) {
					track[j] = k;
				}
			}
		}
		
		
	} 
	imprimirMST();
}

void Grafo::imprimirMST() {\
 
	cout << "\nMinimum spanning tree con aristas y costo\n";
	int sum = 0;
	for (int i = 0; i < size - 1; i++) {
		int costo = matrix[edges[0][i]][edges[1][i]];
		cout << "( " << sucursales[edges[0][i]] << "< --- >" << sucursales[edges[1][i]] << " ) costo: " << costo << "\n";
		sum += costo;
	}
	cout << "\n";
	cout << "Costo total: " << sum << "\n";

}

void Grafo::agregarArista(int origen, int destino, int costo)
{
	if (origen != destino) {
		matrix[origen][destino] = costo;
		matrix[destino][origen] = costo;
	}
	else {
		cout << "No se permite que un nodo tenga un camino hacia si mismo...\n";
	}
}

void Grafo::establecerAristas()
{

	int origen, destino, costo;
	char continuar;

	do {

		imprimir();
		cout << "\nIngrese el numero de la sucursal de origen: ";
		cin >> origen;

		cout << "Ingrese el numero de la sucursal de destino: ";
		cin >> destino;

		cout << "Ingrese el costo entre " << sucursales[origen] << " y " << sucursales[destino] << ": ";
		cin >> costo;

		agregarArista(origen, destino, costo);
		edgesSize++;//aumentando size de las aristas para kruskal
		cout << "Desea agregar una conexion? (s/n): ";
		cin >> continuar;
		limpiarPantalla();
	} while (continuar == 's' || continuar == 'S');

	cout << "Costos actualizados correctamente.\n";
	crearEdgesK();
	imprimir();
}

void Grafo::imprimirSucursales()
{
	cout << "Lista de sucursales:\n";
	cout << setw(10) << " ";
	for (int i = 0; i < size; i++) {
		cout << setw(10) << sucursales[i];
	}
	cout << "\n";
}

void Grafo::crearEdgesK()
{

	edgesK = new int*[3];

	for (int i = 0; i < edgesSize; i++)//creacion de la matriz de aristas para kruskal
	{
		edgesK[i] = new int[edgesSize];
	}
	//recorremos la matriz de 0 a n y como vamos en orden la matriz de edgesK
	//quedara ordenada de una sola vez para poder ser utililizada en kruskal
	int k = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size; j++)
		{
			if (matrix[i][j] != I)//verificamos que haya un costo y entonces colocamos la arista en el array
			{
				edgesK[0][k] = i;
				edgesK[1][k] = j;
				edgesK[2][k] = matrix[i][j];
				k++;
			}
		}
	}

}

void Grafo::imprimirKruskal()
{

	cout << "\nMinimum Cost Spanning Tree Edges\n";
	for (int i = 0; i < size - 1; i++) {
		cout << "[" << edges[0][i] << "]-----[" << edges[1][i] << "]\n";
	}
	cout <<"\n";

}

void Grafo::imprimir() {

	imprimirSucursales();
	for (int i = 0; i < size; i++) {
		cout << setw(10) << sucursales[i];
		for (int j = 0; j < size; j++) {
			cout << setw(10) << matrix[i][j];
		}
		cout << "\n";
	}
}
