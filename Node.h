#include <ostream>
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

class Lista{
    
    public:
    
    bool especializada(){
        return false;
    }

    //LAS FUNCIONES CON ERROR
};


//List

template <class T>
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

    List& operator << (const T& value){
            this->push_back(value);
            return *this;
    }

    List& operator >> (const T& value){
            this->push_front(value);
            return *this;
    }


};


template <class T>
class Circular_List{
private:
    Node<T>* head ;
    Node<T>* tail ;
public:
    Circular_List(){head = nullptr; tail = nullptr;}

    ~Circular_List(){

    }

    T front(){
        return head->value;
    }

    
    T back(){
        return tail->value;
    }

    void push_front(const T &data){
        if(head == nullptr){
            Node<T>* node = new Node<T>{data, nullptr};
            head = node;
            tail = head;
        }
        else{
            Node<T>* New_Head = new Node<T>{data,head};
            head = New_Head;
            tail->next = head;
        }
    }

    void push_back(const T &data) {
        if (head == nullptr) {
            Node<T>* node = new Node<T>{data, nullptr};
            head = node;
            tail = head;
        }
        else {
            Node<T>* node = new Node<T>{data, head};
            tail->next = node;
            tail = node;
        }
    }

    void pop_back(){

        Node<T>* current = head;

        while(current->next != tail){
            current = current->next;
        }

        delete tail;

        current->next = head;
        tail = current;
        current = nullptr;
        delete current;
        

    }

    void pop_front(){

        Node<T>* current = head->next;

        delete head;
        head = current;
        tail->next = head;
        current = nullptr;
        delete current;
    }

    bool empty(){
        return head == nullptr;
    }

    Iterator<T> end(){
        return (Iterator<T> (nullptr));
    }

    int Size(){
        Node<T>* current = head;
        int contador = 1;

        while(current != tail){
            contador ++;
            current = current->next;
        }
        return contador;
    }

    T& operator [](int pos){
        Node<T>* current = head;
        for(int i = 0; i < Size(); i++){
            if(i == pos){
                return current->data;
            }
            current = current->next;
        }
    }

    //Printing
    friend std::ostream& operator << (std::ostream &os , const Circular_List &circular){
        Node<T>* current = circular.head;
        do{
            os << current->value << " ";
            current = current->next;

        }while(current != circular.head);
    }

    Circular_List& operator << (const T& _value){
            this->push_back(_value);
            return *this;
        }

    Circular_List& operator >> (const T& _value){
        this->push_front(_value);            
        return *this;
    }

};

template <class T>
class Iterator_Conexo{
private:
    Nodo_Conexo<T>* iterador;
public:
    Iterator_Conexo(){iterador = nullptr;}

    Iterator_Conexo(Nodo_Conexo<T>* it){ this->iterador = it;}

    void operator ++ (){
        this->iterador = this->iterador->next;
    }

    void operator -- (){
        this->iterador = this->iterador->previous;
    }
    T& operator * (){
        return iterador->value;
    }
    bool operator == (const Iterator_Conexo &it){
        return (iterador == it.iterador);
    }
    bool operator != (const Iterator_Conexo &it){
        return (iterador != it.iterador);
    }

};


template<typename T>
class Double_Linked_List{
private:
    Nodo_Conexo<T>* head ;
    Nodo_Conexo<T>* tail ;
public:
    Double_Linked_List(){head = nullptr; tail = nullptr;}

    ~Double_Linked_List(){

    }

    T front(){
        return head->value;
    }

    
    T back(){
        return tail->value;
    }

    void push_back(const T &data){
        if(head == nullptr){
            Nodo_Conexo<T>* node = new Nodo_Conexo<T>{data, nullptr, nullptr};
            head = node;
            tail = head;
        }
        else{
            Nodo_Conexo<T>* node = new Nodo_Conexo<T>{data, nullptr, tail};
            tail->next = node;
            tail = node;
        }
    }

