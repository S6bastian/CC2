#include <iostream>

using namespace std;

template <class T> //class y typename es igual
struct nodo {
    T valor;
    nodo<T> *next;
    nodo(T v, nodo<T> *n = nullptr) {
        valor = v;
        next = n;
    }
};

template <class T>
struct pila {
    nodo<T> *top=nullptr;

    void push(T v);
    bool pop(T &v);
};

template<class T>
void pila<T>::push(T v){
    top=new nodo<T>(v,top);
}

template<class T>
bool pila<T>::pop(T &v) {
    bool RES = false;
    if (top) {
        v = top->valor;
        nodo<T>* tmp = top;
        top = top->next;
        delete tmp;
        RES = true;
    }
    return RES;
}

int main() {
    pila<int> p;
    p.push(1);
    p.push(2);
    p.push(3);

    int x;
    bool cont = true;
    while (cont) {
        cont = p.pop(x);
        if (cont)
            cout << x << endl;
    }
}

/* OUTPUT

3
2
1

*/