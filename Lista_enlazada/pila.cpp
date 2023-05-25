#include <iostream>

using namespace std;

struct nodo{
    int valor;
    nodo *next;
    nodo(int v, nodo *n=nullptr){
        valor=v;
        next=n;
    }
};

struct pila{
    nodo *top=nullptr;

    void push(int v);
    bool pop(int &v);
};

void pila::push(int v){
    top=new nodo(v,top);
}

bool pila::pop(int &v){
    bool RES=false;
    if(top){
        v=top->valor;
        nodo *tmp=top;
        top=top->next;
        delete tmp;
        RES=true;
    }
    return RES;
}

int main(){
    pila p;
    p.push(1);
    p.push(2);
    p.push(3);

    int x;
    bool cont=true;
    while(cont){
        cont=p.pop(x);
        if(cont)
            cout<<x<<endl;
    }
}


/* OUTPUT

3
2
1

*/