#include <iostream>

using namespace std;

void print1(int A[], int tam)
{
  cout<<"Recorrido dentro de print1"<<endl;
  for(int *p = A;p<A+tam; p++)
      cout<<*p<<" ";
}

void print2(int *A, int tam)
{
  cout<<"Recorrido dentro de print2"<<endl;
  for(int *p = A;p<A+tam; p++)
      cout<<*p<<" ";
}

int main() {
  int A[10] = {1,2,3,4,5,6,7,8,9,0};
  
  cout<<"Recorrido dentro de main"<<endl;
  for(int *p = A;p<A+10; p++)
      cout<<*p<<" ";
  cout<<endl;
  print1(A,10);
  cout<<endl;
  print2(A,10);
}
