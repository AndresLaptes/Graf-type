#include <iostream>
#include "Graf.h"
using namespace std;

int main() {   
    Graf<int>* myGraf = new Graf<int>(5);
    for (int i = 0; i < 10; ++i) myGraf->insert(i);
    myGraf->visualizar();
}