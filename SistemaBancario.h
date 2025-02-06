#pragma once 
#include "BST.h"
#include "Cola.h"
#include "ColaPrioritaria.h"
#include "Cuenta.h"
#include "GestorClientes.h"
#include "ListaCuentas.h"
#include "Pila.h"
#include "Transaccion.h"
#include "Sorting.h"
#include <iostream> 

#include "HashMap.h"
using namespace std;

string obtenerHoraActual();
string obtenerFechaActual();
int leerNumero();
void limpiarPantalla();
class SistemaBancario
{
	ListaCuentas<Cuenta> cuentas;//se guardan todas las cuentas
	Gestor gestor;//todos los clientes estan aqui
	BST<Transaccion> historialGlobal;//todas las transacciones se encuentran en el arbol 
	Cola<Transaccion> solicitudes;//las transacciones normales iran aqui
	ColaPrioritaria<Transaccion> solicitudesPrioritarias;//transacciones prioritarias aqui
	int idClienteActual = 0;// id del cliente actual
	HashMap* passwords;
public:
	SistemaBancario()
	{
		passwords = new HashMap(100);
	}
	void menuPrincipal();//se seleccionara una operacion
	void agregarClientes();//se registran los clientes
	void agregarCuentas();//se le agrega una cuenta al cliente que ingrese su id
	void realizarTransaccion();// se crea una transaccion 
	void ordenarCuentas();
	void ordenarClientes();
	void eliminarEditarCliente();//elimina o modifica un cliente en especifico
	Cuenta* validarCuenta(int id); //valida la existencia de una cuenta y la retorna
	Cliente* validarUsuario();//valida la existencia de un usuario
	int eleccionDeCuenta();//muestra las cuentas del cliente actual y pide que seleccione una, una vez seleccionada retorna el numero de cuenta de la cuenta
	int eleccionDeCuentaDestino();//seleccion de cuenta para transferir dinero
	void bstOpciones();
	void ordenar();//ordenamientos
	void procesarTransacciones(); //para que el administrador procese o bloquee transacciones 
	bool transferencia(Transaccion transaccion);//accion de transferencia bancaria
	void depositoRetiro(Transaccion transaccion);//accion de deposito o retirno de dinero en una cuenta
	void cuentasYTransacciones();//muestra las cuentas y en caso de querer mostrar las transacciones de una cuenta especifica las muestra
	void procesarOBloquear(Transaccion actual);
};
