#ifndef GRAF_H
#define GRAF_H
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;



template <typename T> class Graf {
    private:
        struct Node{
            T vertex;
            vector<Node*> conections;
        };
        vector<Node*> vertexs;

        void insert_biconection(Node *a, Node *b);
    public:
        Graf(const T&);
        ~Graf();
        int size() const;
        void insert(const T& value, int argc = -1 ,T direcciones[] = {});
        //si se encuentra devuelve &var, sino exitse devuelve nullptr
        Node *value(const T& var) const;
        //si existe retorna true, sino false
        bool exist(const T&var) const;

        //conecta dos nodos si no se puede exepcion
        void conect(const T& a, const T& b);
        
        void visualizar(); //Esta la eliminaremos pronto o la pondremos en el privado;

};

#include "Graf_impl.h"

#endif