#include <iostream>

using namespace std;

template <class T>
struct nodo {
    T valor;
    nodo <T> *next;
    nodo(T v, nodo<T>* n = nullptr) {
        valor = v;
        next = n;
    }
};


template <class T>
struct LE {    //Lista Enlazada
    nodo<T> *head=nullptr;
    nodo<T> *tail=nullptr;

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

    for (nodo<T>* p = head; p && p->valor <= x && pos != tail && key == false; p = p->next) {
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
        if(head == nullptr && tail == nullptr){
            head = new nodo<T>(x, head);
            tail = head;
        }
        else if(x < head->valor){
            head = new nodo<T>(x,head);
            tail->next = head;
        }
        else{
            pos->next = new nodo<T>(x, pos->next);
            if(pos == tail){
                tail = pos->next;
            }
        }
    }
}

template  <class T>
bool LE<T>::del(T x) {
    nodo<T>* pos, * tmp;
    bool key = find(x, pos);

    if (key) {
        if (head == tail) {
            tmp = head;
            head = nullptr;
            tail = nullptr;
        }
        else if (x == head->valor) {
            tmp = head;
            head = head->next;
            tail->next = head;

        }
        else if (x == tail->valor) {
            tmp = tail;
            tail = pos;
            tail->next = head;
        }
        else {
            tmp = pos->next;
            pos->next = tmp->next;
        }
        delete tmp;
    }

    return key;
}

template <class T>
void LE<T>::print() {
    cout << "HEAD";
    for (nodo<T> *p = head; p; p=p->next) {
        cout  << " -> " << p->valor;
        if(p == tail){
            cout  << " -> " << p->next->valor;
            break;
        }
    }
    cout << " -> ..." << endl;
}


int main() {
    LE<int> list;
    list.add(8);
    list.add(1);
    list.add(7);
    list.add(5);
    list.add(0);
    list.print();

    list.del(8);
    list.del(1);
    list.del(7);
    list.del(5);
    list.del(0);
    list.print();

    return 0;
}