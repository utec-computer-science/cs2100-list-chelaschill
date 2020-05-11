#include <iostream>
#include "traits.cpp"

using namespace std;

int main() {

    Double_Linked_Circular_List<int> dcl;

    dcl.push_back(1);
    dcl.push_back(5);
    dcl.push_back(2);
   

    dcl.pop_front();
    dcl.pop_back();

    cout << dcl;



    return 0;
}
