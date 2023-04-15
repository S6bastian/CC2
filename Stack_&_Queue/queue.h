#include<iostream>

class queue{
    int A[10];
    int *inicio=A, *fin=A+9, *top=nullptr;

    public:
        void push(int v);
        int pop();
        void print();
};

void queue::push(int v){
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

int queue::pop(){
    int tmp=0;
    if (top){
        tmp=*inicio;
        *inicio=0;
        for (int *i=inicio; i<top; i++){
            std::swap(*i,*(i+1));
        }
        top--;
    }
    else if (!top){
        std::cout<<"Pila vacia"<<std::endl;
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