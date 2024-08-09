
#ifndef GRAF_IMPL_H
#define GRAF_IMPL_H
#include "Graf.h"
#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

template <typename T>
Graf<T>::Graf(const T& value) {
    size = 1;
    Node<T> *nuevo = new Node<T>();
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
void Graf<T>::insert(const T& value, int argc, T direcciones[]) {
    vertexs.push_back(value);
    Node *nuevo = vertexs.back();
    if (argc > 0) {
        for (int i = 0; i < argc; ++i) {
            //

        }
    } else if (argc != 0) //Añadir clase exepcion

}

#endif