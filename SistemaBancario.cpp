#include "SistemaBancario.h"

#include <algorithm>
#include <chrono>
#include <thread>


void esperarTecla() {
	cout << "Presiona Enter para continuar..." <<flush;
	cin.get();  
}

void limpiarPantalla() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}


int leerNumero() {
	int numero;
	while (true) {
		cout << "Ingresa un numero:  ";
		cin >> numero;


		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Entrada invalida, ingresa numeros.\n";
		}
		else {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\n";
			return numero;
		}
	}
	
}

bool pedirSiONo() {
	string respuesta;

	while (true) {
		cout << "Ingrese 'si' o 'no': ";
		cin >> respuesta;

		ranges::transform(respuesta.begin(), respuesta.end(), respuesta.begin(), ::tolower);

		if (respuesta == "si") {
			return true;
		}
		if (respuesta == "no") {
			return false;
		}
		cout << "Entrada invalida, intente de nuevo\n";
	}
}


string obtenerFechaActual() {

	time_t tiempoActual = time(nullptr);
	tm fechaLocal = {};

	if (localtime_s(&fechaLocal, &tiempoActual) != 0) {
		return "Error al obtener la fecha";
	}
	char buffer[100];
	strftime(buffer, sizeof(buffer), "%Y-%m-%d", &fechaLocal);

	return string(buffer);
}

string obtenerHoraActual() {
	time_t tiempoActual = time(nullptr);
	tm horaLocal = {};

	if (localtime_s(&horaLocal, &tiempoActual) != 0) {
		return "Error al obtener la hora";
	}

	char buffer[100];
	strftime(buffer, sizeof(buffer), "%I:%M %p", &horaLocal);

	return string(buffer);
}

void SistemaBancario::menuPrincipal()
{
	int flag = 0;
	int eleccion;
	
	do
	{
		cout << "Elige que deseas hacer \n1-Registrar clientes\n2-Agregar Cuentas\n3-Modificar o eliminar clientes"
			"\n4-Usar metodo recursivo\n5-Mostrar todos los clientes registrados\n6-Deposito, retiro o transferencia bancaria\n7-BST opciones"
		"\n8-Ordenar\n9-manejar transacciones\n10-Mostrar cuentas de un usuario\nPara salir ingrese cualquier otra tecla\n";
		eleccion = leerNumero();
		switch (eleccion)
		{

		case 1: //para registrar los clientes 
			agregarClientes(); 
			break;
		case 2: 
			agregarCuentas(); 
			break;
		case 3: 
			eliminarEditarCliente();
			break;
		case 4: 
			cout << "La cantidad de clientes registrados es: " << gestor.contadorDeClientes(&gestor) << "\n";
			break;
		case 5:
			gestor.mostrarAllInfoClientes();
			 
			break;
		case 6:
			if (validarUsuario() != nullptr)
			{
				realizarTransaccion();
			}
			break;
		case 7:
			bstOpciones();
			break;
		case 8:
			ordenar();
			break;
		case 9:
			procesarTransacciones();
			break;
		 
		case 10:
			cuentasYTransacciones();
			break;
			default:
			flag = 2;
			break;
		}
		 
		esperarTecla();
		limpiarPantalla();
	}
	while (flag == 0);
	
}

void SistemaBancario::agregarClientes()
{
	string nombre;
	string direccion;
	string numeroContacto;
	static int id = 0;
	string finalizar;

	cout << "Ingrese nombre: ";
	getline(cin, nombre);
	cout << "\n";
	cout << "Ingrese direccion: ";
	getline(cin, direccion);
	cout << "\n";
	cout << "Ingrese numero: ";
	getline(cin, numeroContacto);
	cout << "\n";

	id++;
	Cliente cliente = Cliente(nombre, id, direccion, numeroContacto);//creando cliente

	gestor.agregarCliente(cliente);//agregando al registro


	cout << "Desea continuar, si o no?" << endl;
	getline(cin, finalizar);
	if (finalizar == "si")//se pregunta si se quiere seguir, si es diferente de si entonces se termina 
	{
		agregarClientes();
	}
	 
}

