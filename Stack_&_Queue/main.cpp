#include <iostream>
#include "stack.h"
#include "queue.h"

using namespace std;

int main(){
    cout<<"----------------------------------"<<endl;

    stack arr1;
    arr1.push(1);
    arr1.push(9);
    arr1.push(15);
    arr1.print();
    cout<<"Popped:"<<arr1.pop()<<endl;
    arr1.push(23);
    arr1.print();

    cout<<"----------------------------------"<<endl;

    queue arr2;
    arr2.push(2);
    arr2.push(8);
    arr2.push(17);
    arr2.print();
    cout<<"Popped:"<<arr2.pop()<<endl;
    arr2.push(29);
    arr2.print();

    cout<<"----------------------------------"<<endl;

    return 0;
}
