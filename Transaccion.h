#pragma once
#include <string>
#include <iostream>
using namespace std;

class Transaccion
{
	int idTransaccion;
	int numeroDeCuenta;
	int cuentaDestino;
	string tipoDeOperacion;
	string estado;
	string fecha;
	string hora;
	string tipo;
	int monto;
public:
	Transaccion()
	{
		tipoDeOperacion = "";
		estado = "pendiente";
		fecha = "";
		hora = "";
		tipo = "";
		monto = 0;
		numeroDeCuenta = 0;
		cuentaDestino = 0;
		idTransaccion = 0;
	}

	Transaccion(string operacion, string state, string date, string time, int cuantity, int numAccount, int receptor, int idTransaction)
	{
		idTransaccion = idTransaction;
		tipoDeOperacion = operacion;
		estado = state;
		fecha = date;
		hora = time;
		monto = cuantity;
		numeroDeCuenta = numAccount;
		cuentaDestino = receptor;
		if (cuantity >= 10000000)
		{
			tipo = "prioritaria";
		}
		else
		{
			tipo = "normal";
		} 
	}
	Transaccion(const Transaccion& other)
		: tipoDeOperacion(other.tipoDeOperacion), estado(other.estado), fecha(other.fecha),
		hora(other.hora), tipo(other.tipo), monto(other.monto),
		numeroDeCuenta(other.numeroDeCuenta), cuentaDestino(other.cuentaDestino),
		idTransaccion(other.idTransaccion) {
	 
	}
	int getNumeroDeCuenta() { return numeroDeCuenta; }
	string getTipoDeOperacion() { return tipoDeOperacion; }
	string getEstado() { return estado; }
	string getFecha() { return fecha; }
	string getHora() { return hora; }
	string getTipo() { return tipo; }
	int getMonto() { return monto; }
	int getIdTransaccion() { return idTransaccion; }
	int getCuentaDestino() { return cuentaDestino; }
	// Setters
	void setTipoDeOperacion(const string& operation) { tipoDeOperacion = operation; }
	void setEstado(const string& state) { estado = state; }
	void setFecha(const string& date) { fecha = date; }
	void setHora(const string& time) { hora = time; }
	void setTipo(const string& type) { tipo = type; }
	void setMonto(const int& cuantity) { monto = cuantity; }

	void imprimir() {
		cout << "------------------------------------------\n";
		cout << "Id de transaccion: " << idTransaccion << "\n"
			<< "Numero de cuenta: " << numeroDeCuenta << "\n"
			<< "Cuenta Destino: " << cuentaDestino << "\n"
			<< "Tipo de operacion: " << tipoDeOperacion << "\n"
			<< "Estado: " << estado << "\n"
			<< "Fecha: " << fecha << "\n"
			<< "Hora: " << hora << "\n"
			<< "Tipo: " << tipo << "\n"
			<< "Monto: " << monto << "\n"
			<< "------------------------------------------\n";
	}

};
