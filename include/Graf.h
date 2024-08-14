#ifndef GRAF_H
#define GRAF_H
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


//si el tipo es un struct tienes que definir sus operadores ==, <= etc...
template <typename T> class Graf {
    private:
        struct Node{
            T vertex;
            vector<Node*> conections;
        };
        vector<Node*> vertexs;
        
        //si se encuentra devuelve &var, sino exitse devuelve nullptr
        Node *value(const T& var) const;
        void insert_biconection(Node *a, Node *b);
    public:
        Graf(const T& val);
        Graf();
        ~Graf();
        int size() const;
        //valor a añadir, numero de conexxiones hemos pasado, las conexiones...
        void insert(const T& value, int argc = -1 ,T conexiones[] = {});

        //Elimina el vertice y todas sus conexiones
        void remove(const T& value);

        //limpia todo el grafo
        void clean();

        //si existe retorna true, sino false
        bool exist(const T&var) const;

        //mira si dos vertices estan connectado
        bool connected(const T& a, const T& b) const;

        //conecta dos nodos si no se puede exepcion
        void conect(const T& a, const T& b);
        
        void visualizar(); //Esta la eliminaremos pronto o la pondremos en el privado;

        //devuelve la direccion de las conexiones de lo que se le pasa por parametro, si no existe nullptr y si exite el utlimo elemento siempre sera nullptr
        T** conections(const T& var) const;

        //lee un archivo csv 
        void read(FILE *file);

};

#include "Graf_impl.h"

#endif