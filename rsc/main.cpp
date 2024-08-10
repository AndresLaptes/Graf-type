#include <iostream>
#include "Graf.h"
using namespace std;

struct Persona {
    int edad;
    string nombre;

    bool operator==(const Persona other) const {
        return (edad == other.edad) && (nombre == other.nombre);
    }
};

int main() {   
    Graf<Persona>* myGraf = new Graf<Persona>;
    Persona aux, aux2;
    aux.edad = 10;
    aux.nombre = "Andres";
    aux2.edad = 12;
    aux2.nombre = "Matilda";
    myGraf->insert(aux);
    myGraf->insert(aux2);
    myGraf->conect(aux, aux2);

    Persona** ver = myGraf->conections(aux);
    if (ver != nullptr) {
        Persona *ptr = ver[0];
        for (int i = 0; ptr != nullptr; ptr = ver[i]) {
            cout << "Edad: " << ver[i]->edad << endl;
            cout << "Nombre: " << ver[i]->nombre << endl;
            cout << endl;
            ++i;
        }
    }

}