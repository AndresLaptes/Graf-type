#ifndef GRAF_IMPL_H
#define GRAF_IMPL_H
#include "Graf.h"
#include <stdio.h>
#include <vector>
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
Graf<T>::Graf() {

}

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
    auto end = a->conections.end();
    for (auto it = a->conections.begin(); it != end; ++it) {
        if (*it == b) {
            found = true;
            break;
        }
    } 
    
    if (found) throw invalid_argument("Error: already exits your conection between this vertexs"); 
    a->conections.push_back(b);

    end = b->conections.end();
    for (auto it = b->conections.begin(); it != end; ++it) {
        if (a == *it)  {
            found = true;
            break;
        }
    }

    if (found) throw invalid_argument("Error: already exits your conection between this vertexs"); 
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
        auto end = nodo->conections.end();
        for (auto it = nodo->conections.begin(); it != end; ++it) cout << (*it)->vertex << " ";
        cout << endl; 
    }
}

template <typename T>
void Graf<T>::insert(const T& value, int argc, T nodes[]) {
    if (this->exist(value)) {
        string msg = "Error: Your node that are you trying to";
        msg += " already exist in graf";
        throw invalid_argument(msg);
    }
    
    typename Graf<T>::Node *nuevo = new typename Graf<T>::Node;
    nuevo->vertex = value;
    if (0 <= argc) {
        for (int i = 0; i < argc; ++i) {
            Node *aux = this->value(nodes[i]);
            if (aux == nullptr) {
                string msg = "Error: Your node that is in the position ";
                msg += to_string(i);
                msg += " not exist";
                throw invalid_argument(msg);
            } else {
                aux->conections.push_back(nuevo);
                nuevo->conections.push_back(aux);
            }
        }
    }
    this->vertexs.push_back(nuevo);
}

template <typename T>
bool Graf<T>::connected(const T& a, const T&b) const {
    bool found = false;
    if (a == b) {
        string msg = "Error: are same vertex";
        throw invalid_argument(msg);
    }

    Node *A = this->value(a);
    Node *B = this->value(b);
    if (A == nullptr) {
        string msg = "Error: your first vertex not exist in the graf";
        throw invalid_argument(msg);
    }

    if (B == nullptr) {
        string msg = "Error: your second vertex";
        msg += " not exist in the graf";
        throw invalid_argument(msg);
    }

    for (auto& it : A->conections) {
        if (it == B) {
            found = true;
            break;
        }
    }

    if (found) return true;

    for (auto& it : B->conections) {
        if (it == A) {
            found = true;
            break;
        }
    }

    return found;
} 

template <typename T>
void Graf<T>::conect(const T& a, const T& b) {
    Node *A = this->value(a);
    Node *B = this->value(b);
    if (A == nullptr) {
        string msg = "Error: your fisrt vertex ";
        msg += " not exits in the graf";
        throw invalid_argument(msg);
    }

    if (B == nullptr) {
        string msg = "Error: your second vertex ";
        msg += " not exits in the graf";
        throw invalid_argument(msg);
    }

    if (not this->connected(a, b)) {
        A->conections.push_back(B);
        B->conections.push_back(A);
    } else {
        string msg = "Error: your connection between your values";
        msg += " already exists";
        throw invalid_argument(msg);
    }
    
}

template <typename T>
T** Graf<T>::conections(const T& var) const {
    Node *aux = value(var);
    if (aux == nullptr) return nullptr;

    int i = 0;
    int size = aux->conections.size();
    T ** dev = new T*[size + 1];
    auto end = aux->conections.end();
    for (auto it = aux->conections.begin(); it != end; ++it) {
        dev[i] = &((*it)->vertex);
        ++i;
    }
    dev[size] = nullptr;
    
    return dev;
}

template <typename T>
void Graf<T>::clean() {
    for (auto node : vertexs) delete node;
    vertexs.clear();
}

template <typename T>
void Graf<T>::remove(const T& val) {
    Node *dir = this->value(val);
    if (dir != nullptr) {
        for (auto aux : dir->conections) {
            for (auto it = aux->conections.begin(); it != aux->conections.end(); ++it) {
                if (*it == dir) {
                    aux->conections.erase(it);
                    break;
                }
            }
        }

        for (auto aux = this->vertexs.begin(); aux != this->vertexs.end(); ++aux) {
            if (*aux == dir) {
                vertexs.erase(aux);
                break;
            }
        }
    } else {
        string msg = "Error: your are trying to remove a value that not exits";
        throw invalid_argument(msg);
    }
}

#endif