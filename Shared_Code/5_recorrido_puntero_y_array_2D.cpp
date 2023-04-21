#include <iostream>

using namespace std;

void print1(int A[][5],int tam)
{
  cout<<"Recorrido dentro de print1"<<endl;
  for(int (*p)[5] = A;p<A+tam; p++)
  {
    cout<<*p<<" -> "<< **p << endl;
    for(int *q = *p; q < *(p+1);q++)
       cout<<*q<<" ";
    cout<<endl;
  }
}

void print2(int (*A)[5],int tam)
{
  cout<<"Recorrido dentro de print2"<<endl;
  for(int (*p)[5] = A;p<A+tam; p++)
  {
    cout<<*p<<" -> "<< **p << endl;
    for(int *q = *p; q < *(p+1);q++)
       cout<<*q<<" ";
    cout<<endl;
  }
}

int main() {
  //int A[2][5] = {1,2,3,4,5,6,7,8,9,0};
  int A[2][5] = {{1,2,3,4,5},{6,7,8,9,0}};
  
  cout<<"Recorrido dentro de main"<<endl;
  for(int (*p)[5] = A;p<A+2; p++)
  {
    cout<<*p<<" -> "<< **p << endl;
    for(int *q = *p; q < *(p+1);q++)
       cout<<*q<<" ";
    cout<<endl;
  }
  cout<<endl;
  print1(A,2);
  cout<<endl;
  print2(A,2);

}
