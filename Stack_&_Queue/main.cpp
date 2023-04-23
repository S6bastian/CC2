#include <iostream>
#include "stack.h"
#include "queue.h"

using namespace std;

int main(){
    cout<<"----------------------------------"<<endl;
    cout<<"----------------PILA-----------------"<<endl;

    stack arr1;
    arr1.push(1);
    arr1.push(9);
    arr1.push(15);
    arr1.print();
    cout<<"Popped:"<<arr1.pop()<<endl;
    arr1.push(23);
    arr1.print();

    cout<<"----------------------------------"<<endl;
    cout<<"----------------COLA------------------"<<endl;

    queue arr2;
    
    for(int i=1; i<15; i++){
        arr2.push(i);
    }
    for(int i=1; i<15; i++){
        arr2.pop();
    }
    for(int i=1; i<8; i++){
        arr2.push(i);
    }
    for(int i=1; i<4; i++){
        arr2.pop();
    }
    for(int i=1; i<11; i++){
        arr2.push(i);
    }
    for(int i=1; i<13; i++){
        arr2.pop();
    }

    cout<<"----------------------------------"<<endl;

    return 0;
}