void SistemaBancario::agregarCuentas()
{
	  
	Cliente* cliente = validarUsuario();

	if (cliente == nullptr) {
		cout << "Cliente no encontrado.\n";
		return;
	}

	static int numOfAccount = 1;


	Cuenta cuenta(numOfAccount, idClienteActual, 5);
	cout << "------------------------------------------------------\n";
	cout << "Se le ha creado una cuenta al cliente ->" << "id: " << cliente->getIdentificacion() << "\nNombre: " << cliente->getNombreCompleto() << "\n";
	cout << "Numero de cuenta -> " << cuenta.getNumeroDeCuenta()<<"\n";
	cout << "------------------------------------------------------\n";
	cuentas.abrirCuenta(cuenta);

	numOfAccount++;
}
//el usuario selecciona una cuenta, elije el tipo de operacion y el monto para crear asi una transaccion que se procesara luego
void SistemaBancario::realizarTransaccion()//deposito, retiro o transferencia
{
	int cuenta = eleccionDeCuenta();
	int cuentaDestino = 0;
	int monto;
	string tipo = "";
	
	cout << "Retiro, deposito o transferencia? digite r, d o t\n";
	cin >> tipo;
	
	if (tipo != "r" && tipo != "d" && tipo != "t")
	{
		cout << "Entrada invalida\n"; 
	}
	else
	{ 
		if (tipo == "r") {
			tipo = "Retiro";
			cout << "Digite el monto que desea retirar.\n";
			monto = leerNumero();
		}
		else if(tipo == "d") {
			tipo = "Deposito";
			cout << "Digite el monto que desea depositar.\n";
			monto = leerNumero();
		}
		else
		{
			tipo = "Transferencia";
			cout << "Digite el monto que desea transfererir.\n";
			monto = leerNumero();
			cout << "Ahora digite el numero de la cuenta a la que desea transferir el dinero.\n";
		    cuentaDestino = eleccionDeCuentaDestino();
		}
		if (monto == 0) {
			cout << "no se puede hacer una transaccion sin dinero\n";
			return;
		}
		static int idTransaccion = 1;
		string fecha = obtenerFechaActual();
		string hora = obtenerHoraActual();
		Transaccion transaccion(tipo, "pendiente", fecha, hora, monto, cuenta, cuentaDestino,idTransaccion);

		transaccion.imprimir();
		historialGlobal.Insert(transaccion);
		if (transaccion.getTipo() == "prioritaria")
		{
			solicitudesPrioritarias.insertar(transaccion, transaccion.getMonto());
		}
		else
		{
			solicitudes.encolar(transaccion);
		}
		idTransaccion++;
		cout << "La transaccion ha sido creada, debe ser procesada \n";
		cout << "transaccion con id -> " << transaccion.getIdTransaccion()<<"\n";
	}
}
 
void SistemaBancario::ordenarCuentas()
{
	int seleccion;
	cout << "Elige el algoritmo para ordenar las cuentas.\n1-Bubblesort 2-insertionSort 3-selectionSort\n";
	seleccion = leerNumero();
	switch (seleccion)
	{
	case 1:
		bubbleSort(cuentas);
		cuentas.imprimirCuentas();
		break;
	case 2:
		insertionSort(cuentas);
		cuentas.imprimirCuentas();
		break;
	case 3:
		selectionSort(cuentas);
		cuentas.imprimirCuentas();
		break;
		default:
			cout << "Seleccion del algoritmo invalida.\n";
			break;
	}

}

void SistemaBancario::ordenarClientes()
{
	int seleccion;
	cout << "Elige el algoritmo para ordenar los clientes.\n1-Quicksort 2-Heapsort 3-Mergesort\n";
	seleccion = leerNumero();
	switch (seleccion)
	{
	case 1:
		QuickSort(gestor.getClientes(), 0, gestor.getSize()-1);
		gestor.mostrarClientes();
		break;
	case 2:
		HeapSort(gestor.getClientes(), gestor.getSize() - 1);
		gestor.mostrarClientes();
		break;
	case 3:
		RecursiveMergeSort(gestor.getClientes(),0, gestor.getSize() - 1);
		gestor.mostrarClientes();
		break;
	default:
		cout << "Seleccion del algoritmo invalida.\n";
		break;
	}
}

void SistemaBancario::eliminarEditarCliente()
{
	int indice;
	int choose;
	gestor.mostrarClientes();
	cout << "Ingrese el indice del cliente que desea modificar o eliminar.\n ";

	indice = leerNumero();
	 
	cout << "1-Modificar cliente  2-Eliminar cliente\n";
	choose = leerNumero();
	switch (choose)
	{
	case 1://caso 1 para modificar el cliente se valida el indice y se utiliza el metodo para modificar
		if (indice < gestor.getSize() && indice >= 0)
		{
			gestor.modificarCliente(indice);
		}
		else
		{
			cout << "Usuario no encontrado para editar\n";
		}
		break;
	case 2: //caso 2 igual que el uno solo que elimina el indice
		if (indice < gestor.getSize() && indice >= 0)
		{
			gestor.eliminarCliente(indice);
		}
		else
		{
			cout << "Usuario no encontrado para eliminar\n";
		}
		break;
	default:
		cout << "No elegiste una opcion valida...\n";
		break;
	}
}

Cuenta* SistemaBancario::validarCuenta(int id)
{
	return cuentas.consultarCuenta(id, false);
}

