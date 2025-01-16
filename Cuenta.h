#pragma once



class Cuenta
{
	int numeroDeCuenta;
	int idDelCliente;
	int saldo; 

public:
	Cuenta()
	{
		numeroDeCuenta = 0;
		idDelCliente = 0;
		saldo = 0;
		estado = false;
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
};