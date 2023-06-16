/*  NOTAS
    -PROBABLEMENTE EXISTA UN MEJOR CÓDIGO
*/

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
    bool found = false;
    pos = nullptr;

    for (nodo<T>* p = head; p && pos != tail; pos = p, p = p->next) {
        if (p->valor == x) {
            if(head==p){
                pos=p;
            }
            found = true;
            break;
        }
        if (x < p->valor){
            if (head->valor > x){
                pos = p;
            }
            break;
        }
    }

    return found;
}

template <class T>
void LE<T>::add(T x) {
    nodo<T>* pos;

    if (!find(x, pos)) {
        if (pos) {
            if(head->valor > x){
                head = new nodo<T>(x,pos);
                tail->next = head;
            }
            else {
                pos->next = new nodo<T>(x, pos->next);
                
                if(tail->valor < pos->next->valor){
                    tail = pos->next;
                }
            }
        }
        else {
            head = new nodo<T>(x, head);
            head->next = head;
            tail = head;
        }
    }
}

template  <class T>
bool LE<T>::del(T x) {
    nodo<T>* pos, * tmp;
    bool key = find(x, pos);

    if (key) {
        if (head!=tail) {
            if (pos==head){
                tmp=pos;
                head=pos->next;
                tail->next=head;
            }
            else{
                tmp = pos->next;
                pos->next = tmp->next;
                if (tmp==tail){
                    tail=pos;
                }
            }
            
        }
        else {
            tmp = head;
            head = nullptr;
            tail = nullptr;
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

    //list.del(8);
    list.del(1);
    //list.del(7);
    //list.del(5);
    //list.del(0);
    list.print();


    //list.print();

    return 0;
}