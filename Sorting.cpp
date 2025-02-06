#include "Sorting.h"

void swap(Cliente& a, Cliente& b) noexcept
{
    Cliente temp = a;
    a = b;
    b = temp;
}

void swapCuenta(Nodo<Cuenta>* nodo1, Nodo<Cuenta>* nodo2) {
    if (nodo1 && nodo2) {
        Cuenta temp = nodo1->dato;
        nodo1->dato = nodo2->dato;
        nodo2->dato = temp;
    }
}

void bubbleSort(ListaCuentas<Cuenta>& cuentas) {
    if (!cuentas.getHead()) return;

    bool intercambiado;
    Nodo<Cuenta>* actual;
    Nodo<Cuenta>* limite = nullptr;

    do {
        intercambiado = false;
        actual = cuentas.getHead();

        while (actual->next != limite) {
            if (actual->dato.getSaldo() > actual->next->dato.getSaldo()) {
                swapCuenta(actual, actual->next);
                intercambiado = true;
            }
            actual = actual->next;
        }
        limite = actual;
    } while (intercambiado);
}
void insertionSort(ListaCuentas<Cuenta>& cuentas) {
    if (!cuentas.getHead()) return;

    Nodo<Cuenta>* listaOrdenada = nullptr;
    Nodo<Cuenta>* actual = cuentas.getHead();

    while (actual) {
        Nodo<Cuenta>* siguiente = actual->next;


        if (!listaOrdenada || listaOrdenada->dato.getSaldo() >= actual->dato.getSaldo()) {
            actual->next = listaOrdenada;
            listaOrdenada = actual;
        }
        else {
            Nodo<Cuenta>* temp = listaOrdenada;
            while (temp->next && temp->next->dato.getSaldo() < actual->dato.getSaldo()) {
                temp = temp->next;
            }
            actual->next = temp->next;
            temp->next = actual;
        }

        actual = siguiente;
    }

    cuentas.setHead(listaOrdenada); // Actualizar la cabeza con la lista ordenada
}
void selectionSort(ListaCuentas<Cuenta>& cuentas) {
    if (!cuentas.getHead()) return;

    Nodo<Cuenta>* actual = cuentas.getHead();

    while (actual) {
        Nodo<Cuenta>* minimo = actual;
        Nodo<Cuenta>* explorador = actual->next;

        while (explorador) {
            if (explorador->dato.getSaldo() < minimo->dato.getSaldo()) {
                minimo = explorador;
            }
            explorador = explorador->next;
        }

        if (minimo != actual) {
            swapCuenta(minimo, actual);
        }

        actual = actual->next;
    }
}


void Merge(Cliente A[], int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int k = low;
    Cliente* B = new Cliente[high + 1];
    while (i <= mid && j <= high) {
        if (A[i].getIdentificacion() < A[j].getIdentificacion()) {
            B[k++] = A[i++];
        }
        else {
            B[k++] = A[j++];
        }
    }
    while (i <= mid) {
        B[k++] = A[i++];
    }
    while (j <= high) {
        B[k++] = A[j++];
    }
    for (int e = low; e <= high; e++) {
        A[e] = B[e];
    }
}

void RecursiveMergeSort(Cliente A[], int low, int high) {
    if (low < high) {

        int mid = low + (high - low) / 2;


        RecursiveMergeSort(A, low, mid);
        RecursiveMergeSort(A, mid + 1, high);


        Merge(A, low, mid, high);
    }
}


int partition(Cliente A[], int low, int high) {
	string pivot = A[low].getNombreCompleto();
    int i = low + 1;
    int j = high;

    while (true) {
        while (i <= j && A[i].getNombreCompleto() <= pivot) {
            i++;
        }
        while (A[j].getNombreCompleto() >= pivot && j >= i) {
            j--;
        }
        if (j < i) {
            break;
        }
        swap(A[i], A[j]);
    }
    swap(A[low], A[j]);
    return j;
}

void QuickSort(Cliente A[], int low, int high) {
    if (low < high) {
        int p = partition(A, low, high);
        QuickSort(A, low, p - 1);
        QuickSort(A, p + 1, high);
    }
}

//Heap sort
void Insert(Cliente A[], int n)
{
    int i = n;
    Cliente temp = A[i];
    while (i > 1 && temp.getIdentificacion() > A[i / 2].getIdentificacion())
    {
        A[i] = A[i / 2];
        i = i / 2;
    }
    A[i] = temp;
}
inline Cliente Delete(Cliente clientes[], int n)
{
    int i, j;
    Cliente temp;
    Cliente val = clientes[0];
    Cliente x = clientes[n];
    clientes[0] = clientes[n];
    clientes[n] = val;
    i = 0; j = i * 2;
    while (j <= n - 1)
    {
        if (j<n - 1 && clientes[j + 1].getIdentificacion()>clientes[j].getIdentificacion())
            j = j + 1;
        if (clientes[i].getIdentificacion() < clientes[j].getIdentificacion())
        {
            temp = clientes[i];
            clientes[i] = clientes[j];
            clientes[j] = temp;
            i = j;
            j = 2 * j;
        }
        else
            break;
    }
    return val;
}

void HeapSort(Cliente clientes[], int n) {

    int i;
    for (i = 0; i <= n; i++)
        Insert(clientes, i);

    for (i = n; i > 0; i--)
    {
        Delete(clientes, i);
    }
}