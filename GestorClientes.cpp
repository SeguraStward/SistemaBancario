#include "GestorClientes.h"

#include "Sorting.h"


Gestor::Gestor()
{
	size = 0;
	clientes = new Cliente[size];
}
Gestor::~Gestor()
{
	delete[] clientes;
	
}
Cliente* Gestor::getCliente(int id)
{

	for(int i = 0; i< size;i++)
	{
		if(clientes[i].getIdentificacion() == id)
		{
			return &clientes[i];
		}
	}

	return nullptr;
}



bool Gestor::agregarCliente(Cliente& nuevoCliente)
{
	if(nombreOcupado(nuevoCliente.getNombreCompleto()))
	{
		cout << "El nombre elegido para el cliente no esta disponible.\n";
		return false;
	}
	size++;
	Cliente* auxiliar = new Cliente[size];//creando un nuevo array dinamico con mayor size

	 int i = 0;
	 for(;i<size-1;i++)//tiempo O(n) se itera n veces y espacio O(n) tambien son n elementos
	 {
		 auxiliar[i] = clientes[i];
	 }
	 auxiliar[i] = nuevoCliente;
	  
	 delete[] clientes;//liberando memoria
	 clientes = nullptr; //desocupando direccion de memoria
	 clientes = auxiliar;//ahora clientes apunta a la misma direccion de auxiliar que es el vector actualizado
	 return true;
}

void Gestor::eliminarPrimero()
{
	if(size <= 0)
	{
		cerr << "No hay elementos para eliminar.";
		return;
	}
	size--;
	Cliente* auxiliar = new Cliente[size];

	for(int i = 0; i < size;i++)
	{
		auxiliar[i] = clientes[i+1];//se copian desde la posicion 1 del array de clientes entonces asi se evita copiar la posicion 0 
	}

	delete[] clientes;
	clientes = nullptr;
	clientes = auxiliar; 
}

void Gestor::eliminarUltimo()
{
	if (size <= 0)
	{
		cerr << "No hay elementos para eliminar.";
		return;
	}
	size--;
	Cliente* auxiliar = new Cliente[size];

	for (int i = 0; i < size; i++)//con la reduccion de size basta para no copiar el ultimo
	{
		auxiliar[i] = clientes[i];
	}

	delete[] clientes;
	clientes = nullptr;
	clientes = auxiliar;
}

void Gestor::eliminarCliente(int index)
{
	if (size <= 0)
	{
		cerr << "No hay elementos para eliminar.";
		return;
	}
	size--;
	Cliente* auxiliar = new Cliente[size];

	int j = 0;

	for (int i = 0; i < size; i++) 
	{
		if (i == index)j++; //la posicion que no se copiara se salta 
		auxiliar[i] = clientes[j];
	}

	delete[] clientes;
	clientes = nullptr;
	clientes = auxiliar;
}
 
void Gestor::mostrarClientes()
{
	for(int i= 0; i< size;i++)
	{
		cout << "Indice: " << i << " Cliente -> " << clientes[i].getNombreCompleto() << endl;
	}
	 
}

void Gestor::mostrarAllInfoClientes()
{
	for (int i = 0; i < size; i++)
	{
		cout <<" Cliente numero -> " << i<<"\n";
		cout <<" Identificacion -> " << clientes[i].getIdentificacion() << "\n";
		cout <<" Nombre completo -> " << clientes[i].getNombreCompleto() << "\n";
		cout <<" Direccion -> " << clientes[i].getDireccion() << "\n";
		cout <<" Numero de contacto-> " << clientes[i].getNumeroDeContacto() << "\n";
		cout <<"--------------------------------------------------------------\n";
	}
}


 //Con arrays dinamicos se debe tener un seguimiento de el tamanio del array
//por lo cual en lugar de pasar el array dinamico de clientes registrados
// paso el gestor, que contiene la lista de clientes registrados y que tambien tiene el tamanio del array
//y listo, utilizo el metodo recursivo para contar los clientes.
// Lo hice de esta forma por que no hay manera de averiguar el tamanio de un array dinamico ya que este tamanio se establece en tiempo de ejecucion
// y para contar necesito el tamanio maximo del array para no sobrepasar el limite
int Gestor::contadorDeClientes(Gestor* gestor)
{ 
	return recursiveMethod(1, gestor->getSize());
}

bool Gestor::nombreOcupado(string name)
{
	QuickSort(clientes, 0, size - 1);



	Cliente* cliente = binarySearch(name,0,size-1);
	if (cliente == nullptr)return false;


	return true;
}

Cliente* Gestor::binarySearch(string nombre, int l, int h)
{

	
	if (l <= h) {
		int mid = (h + l) / 2;//calculamos el medio
		if (clientes[mid].getNombreCompleto() == nombre)//si es el que buscamos entones retornamos
		{
			return &clientes[mid];
		}
		if (clientes[mid].getNombreCompleto() < nombre)//si el que buscamos es mayor del que esta en medio entonces buscamos en la mitad superior donde se encuentra valores mayor a mid
		{
			return binarySearch(nombre, mid+1, h);
		} //si no, significa que el valor que buscamos es menor a mid por lo cual se encuentra en la mitad inferior
		 	return binarySearch(nombre, l, mid - 1);  
	}
	
	return nullptr;
}

void Gestor::modificarCliente(int index)
{
	if (index < size && index >= 0)
	{ 
		cout << "Escriba el nuevo nombre del cliente: ";
		getline(cin, clientes[index].getNombreCompleto());
		cout << endl;

		cout << "Escriba la nueva direccion: ";
		getline(cin, clientes[index].getDireccion());
		cout << endl;

		cout << "Escriba el nuevo numero de contacto: ";
		getline(cin, clientes[index].getNumeroDeContacto());
		cout << "\n Listo, el usuario a sido modificado con exito! \n";

	}
 
	
}
// aqui esta el metodo para contar, recibe el minimo que es uno(siempre) y el maximo
// me inspire un poco en el pivote de quicksort, el tiempo de complejidad es de n/2 pero se toma solo encuenta n entonces es O(n)
//porque? pues porque tenemos n elementos y se van contando en pares o sea que no avanzamos 1 a 1 si no de dos en dos, por lo que si tenemos 6 elementos
// esta funcion se va a llamar 3 veces
// el espacio tambien es n/2 son las veces que esta funcion se almacena en la pila(stack) pero no se toman en cuenta los numeros por lo que es O(n)
//porque no se toman en cuenta los numeros? pues porque a medida que n crece esa division entre dos se vuelve insignificante
//Nos interesa el orden de crecimiento del tiempo de ejecucion o el espacio utilizado, no los valores exactos 
int Gestor::recursiveMethod(int min, int max)
{
	if (min > max)
	{
		return 0;
	}

	if (min == max) {
		return 1;
	}
	min++;
	max--;
	return 2 + recursiveMethod(min, max);
}