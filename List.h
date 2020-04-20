#ifndef LINKED_LIST_LIST_H
#define LINKED_LIST_LIST_H

#endif //LINKED_LIST_LIST_H

#include "Node.h"

template <class T>
class Iterator{
private:
    Node<T>* iterator;
public:
    Iterator(){iterator = nullptr;}

    Iterator(Node<T>* it){this->iterator = it;}

    void operator ++ (){
        this->iterator = this->iterator->next;
    }

    void operator -- (){
        this->iterator = this->iterator->previous;
    }

    T& operator * (){
        return iterator->value;
    }

    bool operator == (const Iterator &it){
        return (iterator == it.iterator);
    }

    bool operator != (const Iterator &it){
        return (iterator != it.iterator);
    }

};

template <typename T>
class List {
private:
    Node<T>* head;
    Node<T>* tail;
public:
    List(const List &lista){head = lista.head; tail = lista.tail;}

    List(T* array, int size) {

        head = nullptr;
        tail = head;

        for (int i = 0; i < size; i++) {
            push_back(array[i]);
        }
        tail->next = nullptr;
    }

    List(Node<T>* node){
        head = node;
        tail = node;
    }

    List(int n){

        head = nullptr;
        tail = head;
        for(int i = 0; i < n; i++){
            push_back(rand());
        }
    }

    List(){head = nullptr, tail = nullptr;}

    ~List(){
    }

    //Retorna una referencia al primer elemento
    T front(){
        return head->value;
    }

    // Retorna una referencia al ultimo elemento
    T back(){
        return tail->value;
    }


    // Inserta un elemento al final
    void push_back(const T& element){
        if (head == nullptr) {
            Node<T>* node = new Node<T> {element, nullptr};
            head = node;
            tail = head;
        }
        else {
            Node<T>* node = new Node<T> {element, nullptr};
            tail->next = node;
            tail = node;
        }
    }

    // Inserta un elemento al inicio
    void push_front(const T& element){
        if(head == nullptr){
            Node<T>* node = new Node<T> {element, nullptr};
            head = node;
            tail = head;
        }
        else{
            Node<T>* New_Head = new Node<T> {element, head};
            head = New_Head;
        }
    }

    // Quita el ultimo elemento y retorna una referencia
    void pop_back(){
        Node<T>* current = head;
        if(current != nullptr) {
            while (current->next != tail) {
                current = current->next;
            }
            delete tail;
            current->next = nullptr;
            tail = current;
        }
    }

    // Quita el primer elemento y retorna una referencia
    void pop_front(){
        Node<T>* current = head;
        if(current != nullptr) {
            current = current->next;
            delete head;
            head = current;
        }
    }

    Iterator<T> end(){
        return (Iterator<T> (nullptr));
    }

    // Acceso aleatorio
    T &operator [] (int pos){
        int contador = 0;
        for(Iterator<T> it(head); it != end() ; ++it){
            if(contador == pos)
                return *it;
            else{
                contador++;
            }
        }
    }

    // la lista esta vacia?
    bool empty(){
        return head == nullptr;
    }

    // retorna el tamaño de la lista
    unsigned int size(){
        Node<T>* current = head;
        int contador = 0;

        while(current != nullptr){
            contador++;
            current = current->next;
        }
        return contador;
    }

    // Elimina toda la lista
    void clear(){
        Node<T>* current = head;
        while(current != nullptr){
            current = current->next;
            delete head;
            head = current;
        }
        delete current;
        delete head;
        delete tail;
    }

    // Elimina un elemento en base a un puntero
    void erase(Node<T>* borrar){
        Node<T>* current = head;

        if(head->value == borrar->value) {
            head = head->next;
            delete current;
        }

        while(current != nullptr){
            if(current->next != nullptr) {
                if (current->next->value == borrar->value){
                    current->next = current->next->next;
                    if(current->next == nullptr)
                        tail = current;
                }
            }
            current = current->next;
        }
    }

    // Inserta un elemento  en base a un puntero
    void insert(Node<T>* insertar, const T& pos) {
        if (pos >= size())
            push_back(insertar->value);
        if (pos == 0)
            push_front(insertar->value);
        if (pos > 0 && pos < size()) {
            Node<T> *current = head;
            for (int i = 0; i < pos - 1; i++) {
                current = current->next;
            }
            insertar->next = current->next;
            current->next = insertar;
        }
    }


    // Elimina todos los elementos por similitud
    void remove(const T& data){

        Node<T>* current = head;

        if(head->value == data) {
            head = head->next;
            delete current;
        }

        while(current != nullptr){
            if(current->next != nullptr) {
                if (current->next->value == data){
                    current->next = current->next->next;
                    if(current->next == nullptr)
                        tail = current;
                }
            }
            current = current->next;
        }
    }

    List& sort(){
        Node<T>* j = head->next;
        Node<T>* i = head;

        for(i = head; i != nullptr; i = i->next ){
            for(j = i->next; j != nullptr; j = j->next){
                if(i->value > j->value){
                    T temp = i->value;
                    i->value = j->value;
                    j->value = temp;
                }
            }
        }
    }

    // invierte la lista
    List& reverse(){
        Node<T>* cabeza = head;
        cabeza->value = head->value;
        Node<T>* cola = head;
        cola->value = head->value;
        int j = 0;

        for(int i = 0; i < size()/2; i++){
            int contador = size()-1-j;
            while(contador > 0 ){
                cola = cola->next;
                contador--;
            }
            j++;

            T temp = cabeza->value;
            cabeza->value = cola->value;
            cola->value = temp;

            cabeza = cabeza->next;
            cola = head;
        }
    }

    // Imprime la lista con cout
    friend std::ostream& operator << (std::ostream &os , const List &lista){
        Node<T>* current = lista.head;
        while(current != nullptr) {
            os << current->value << " ";
            current = current->next;
        }
    }
};
