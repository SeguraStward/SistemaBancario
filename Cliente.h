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
	Cliente()
	{
		nombreCompleto = "";
		identificacion = 0;
		direccion = "";
		numeroDeContacto = "";
	}
	Cliente(const string& nombre, const int& id, const string& direccion, const string& numDeContacto)
	{
		nombreCompleto = nombre;
		identificacion = id;
		this->direccion = direccion;
		numeroDeContacto = numDeContacto;
	}

	string &getNombreCompleto()
	{
		return nombreCompleto;
	}

	int getIdentificacion()
	{
		return identificacion;
	}

	string &getDireccion()
	{
		return direccion;
	}

	string &getNumeroDeContacto()
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
