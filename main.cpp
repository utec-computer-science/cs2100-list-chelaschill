#include <iostream>
#include "List.h"

using namespace std;

int main() {

    int *array =  new int[5];

    for(int i = 0; i < sizeof(array); i++)
        array[i] = i;

    List<int> lista(array);

    //lista.List(array);


    return 0;
}