Cliente* SistemaBancario::validarUsuario()//para asegurar que el usuario exista
{
	cout << "\n-----------------------------------------\n";

	int id;
	cout << "Por favor ingresa tu id. \n";
	id = leerNumero();
	cout << "-----------------------------------------\n";
	Cliente* cliente = gestor.getCliente(id);

	if (cliente != nullptr)
	{
		cout << "Cliente encontrado\n";
		cout << "Bienvenido estimado " << cliente->getNombreCompleto() << "\n";
		idClienteActual = id;
		cout << "\n-----------------------------------------\n";
		return cliente;
	}
	cout << "Cliente no encontrado\n";
	cout << "\n-----------------------------------------\n";
	return nullptr;
}

int SistemaBancario::eleccionDeCuenta()
{
	cuentas.imprimirCuentasDelUsuarioId(idClienteActual);

	cout << "Ingrese el numero de cuenta de la cuenta que desea seleccionar.\n";
	int seleccion = leerNumero();


	return seleccion;
}

int SistemaBancario::eleccionDeCuentaDestino()
{
	cuentas.imprimirCuentasExcepto(idClienteActual);

	cout << "Ingrese el numero de cuenta de la cuenta destino.\n";
	int seleccion = leerNumero();


	return seleccion; 
}

void SistemaBancario::bstOpciones()//busca la transaccion por medio de su id y tambien muestra todas las transacciones con los recorridos 
{
	Node<Transaccion>* temp;
	int seleccion;
	cout << "Los recorridos mostraran todas las transacciones y todos sus datos.\n";
	cout << "1-Buscar transaccion 2-PreOrden 3-InOrden 4-PosOrden\n";
	seleccion = leerNumero();

	switch (seleccion)
	{
	case 1:
		cout << "Ingrese el id de la transaccion para buscar en el historialGlobal.\n";
		seleccion = leerNumero();

		temp = historialGlobal.Search(seleccion);
		if(temp != nullptr)
		{
			cout << "Transaccion encontrada.\n";
			temp->data.imprimir();
		}else
		{
			cout << "Transaccion no encontrada\n";
		}
		break;
	case 2:
		historialGlobal.preOrder(historialGlobal.getRoot());
		cout << "\nPreOrden listo.\n";
		break;
	case 3:
		historialGlobal.InOrder(historialGlobal.getRoot());
		cout << "\nInOrden listo.\n";
		break;
	case 4:
		historialGlobal.postOrder(historialGlobal.getRoot());
		cout << "\nPostOrden listo.\n";
		break;
	default:
		cout << "Seleccion no valida\n";
		break;
	}


}

void SistemaBancario::ordenar()//para ordenar las listas de cuentas o clientes
{
	int seleccion;
	cout << "Que quieres ordenar 1-clientes o 2-cuentas\n";
	seleccion = leerNumero();

	switch (seleccion)
	{
	case 1:
		ordenarClientes();
		break;
	case 2:
		ordenarCuentas();
		break;

	default:
		cout << "Seleccion invalida.\n";
		break;

	}


}

void SistemaBancario::procesarTransacciones()
{
	int seleccion;
	//manejando primero las solicitudes prioritarias, intenta procesarlas o las puede bloquear de una vez 
	while (!solicitudesPrioritarias.estaVacia())
	{
		Transaccion actual = solicitudesPrioritarias.extraer();//extrae de la cola prioritaria la transaccion con mayor prioridad 
		
		cout << "Transaccion prioritaria.\n";
		actual.imprimir();
		cout << "Deseas intentar procesarla o bloquearla? 1-procesar 2-bloquear\n";
		
		do//para que seleccione una opcion correcta
		{
			seleccion = leerNumero();
			if(seleccion == 1)
			{
				 if(actual.getTipoDeOperacion() == "Transferencia")//tipo transferencia entonces se dirige a hacer la transferencia o sea la transaccion tiene cuenta de origen y cuenta de destino
				 {
					 transferencia(actual);
				 }else//si no se va a por el deposito o retiro que es en una misma cuenta
				 {
					 depositoRetiro(actual);
				 }
			
			}else if(seleccion == 2)
			{
				actual.setEstado("Bloqueada");
				historialGlobal.replace(actual);//se actualiza en el bst
			}
		}
		while (seleccion != 1 && seleccion != 2); 
	}
	//despues se procesan las transacciones normales con un proceso igual
	while (!solicitudes.vacia())
	{
		Transaccion actual = solicitudes.desencolar();//desencolando la transaccion normal
		cout << "Transaccion normal.\n";
		actual.imprimir();
		cout << "Deseas intentar procesarla o bloquearla? 1-procesar 2-bloquear\n";

		do//para que seleccione una opcion correcta
		{
			seleccion = leerNumero();
			if (seleccion == 1)
			{
				if (actual.getTipoDeOperacion() == "Transferencia")
				{
					transferencia(actual);
				}
				else
				{
					depositoRetiro(actual);
				}

			}
			else if (seleccion == 2)
			{
				actual.setEstado("Bloqueada");
				historialGlobal.replace(actual);
			}
		} while (seleccion != 1 && seleccion != 2);
	}
}

