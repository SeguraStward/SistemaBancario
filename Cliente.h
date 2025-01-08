#pragma once
#include <iostream>
#include <string>
using namespace std;

class Cliente
{
	string nombreCompleto;
	int identificacion;
	string direccion;
	string numeroDeContacto;

public:
	Cliente(){}
	Cliente(const string& nombre, const int& id, const string& direccion, const string& numDeContacto)
	{
		nombreCompleto = nombre;
		identificacion = id;
		this->direccion = direccion;
		numeroDeContacto = numDeContacto;
	}

	string getNombreCompleto() const
	{
		return nombreCompleto;
	}

	int getIdentificacion() const
	{
		return identificacion;
	}

	string getDireccion() const
	{
		return direccion;
	}

	string getNumeroDeContacto() const
	{
		return numeroDeContacto;
	}

	void setNombreCompleto(const std::string& nuevoNombre)
	{
		nombreCompleto = nuevoNombre;
	}

	void setIdentificacion(const int& nuevoId)
	{
		identificacion = nuevoId;
	}

	void setDireccion(const std::string& nuevaDireccion)
	{
		direccion = nuevaDireccion;
	}

	void setNumeroDeContacto(const std::string& nuevoNumContacto)
	{
		numeroDeContacto = nuevoNumContacto;
	}

	void imprimir() const
	{
		cout << "Nombre: " << nombreCompleto << endl;
		cout << "ID: " << identificacion << endl;
		cout << "Dirección: " << direccion << endl;
		cout << "Número de contacto: " << numeroDeContacto << endl;
	}
};
