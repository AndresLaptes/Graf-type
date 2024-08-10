#include <iostream>
#include "Graf.h"
using namespace std;

int main() {   
    Graf<int>* myGraf = new Graf<int> ;
    for (int i = 0; i < 10; ++i) myGraf->insert(i);

    for (int i = 0; i < 10; ++i) {
        for (int j = i; j < 10; ++j) {
            if (i % 2 == 0) {
                if (i != j) myGraf->conect(i, j);
            }
        }
    }

    cout << "Resultado" << endl;
    myGraf->visualizar();
}