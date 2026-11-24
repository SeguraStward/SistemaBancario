#include "HashMap.h"

// Sondeo lineal: desde el indice que da el hash avanzamos de uno en uno
// hasta encontrar una casilla vacia o la casilla que ya tiene esta misma llave.
int HashMap::probe(string key)
{
	int index = static_cast<int>(hash(key));
	int i = 0;
	while (!keys[(index + i) % size].empty() && keys[(index + i) % size] != key) i++;

	return (index + i) % size;
}

// djb2: funcion hash de Daniel J. Bernstein. Produce una distribucion uniforme y reduce las colisiones.
unsigned long HashMap::hash(string key)
{
	unsigned long hash = 5381; // numero elegido por Bernstein
	for (unsigned char ch : key) {
		// (hash << 5) es un desplazamiento de 5 bits a la izquierda, igual que (hash * 32)
		hash = ((hash << 5) + hash) + ch;
	}
	return hash % size;
}

void HashMap::insert(const string key, const string password)
{
	// Mantenemos el factor de carga en 0.5 o menos para que la tabla siga siendo eficiente.
	if (static_cast<float>(elements) / static_cast<float>(size) >= 0.5f)
	{
		cout << "Tabla de passwords llena, no se puede insertar mas.\n";
		return;
	}

	int index = probe(key);
	if (keys[index].empty()) elements++; // llave nueva; si ya existia solo se actualiza la contraseña

	keys[index] = key;
	array[index] = password;
}

// Retorna true solo si existe esa llave y su contraseña coincide.
bool HashMap::search(string key, string password)
{
	int index = static_cast<int>(hash(key));

	for (int i = 0; i < size; i++) {
		int actual = (index + i) % size;
		if (keys[actual].empty()) return false;            // casilla vacia: la llave no esta en la tabla
		if (keys[actual] == key) return array[actual] == password;
	}
	return false;
}
