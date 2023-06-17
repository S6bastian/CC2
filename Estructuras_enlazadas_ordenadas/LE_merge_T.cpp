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


template <class T>
void merge(nodo<T> *&H1, nodo<T> *&H2){
    nodo<T> *ap1, *p1, *p2;
    ap1 = H1;
    p1 = ap1->next;
    p2 = H2;
    while(H2){
        if(p2->valor < H1->valor){
            H2 = p2->next;
            H1 = p2;
            p2->next = ap1;
            ap1 = H1;
            p1 = ap1->next;
            p2 = H2;
        }
        else if(p2->valor >= ap1->valor && p2->valor < p1->valor){
            H2 = p2->next;
            ap1->next = p2;
            p2->next = p1;
            ap1 = p2;
            p2 = H2;
        }
        
        else{
            ap1 = ap1->next;
            p1 = p1->next;
            if(p1 == nullptr){
                break;
            }
        }
    }
    if(p2->valor >= ap1->valor && p1 == nullptr && p2 != nullptr){
        ap1->next = p2;
        H2 = nullptr;
    }
}


int main() {
    LE<int> H1;
    LE<int> H2;
    H1.add(2);
    H1.add(4);
    H1.add(6);
    H1.add(8);
    H1.add(10);
    H2.add(3);
    H2.add(6);
    H2.add(9);

    H1.add(3);
    H2.add(0);
    H2.add(1);
    H2.add(4);
    H2.add(23);

    H1.print();
    H2.print();
    cout<<endl;

    merge(H1.head, H2.head);

    H1.print();
    H2.print();

    return 0;
}