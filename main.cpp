#include <iostream>
#include "List.h"

using namespace std;

int main() {

    int array[5] =  {1,2,3,4,5};


    List<int> lista;
    auto nodo = new Node<int>(4, nullptr);
    lista.push_back(1);
    lista.push_back(2);
    lista.push_back(3);
    //lista.push_back(4);
    lista.push_back(5);

    lista.insert(nodo, 3);

   cout << lista;




    return 0;
}
