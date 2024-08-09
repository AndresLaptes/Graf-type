
#ifndef GRAF_IMPL_H
#define GRAF_IMPL_H
#include "Graf.h"
#include <stdio.h>
#include <vector>
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
Graf<T>::Graf(const T& value) {
    Node *nuevo = new Node;
    nuevo->vertex = value;
    vertexs.push_back(nuevo);
}

template <typename T>
int Graf<T>::size() const {
    return vertexs.size();
}

template <typename T> 
Graf<T>::~Graf() {
    for (auto node : vertexs) delete node;
    vertexs.clear();
}

template <typename T> 
void Graf<T>::insert_biconection(Node *a, Node *b){
    bool found = false;
    int end = a->conections.size();
    for (int i = 0; i < end; ++i) {
        if (b == a->conections[i]) found = true;
    }
    
    if (found) throw invalid_argument("Error: already exits your conection between this nodes"); 
    a->conections.push_back(b);

    end = b->conections.size();
    for (int i = 0; i < end; ++i) {
        if (a == b->conections[i]) found = true;
    }

    if (found) throw invalid_argument("Error: already exits your conection between this nodes"); 
    b->conections.push_back(a);
}

template <typename T>
typename Graf<T>::Node* Graf<T>::value(const T& var) const {
    for (auto& nodo : vertexs) {
        if (nodo->vertex == var) return nodo; 
    }
    return nullptr; 
}

template <typename T>
bool Graf<T>::exist(const T& var) const {
    Node *aux = value(var);
    return aux != nullptr;
}

template <typename T>
void Graf<T>::visualizar() {
    for (auto& nodo : vertexs) {
        cout << "En la direccion (" << nodo << ") hay un nodo con valor: " << nodo->vertex << " con las siguientes conexiones : ";
        int end = nodo->conections.size();
        for (int i = 0; i < end; ++i) cout << nodo->conections[i] << " ";
        cout << endl; 
    }
}

template <typename T>
void Graf<T>::insert(const T& value, int argc, T nodes[]) {
    typename Graf<T>::Node *nuevo = new typename Graf<T>::Node;
    nuevo->vertex = value;
    if (0 <= argc) {
        for (int i = 0; i < argc; ++i) {
            Node *aux = this->value(nodes[i]);
            if (aux == nullptr) {
                string msg = "Error: Your node ";
                msg += to_string(nodes[i]);
                msg += " is not exist";
                throw invalid_argument("Error: argc is an invalid number");
            } else {
                aux->conections.push_back(nuevo);
                nuevo->conections.push_back(aux);
            }
        }
    }
    this->vertexs.push_back(nuevo);
}

#endif