bool SistemaBancario::transferencia(Transaccion transaccion)
{
	Cuenta* origen = validarCuenta(transaccion.getNumeroDeCuenta());
	Cuenta* destino = validarCuenta(transaccion.getCuentaDestino());

	if (!destino)//si el destino el null o sea falso entonces es porque la cuenta destino no existe y la transaccion se coloca como bloqueada
	{
		cout << "Transaccion bloqueada porque la cuenta destino es invalida.\n";
		transaccion.setEstado("Bloqueada");
		historialGlobal.replace(transaccion);
		return false;
	}
	if(!origen)//igualmente aqui con la cuenta origen
	{
		cout << "Transaccion bloqueada porque la cuenta origen es invalida.\n";
		transaccion.setEstado("Bloqueada");
		historialGlobal.replace(transaccion);
		return false;
	}


	if(origen->getSaldo() < transaccion.getMonto())//si las cuentas existen se evalua el monto de la cuenta de la que se va a sacar dinero para depositarlo en otra cuenta y si el monto de la cuenta es menor al que se desea transferir se bloquea porque es saldo insuficiente
	{
		cout << "Transaccion bloqueada porque la cuenta origen no tiene el saldo suficiente.\n";
		transaccion.setEstado("Bloqueada");
		historialGlobal.replace(transaccion);
		return false;
	}
	//si las cosas estan bien entonces se hace la operacion(transferencia)

	destino->setSaldo(destino->getSaldo() + transaccion.getMonto());
	origen->setSaldo(origen->getSaldo() - transaccion.getMonto());
	origen->agregarAHistorial(transaccion);//agregando la transaccion al historial de las cuentas
	destino->agregarAHistorial(transaccion);
	transaccion.setEstado("Procesada");
	historialGlobal.replace(transaccion);
	cout << "Transferencia exitosa.\n";
	return true;
}

void SistemaBancario::depositoRetiro(Transaccion transaccion)
{
	Cuenta* cuenta = validarCuenta(transaccion.getNumeroDeCuenta());

	if(cuenta == nullptr)//asegurando que la cuenta exista
	{
		cout << "Transaccion bloqueada porque la cuenta no existe.\n";
		transaccion.setEstado("Bloqueada");
		historialGlobal.replace(transaccion);
		return;
	}
	if(transaccion.getTipoDeOperacion() == "Deposito")
	{
		cuenta->setSaldo(cuenta->getSaldo() + transaccion.getMonto());//sumandole el monto de la transaccion al monto de la cuenta
		transaccion.setEstado("Procesada");
		historialGlobal.replace(transaccion);
		cout << "Deposito correctamente procesado.\n";
	}else if(transaccion.getTipoDeOperacion() == "Retiro")
	{
		if(transaccion.getMonto() > cuenta->getSaldo())//verificando que la cuenta tenga suficiente dinero
		{
			cout << "Transaccion bloqueada por que el monto a retirar supera el saldo de la cuenta.\n";
			transaccion.setEstado("Bloqueada");
			historialGlobal.replace(transaccion);
		}else//si esta la cuenta tienen suficiente dinero entonces se le hace el retiro y se actualiza en el bst
		{
			cuenta->setSaldo(cuenta->getSaldo() - transaccion.getMonto());
			transaccion.setEstado("Procesada");
			historialGlobal.replace(transaccion);
			cout << "Retiro exitoso.\n";
		}
	}
	cuenta->agregarAHistorial(transaccion);//se agrega al historial la transaccion 
	 
}

void SistemaBancario::cuentasYTransacciones()//para mostrar las cuentas y el historial de transacciones de la cuenta
{
	Cliente* cliente;
	int eleccion;
	cliente = validarUsuario();
	if (cliente != nullptr)
	{
		cuentas.imprimirCuentasDelUsuarioId(cliente->getIdentificacion());

	}
	cout << "Deseas ver el historial de transacciones de una cuenta?.\n";
	if (pedirSiONo())
	{
		cout << "Ingresa el numero de cuenta.\n";
		eleccion = leerNumero();
		Cuenta* cuenta = cuentas.consultarCuenta(eleccion, false);

		if (cuenta != nullptr)
		{
			if (cuenta->getIdDelCliente() == idClienteActual)
			{
				cuenta->getPila()->imprimirPila();
			}
			else
			{
				cout << "La cuenta no es del cliente actual.\n";
			}

		}
	}

}


