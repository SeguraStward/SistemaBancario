# Sistema Bancario en C++

> Simulador de banco por consola donde cada parte del sistema está construida sobre una **estructura de datos implementada desde cero**: listas enlazadas, árbol binario de búsqueda, colas, cola de prioridad, pila, tabla hash y grafo, más siete algoritmos de ordenamiento.

![C++17](https://img.shields.io/badge/C%2B%2B-17-blue.svg)
![Sin STL para estructuras](https://img.shields.io/badge/estructuras-implementadas%20a%20mano-orange.svg)
![Plataformas](https://img.shields.io/badge/Windows%20%7C%20Linux%20%7C%20macOS-lightgrey.svg)

Proyecto del curso de Estructuras de Datos · Universidad Nacional de Costa Rica.

---

## Qué hace

Desde un menú por consola se puede:

- Registrar clientes con usuario y contraseña, y abrirles una o varias cuentas.
- Hacer depósitos, retiros y transferencias entre cuentas.
- Enviar transacciones a una cola normal o a una **cola de prioridad**, para que un administrador las procese o las bloquee.
- Buscar transacciones por ID y recorrer el historial (in-orden, pre-orden, post-orden).
- Ordenar cuentas y clientes con distintos algoritmos.
- Calcular la red de sucursales de menor costo y recorrerla.

## Qué estructura resuelve cada problema

| Parte del banco | Estructura | Archivo | Por qué |
|-----------------|-----------|---------|---------|
| Cuentas | Lista enlazada genérica | `ListaCuentas.h` | Altas y bajas sin mover memoria. |
| Clientes | Arreglo dinámico + búsqueda binaria | `GestorClientes.*`, `Cliente.h` | Se ordena por nombre y se busca en O(log n). |
| Historial global de transacciones | Árbol binario de búsqueda | `BST.h` | Búsqueda por ID en O(log n) en promedio. |
| Solicitudes normales | Cola (FIFO) | `Cola.h` | Se atienden en orden de llegada. |
| Solicitudes urgentes | Cola de prioridad | `ColaPrioritaria.h` | Las transacciones prioritarias se procesan primero. |
| Movimientos recientes de cada cuenta | Pila (LIFO) | `Pila.h`, `Cuenta.h` | Lo último que pasó es lo primero que se muestra. |
| Contraseñas | Tabla hash (djb2 + sondeo lineal) | `HashMap.*` | Verificar usuario y contraseña en O(1) en promedio. |
| Sucursales | Grafo con matriz de adyacencia | `Graph.*` | Árbol de expansión mínima con **Prim** y **Kruskal**; recorridos **BFS** y **DFS**. |

**Ordenamientos** (`Sorting.*`): Bubble Sort, Insertion Sort y Selection Sort sobre la lista de cuentas; Merge Sort, Quick Sort y Heap Sort sobre el arreglo de clientes.

## Cómo ejecutarlo

**Linux / macOS (g++)**

```bash
git clone https://github.com/SeguraStward/SistemaBancario.git
cd SistemaBancario
g++ -std=c++17 *.cpp -o sistema_bancario
./sistema_bancario
```

**Con CMake (cualquier sistema)**

```bash
cmake -B build
cmake --build build
./build/sistema_bancario
```

**Windows (Visual Studio)**: abre `Sistema bancario.sln` y ejecuta con `Ctrl + F5`.

## Pruebas

```bash
g++ -std=c++17 -I. tests/test_hashmap.cpp HashMap.cpp -o test_hashmap
./test_hashmap
```

Verifican que la tabla de contraseñas no deje entrar con la contraseña de otro usuario, que actualizar una contraseña no cree duplicados y que con muchas colisiones ninguna llave se pierda.

## Estructura del proyecto

```text
SistemaBancario/
├── Main.cpp                 # abre el menú principal
├── SistemaBancario.*        # lógica del banco y menús
├── ListaCuentas.h  Cuenta.h  Nodo.h
├── GestorClientes.*  Cliente.h
├── Transaccion.h
├── BST.h  Cola.h  ColaPrioritaria.h  Pila.h
├── HashMap.*                # contraseñas
├── Graph.*                  # sucursales: Prim, Kruskal, BFS, DFS
├── Sorting.*                # 7 algoritmos de ordenamiento
├── tests/
├── CMakeLists.txt
└── Sistema bancario.sln     # proyecto de Visual Studio
```

## Próximas mejoras

- Guardar las contraseñas con un hash criptográfico (por ejemplo bcrypt) en lugar de texto plano.
- Persistir clientes y cuentas en un archivo para no perderlos al cerrar.
- Reemplazar punteros crudos por `std::unique_ptr` para manejar la memoria de forma automática.

---

Hecho por **Stward Segura**, estudiante de Ingeniería en Sistemas en la Universidad Nacional de Costa Rica.
