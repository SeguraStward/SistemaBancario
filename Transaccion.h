#pragma once
#include <string>
#include <iostream>
using namespace std;

class Transaccion
{
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
	}

	Transaccion(string &operacion, string &state, string &date, string &time, string &type, int &cuantity)
	{
		tipoDeOperacion = operacion;
		estado = state;
		fecha = date;
		hora = time;
		tipo = type;
		monto = cuantity;
	}

	string getTipoDeOperacion() const { return tipoDeOperacion; }
	string getEstado() const { return estado; }
	string getFecha() const { return fecha; }
	string getHora() const { return hora; }
	string getTipo() const { return tipo; }
	int getMonto() const { return monto; }

	// Setters
	void setTipoDeOperacion(const string& operation	) { this->tipoDeOperacion = operation; }
	void setEstado(const string& state) { this->estado = state; }
	void setFecha(const string& date) { this->fecha = date; }
	void setHora(const string& time) { this->hora = time; }
	void setTipo(const string& type) { this->tipo = type; }
	void setMonto(const int& cuantity) { this->monto = cuantity; }

	void imprimir() const {
		cout << "Tipo de operacion: " << tipoDeOperacion << " Estado: " << estado
			<< " Fecha: " << fecha << " Hora: " << hora << " Tipo: " << tipo
			<< " Monto: " << monto << endl;
	}
 
};
