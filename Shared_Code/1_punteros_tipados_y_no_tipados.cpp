#include <iostream>

using namespace std;

int main() {
  int a=65;
  int *p=&a;
  char *q = (char*)p;
  void *r = p;

  cout<<*p<<endl;
  cout<<*q<<endl;

  *(q+1)='@';
  cout<<*(q+1)<<endl;
  cout<<*p<<endl;
  
  //No se puede dereferenciar un puntero void
  //cout<<*r<<endl;

  //es necesario hacer un cast
  cout<<*((int*)r)<<endl;

  //no se puede aplicar aritmetica de punteros a un void
  //r = r+1;

  //es necesario hacer un cast
  cout<<*((int*)r+1)<<endl; 

  int *s = (int*)r+1;
  cout<<*s<<endl;
  cout<<*(s-1)<<endl;
  
  char *t = (char*)r+1;
  cout<<*t<<endl;
  cout<<*(t-1)<<endl;

  char b = *t;
  *t = *(t-1);
  *(t-1) = b;

  cout<<a<<endl;

}
