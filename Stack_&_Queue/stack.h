#include <iostream>

class stack{
    int A[10];
    int *inicio=A, *fin=A+9, *top=nullptr;

    public:
        void push(int v);
        int pop();
        void print();
};

void stack::push(int v){

    if (!top){  //Al ser nullptr (lista vacia) será 0
        top=inicio;
        *top=v;
    }
    else if(top<fin){
        top++;
        *top=v;
    }
    else{
        std::cout<<"Pila llena"<<std::endl;
    }
}

int stack::pop(){
    int tmp=0;

    if(top){
        tmp=*top;
        top--;
        if(top<inicio){
            top=nullptr;
        }
        else{
            std::cout<<"Pila vacia"<<std::endl;
        }
        *top=0;
    }
    return tmp;
}

void stack::print(){
    std::cout<<"[ ";
    for(int *i=A; i<=A+9; i++){
        std::cout<<*i<<" ";
    }
    std::cout<<"]"<<std::endl;
}