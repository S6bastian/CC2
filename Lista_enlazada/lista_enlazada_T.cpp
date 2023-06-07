#include <iostream>

using namespace std;

template <class T>
struct nodo {
    T valor;
    nodo <T>* next;
    nodo(T v, nodo<T>* n = nullptr) {
        valor = v;
        next = n;
    }
};


template <class T>
struct LE {    //Lista Enlazada
    nodo<T>* head=NULL;

    bool find(T x, nodo<T> *&pos);
    void add(T x);
    bool del(T x);
    void print();
    //~LE();
};

template <class T>
bool LE<T>::find(T x, nodo<T> *&pos) {
    bool key = false;
    pos = nullptr;

    for (nodo<T>* p = head; p && p->valor <= x; p = p->next) {
        if (p->valor == x) {
            key = true;
        }
        else{
            pos = p;
        }
    }

    return key;
}

template <class T>
void LE<T>::add(T x) {
    nodo<T>* pos;

    if (!find(x, pos)) {
        if (pos) {
            pos->next = new nodo<T>(x, pos->next);
        }
        else {
            head = new nodo<T>(x, head);
        }
    }
}

template  <class T>
bool LE<T>::del(T x) {
    nodo<T>* pos, * tmp;
    bool key = find(x, pos);

    if (key) {
        if (pos) {
            tmp = pos->next;
            pos->next = tmp->next;
        }
        else {
            tmp = head;
            head = tmp->next;
        }
        delete tmp;
    }

    return key;
}

template <class T>
void LE<T>::print() {
    cout << "HEAD -> ";
    for (nodo<T>* p = head; p; p=p->next) {
        cout << p->valor << " -> ";
    }
    cout << "NULL" << endl;
}


int main() {
    LE<int> list;
    list.add(1);
    list.add(3);
    list.add(5);
    list.del(5);
    list.print();

    return 0;
}