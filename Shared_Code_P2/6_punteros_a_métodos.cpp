#include <iostream>

using namespace std;

class Foo
{
  public:
  int add(int i, int j)
  { return i+j;}

  int mult(int i,int j)
  { return i*j;}

  static int negate(int i)
  { return -i;}
};

int bar1(int i, int j,Foo *pFoo, int (Foo::*pFn)(int,int))
{ 
  return (pFoo->*pFn)(i,j);
};

typedef int(Foo::*Foo_pFn)(int, int);

int bar2(int i, int j,Foo *pFoo,Foo_pFn pFn)
{
  return(pFoo->*pFn)(i,j);
};

int bar3(int i, int(*pfn)(int))
{ return pfn(i);};

typedef int(*pFn)(int);

int bar4(int i, pFn pfn)
{ return pfn(i);}

int main() {
  Foo foo;
  cout<<"Prueba de bar1 "<<endl;
  cout<<"Foo::add(2,4) = "<<bar1(2,4, &foo, &Foo::add)<<endl;
  cout<<"Foo::mult(2,4) = "<<bar1(2,4,&foo, &Foo::mult)<<endl;
  cout<<"Prueba de bar2"<<endl;
  cout<<"Foo::add(3,5) = "<<bar2(3,5,&foo,&Foo::add)<<endl;
  cout<<"Foo::mult(3,5) = "<<bar2(3,5,&foo,&Foo::mult)<<endl;
  cout<<"Prueba de bar3"<<endl;
  cout<<"Foo::negate(6) = "<<bar3(6,&Foo::negate)<<endl;
  cout<<"Prueba de bar4"<<endl;
  cout<<"Foo::negate(-6) = "<<bar4(-6,&Foo::negate)<<endl;

}

/*OUTPUT

Prueba de bar1 
Foo::add(2,4) = 6
Foo::mult(2,4) = 8
Prueba de bar2
Foo::add(3,5) = 8
Foo::mult(3,5) = 15
Prueba de bar3
Foo::negate(6) = -6
Prueba de bar4
Foo::negate(-6) = 6

*/