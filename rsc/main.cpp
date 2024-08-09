#include <iostream>
#include "Graf.h"
using namespace std;

int main() {   
    Graf<int>* myGraf = new Graf<int>(5);
    myGraf->insert(5,0);
}