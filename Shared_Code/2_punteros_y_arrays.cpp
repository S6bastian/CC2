#include <iostream>

using namespace std;

void func(int A[5])
{
  cout<<"dentro de func ********"<<endl;
  cout<<"size of func "<<sizeof(A)<<endl;

  cout<<"imprimo A "<<A<<endl;
  cout<<"imprimo *A "<<*A<<endl;
  cout<<"imprimo *A+1 "<<*A+1<<endl;
  cout<<"imprimo *(A+1) "<<*(A+1)<<endl;
  cout<<"imprimo *(A+3) "<<*(A+3)<<endl;

  A++;
  cout<<"imprimo *A "<<*A<<endl;

  cout<<"fin func ****"<<endl;
}

int main() {
  int A[5]={1,3,5,7,9};
  cout<<"size of main "<<sizeof(A)<<endl;
  func(A);
  
  cout<<"imprimo A "<<A<<endl;
  cout<<"imprimo *A "<<*A<<endl;
  cout<<"imprimo *A+1 "<<*A+1<<endl;
  cout<<"imprimo *(A+1) "<<*(A+1)<<endl;
  cout<<"imprimo *(A+3) "<<*(A+3)<<endl;

  //A++; no se puede porque un array no es un puntero, aunque se comporte como un puntero
  cout<<"imprimo *A "<<*A<<endl;

}
