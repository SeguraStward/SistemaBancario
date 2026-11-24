#include "SistemaBancario.h"

// Punto de entrada: abre el menú principal del sistema bancario.
// Desde el menú se llega a todas las estructuras de datos del proyecto
// (lista de cuentas, BST de transacciones, colas, ordenamientos, grafo de sucursales y hash de contraseñas).
int main()
{
	SistemaBancario sistema;
	sistema.menuPrincipal();
	return 0;
}
