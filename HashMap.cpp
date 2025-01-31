#include "HashMap.h"
 
int HashMap::probe(string key)
{
	int index = static_cast<int>(hash(key));
	int i = 0;
	while (array[(index + i) % size] != "")i++;//buscamos un lugar vacio para la insercion, ya que hubo una colision antes

	return (index + 1) % size;
}
//esta funcion produce una distribucion uniforme de los valores reduciendo las colisiones 
unsigned long HashMap::hash(string key)//estoy usando jdb2 funcion hash creada por Daniel J. Bernstein, matematico, criptografo y programador, 
{ 
	unsigned long hash = 5381;//numero elegido por Bernstein
	for (char ch : key) {
		//(hash << 5) esto es un desplazamiento de 5 bits a la izquierda es igual (hash * 32)
		hash = ((hash << 5) + hash) + static_cast<int>(ch); 
	}
	return hash % size; 
}

void HashMap::insert(string key, string password)
{
	if(static_cast<float>(elements)/static_cast<float>(size) >= 0.5)//para evitar que se llene, evitamos problemas y la tabla se mantiene eficiente, es recomendado mantener el factor de carga igual o menor a 0.5 eso dice mi profesor indu
	{
		cout << "Tabla de passwords llena, no se puede insertar mas.\n";
		return;
	} 
	int index = static_cast<int>(hash(key));
	if (!array[index].empty())index = probe(key);// si el indice que nos dio el hash se encuentra ocupado hacemos el sondeo lineal nos desplazamos a la siguiente direccion

	array[index] = password;

	elements++;
}


bool HashMap::search(string key, string password)
{
	int index = static_cast<int>(hash(key));
	int i = 0;

	while (array[(index + i) % size] != password) {//Por si hubo una colision antes entonces hacemos el sondeo lineal, osea nos desplazamos al siguiente indice
		if (array[(index + i) % size] == "")return false;// si nos topamos con un valor vacio significa que el valor no esta en la tabla 
		i++;
	}
	//si el ciclo termino significa que el valor si se encontro entonces retornamos true, o sea el usuario ingreso la contrasena correcta
	return true;
}
 