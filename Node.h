#ifndef LINKED_LIST_NODE_H
#define LINKED_LIST_NODE_H

#endif //LINKED_LIST_NODE_H

template <typename T>
class Node {

public:
    T value;
    Node<T>* next;

    Node(T value, Node<T>* next){this->value = value; this->next = next;}

    ~Node(){}
};

template <typename T>
class Nodo_Conexo {

public:
    T value;
    Nodo_Conexo<T>* next;
    Nodo_Conexo<T>* previous;
    
    Nodo_Conexo(T value, Nodo_Conexo<T>* next, Nodo_Conexo<T>* previous){this->value = value; this->next = next; this->previous = previous;}

    ~Nodo_Conexo(){}
};
