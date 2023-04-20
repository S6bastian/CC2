#include<iostream>

class queue{
    int A[10];
    int *inicio=A, *fin=A+9, *head=nullptr, *tail=nullptr;

    public:
        void push(int v);
        int pop();
        void print();
};

void queue::push(int v){
    if (!head){  //Al ser nullptr (lista vacia) será 0
        head=inicio;
        tail=inicio;
        *tail=v;
    }
    else{
        tail++;

        if(tail==fin+1){
            tail=inicio;
        }

        if(tail==head){
            std::cout<<"Pila llena"<<std::endl;
            tail--;
        }
        else{
            *tail=v;
        }
    }
}

int queue::pop(){
    int tmp=0;

    if(!head){
        std::cout<<"Pila vacia"<<std::endl;
    }
    else{
        tmp=*head;
        head++;
        
        if(head==fin+1){
            head=inicio;
        }

        if(head==tail+1 || (tail==fin && head==inicio)){
            std::cout<<"Pila vacia"<<std::endl;
            head--;
            tmp=0;
        }
    }

    return tmp;
}

void queue::print(){
    std::cout<<"[ ";
    for(int *i=A; i<=A+9; i++){
        std::cout<<*i<<" ";
    }
    std::cout<<"]"<<std::endl;
}