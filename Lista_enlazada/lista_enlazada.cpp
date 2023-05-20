#include <iostream>

using namespace std;

struct nodo{
    int valor;
    nodo* next;
    nodo(int v, nodo *n=nullptr){
        valor=v;
        next=n;
    }
};

int main(){
    int A[10]={1,3,8,15,7,6,8,9,1,10};
    nodo *head=nullptr;
    nodo *tmp;

    for(int i=0; i<10; i++){
        if(!head){
            head=new nodo(A[i]);
            tmp=head;
        }
        else{
            tmp->next=new nodo(A[i]);
            tmp=tmp->next;
        }
    }

    for(nodo*p=head; p; p=p->next){
        cout<<p->valor<<"->";
    }
    cout<<"NULL"<<endl;

    return 0;
}
