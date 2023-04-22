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
    arr2.push(1);
    arr2.push(2);
    arr2.push(3);
    arr2.print();
    cout<<"Popped:"<<arr2.pop()<<endl;
    arr2.push(4);
    arr2.print();
    arr2.push(5);
    arr2.push(6);
    arr2.push(7);
    arr2.push(8);
    arr2.push(9);
    arr2.push(10);
    arr2.push(11);
    arr2.push(12);
    arr2.push(13);
    arr2.print();
    cout<<"Popped:"<<arr2.pop()<<endl;
    arr2.push(14);
    arr2.print();
    arr2.push(15);
    cout<<"Popped:"<<arr2.pop()<<endl;
    cout<<"Popped:"<<arr2.pop()<<endl;
    cout<<"Popped:"<<arr2.pop()<<endl;
    cout<<"Popped:"<<arr2.pop()<<endl;
    cout<<"Popped:"<<arr2.pop()<<endl;
    cout<<"Popped:"<<arr2.pop()<<endl;
    cout<<"Popped:"<<arr2.pop()<<endl;
    cout<<"Popped:"<<arr2.pop()<<endl;
    cout<<"Popped:"<<arr2.pop()<<endl;
    arr2.print();
    cout<<"Popped:"<<arr2.pop()<<endl;
    cout<<"Popped:"<<arr2.pop()<<endl;
    arr2.print();
    arr2.push(500);
    arr2.print();

    cout<<"----------------------------------"<<endl;

    return 0;
}
