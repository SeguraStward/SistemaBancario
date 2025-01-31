#pragma once
#include "Pila.h"
#include "Transaccion.h"


class Cuenta
{
	int numeroDeCuenta;
	int idDelCliente;
	int saldo; 
	Pila<Transaccion> historialReciente;
public:
	Cuenta()
	{
		numeroDeCuenta = 0;
		idDelCliente = 0;
		saldo = 0;
		 
	}
	Cuenta(int numOfAccount, int idCliente, int monto)
	{
		numeroDeCuenta = numOfAccount;
		idDelCliente = idCliente;
		saldo = monto;
	}

	int getIdDelCliente()
	{
		return idDelCliente;
	}

	int getNumeroDeCuenta()
	{
		return numeroDeCuenta;
	}

	int getSaldo()
	{
		return saldo;
	}

	void setSaldo(int nuevo)
	{
		saldo = nuevo;
	}

	void agregarAHistorial(Transaccion& transaccion)
	{
		historialReciente.empilar(transaccion);
	}

	void imprimirCuenta()
	{
		cout << "-----------------------------------------------------\n";
		cout << "Informacion de la cuenta:\n";
		cout << "Numero de cuenta: " << numeroDeCuenta << "\n";
		cout << "Id del cliente: " << idDelCliente << "\n";
		cout << "Saldo actual: " << saldo << "\n";
		cout << "-----------------------------------------------------\n";
	}

	Pila<Transaccion>* getPila()
	{
		return &historialReciente;
	}

};
