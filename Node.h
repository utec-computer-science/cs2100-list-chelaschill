#ifndef LINKED_LIST_NODE_H
#define LINKED_LIST_NODE_H

#endif //LINKED_LIST_NODE_H

template <typename T>
class Node {

public:
    T value;
    Node<T>* next;

    Node(T value, Node<T>* next){this->value = value; this->next = next;}

    ~Node(void){}
};
