#include <iostream>

using namespace std;

int suma(int a, int b)
{ return a+b;}

int mult(int a, int b)
{ return a*b;}

int main() {
  int (*pf) (int, int);

  pf = &suma;
  cout<<(*pf)(5,3)<<endl;
  cout<<pf(5,3)<<endl;

  pf = mult;
  cout<< pf(5,3)<<endl;
  cout<< (*pf)(5,3)<<endl;

}
