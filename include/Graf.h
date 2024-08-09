#ifndef GRAF_H
#define GRAF_H
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

template <typename T> struct Node{
    T vertex;
    vector<Node*> conections;
};

template <typename T> class Graf {
    private:
        vector<Node<T>*> vertexs;
    public:
        Graf(const T&);
        ~Graf();
        int size() const;
        void insert(const T& value, int argc ,T direcciones[] = {});
};

#include "Graf_impl.h"

#endif