    void push_front(const T &data){
        if(head == nullptr){
            Nodo_Conexo<T>* node = new Nodo_Conexo<T>{data, nullptr, nullptr};
            head = node;
            tail = head;
        }
        else{
            Nodo_Conexo<T>* node = new Nodo_Conexo<T>{data, head, nullptr};
            head->previous = node;
            head = node;
        }
    }

    void pop_front(){
        
        Nodo_Conexo<T>* current = head->next;
        delete head;
        head = current;
        current = nullptr;
        delete current;

    }

    void pop_back(){

        Nodo_Conexo<T>* current = tail->previous;

        delete tail;
        tail = current;
        tail->next = nullptr;
    
    }

     bool empty(){
        return head == nullptr;
    }


     int Size(){
        Nodo_Conexo<T>* current = head;
        int contador = 1;

        while(current != tail){
            contador ++;
            current = current->next;
        }
        return contador;
    }
    

    Iterator_Conexo<T> end(){
        return (Iterator_Conexo<T> (nullptr));
    }

    T& operator [] (int pos){
        int contador = 0;
        for(Iterator_Conexo<T> it(head); it != end(); ++it){
            if(contador == pos)
                return *it;
            else{
                contador++;
            }
        }
    }

    //Printing
    friend std::ostream& operator << (std::ostream &os, const Double_Linked_List &dll){
        Nodo_Conexo<T>* current = dll.head;
        while(current != nullptr ){
            os << current->value << " ";
            current = current->next;
        }
    }

    Double_Linked_List& operator << (const T& _value){
            this->push_back(_value);
            return *this;
        }

    Double_Linked_List& operator >> (const T& _value){
            this->push_front(_value);            
            return *this;
    }

};


template <class T>

class Double_Linked_Circular_List{
private:
    Nodo_Conexo<T>* head;
    Nodo_Conexo<T>* tail;
public:
    Double_Linked_Circular_List(){head = nullptr; tail = nullptr;}

    ~Double_Linked_Circular_List(){

    }


    T front(){
        return head->value;
    }

    
    T back(){
        return tail->value;
    }


    void push_back(const T& data){

        if(head == nullptr){
            Nodo_Conexo<T>* node = new Nodo_Conexo<T>{data, nullptr, nullptr};
            head = node;
            tail = head;
        }
        else{
            Nodo_Conexo<T>* node = new Nodo_Conexo<T>{data, head, tail};
            tail->next = node;
            tail = node;
        }

    }

    void push_front(const T& data){

        if(head == nullptr){
            Nodo_Conexo<T>* node = new Nodo_Conexo<T>{data, nullptr, nullptr};
            head = node;
            tail = head;
        }
        else{
            Nodo_Conexo<T>* node = new Nodo_Conexo<T>{data, head, tail};
            tail->next = node;
            head = node;
        }

    }

    void pop_back(){

        Nodo_Conexo<T>* current = tail->previous;
        delete tail;
        current->next = head;
        head->previous = current;
        tail = current;

    }

    void pop_front(){

        Nodo_Conexo<T>* current = head->next;
        delete head;
        tail->next = current;
        current->previous = tail;
        head = current;

    }

     bool empty(){
        return head == nullptr;
    }

    Iterator_Conexo<T> end(){
        return (Iterator_Conexo<T> (nullptr));
    }

    int Size(){
        Nodo_Conexo<T>* current = head;
        int contador = 1;

        while(current != tail){
            contador ++;
            current = current->next;
        }
        return contador;
    }

    T& operator [](int pos){
        Nodo_Conexo<T>* current = head;
        for(int i = 0; i < Size(); i++){
            if(i == pos){
                return current->value;
            }
            current = current->next;
        }
    }

    //Printing
    friend std::ostream& operator << (std::ostream &os , const Double_Linked_Circular_List &double_circular){
        Nodo_Conexo<T>* current = double_circular.head;
        do{
            os << current->value << " ";
            current = current->next;

        }while(current != double_circular.head);
    }

    Double_Linked_Circular_List& operator << (const T& _value){
            this->push_back(_value);
            return *this;
        }

    Double_Linked_Circular_List& operator >> (const T& _value){
        this->push_front(_value);            
        return *this;
    }


};
