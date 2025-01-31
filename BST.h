#pragma once

#include <iostream>

using namespace std;

template<typename t>
class Node {
public:
    Node<t>* izq;
    t data;
    Node<t>* der;
    Node(const t& dato): data(dato), izq(nullptr), der(nullptr){}

};
//EL insert, la busqueda y los recorridos los hice con el id de la transaccion que no se va a repetir, en el enunciado del proyecto dice que
//se haga mediante el numero de cuenta pero las transacciones pueden venir de una misma cuenta entonces se podrian repetir los numeros de cuenta aqui en el bst
//creando problemas por eso cree el id transaccion para evitar duplicados 
template<typename t>
class BST {

    Node<t>* root;
public:
    BST() { root = nullptr; }
    Node<t>* getRoot() { return root; }
    void Insert(t dato);
    void insert(t dato);
    void InOrder(Node<t>* p);
    void preOrder(Node<t>* p);
    void postOrder(Node<t>* p);
    void inorder(Node<t>* p);//para probarlo con datos primitivos
    void preorder(Node<t>* p);
    void postorder(Node<t>* p);
    Node<t>* Search(int idTransaccion);
    bool replace(t& nuevaTransaccion);
};
template <typename t>
void BST<t>::Insert(t dato) {//se inserta conforme al numero de cuenta de la transaccion 

    Node<t>* actual = root;
    Node<t>* nuevo;
    Node<t>* previo = root;

    // root is empty
    if (root == nullptr) {
        nuevo = new Node<t>(dato); 
        root = nuevo;
        return;
    }

    while (actual != nullptr) {
        previo = actual;
        if (dato.getIdTransaccion() < actual->data.getIdTransaccion()) {
            actual = actual->izq;
        }
        else if (dato.getIdTransaccion() > actual->data.getIdTransaccion()) {
            actual = actual->der;
        }
        else {//si es igual termina el metodo, en un historialGlobal no deben de haber duplicados
            return;
        }
    }

    //ahora r apunta al padre del dato que se ingresara y temp en nulo
    nuevo = new Node<t>(dato);
   
    if (dato.getIdTransaccion() < previo->data.getIdTransaccion()) {//se hace la insercion en la posicion correspondiente
        previo->izq = nuevo;
    }
    else {
        previo->der = nuevo;
    }

}
template <typename t>
void BST<t>::InOrder(Node<t>* p) {
    if (p) {
        InOrder(p->izq);
        p->data.imprimir();
        InOrder(p->der);
    }
}
template <typename t>
void BST<t>::preOrder(Node<t>* p) {
    if (p) {
        p->data.imprimir();
        preOrder(p->izq); 
        preOrder(p->der);
    }
}
template <typename t>
void BST<t>::postOrder(Node<t>* p) {
    if (p) {
    	postOrder(p->izq);
        postOrder(p->der);
        p->data.imprimir();
    }
}
template<typename t>
Node<t>* BST<t>::Search(int idTransaccion) {
    Node<t>* temp = root;
    while (temp != nullptr) {
        if (idTransaccion == temp->data.getIdTransaccion()) {
            return temp;
        }
        if (idTransaccion < temp->data.getIdTransaccion()) {
            temp = temp->izq;
        }
        else {
            temp = temp->der;
        }
    }
    return nullptr;
}
template<typename t>
bool BST<t>::replace(t& nuevaTransaccion) {
    int idTransaccion = nuevaTransaccion.getIdTransaccion();
    Node<t>* temp = root;

    while (temp != nullptr) {
        if (idTransaccion == temp->data.getIdTransaccion()) {
             
            temp->data = nuevaTransaccion;
            return true;  
        }
        if (idTransaccion < temp->data.getIdTransaccion()) {
            temp = temp->izq;
        }
        else {
            temp = temp->der;
        }
    }

   
    return false;
}
template <typename t>
void BST<t>::inorder(Node<t>* p) {
    if (p) {
        inorder(p->izq);
        cout << p->data << " ";
        inorder(p->der);
    }
}
template <typename t>
void BST<t>::preorder(Node<t>* p) {
    if (p) {
        cout << p->data << " ";
        preorder(p->izq);
        preorder(p->der);
    }
}
template <typename t>
void BST<t>::postorder(Node<t>* p) {
    if (p) {
        postorder(p->izq);
        postorder(p->der);
        cout<<p->data<<" ";
    }
}
template <typename t>//para utilizarlo con int
void BST<t>::insert(t dato) {//se inserta conforme al numero de cuenta de la transaccion 

    Node<t>* actual = root;
    Node<t>* nuevo;
    Node<t>* previo = root;

    // root is empty
    if (root == nullptr) {
        nuevo = new Node<t>(dato);
        root = nuevo;
        return;
    }

    while (actual != nullptr) {
        previo = actual;
        if (dato < actual->data) {
            actual = actual->izq;
        }
        else if (dato > actual->data) {
            actual = actual->der;
        }
        else {//si es igual termina el metodo, en un historialGlobal no deben de haber duplicados
            return;
        }
    }

    //ahora r apunta al padre del dato que se ingresara y temp en nulo
    nuevo = new Node<t>(dato);

    if (dato < previo->data) {//se hace la insercion en la posicion correspondiente
        previo->izq = nuevo;
        cout << "ingresando a la izquierda: "<<dato<<"\n";
    }
    else {
        previo->der = nuevo;
        cout << "ingresando a la derecha: " << dato << "\n";
    }

}