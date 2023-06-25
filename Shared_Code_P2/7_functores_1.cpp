#include <iostream>

using namespace std;

//functores
class suma
{
  int x;
  public:
  suma(int a):x(a){}; //{ x = a;}
  
  int operator()(int b)
  { return x+b;}
};

class mult
{
  int x;
  public:
  mult(int a):x(a) {};

  int operator()(int b)
  { return x*b;}
};

//----------------------------------
class suma2
{
  int x;
  public:
  suma2(int a):x(a){}; //{ x = a;}
  
  int operator()(int b)
  { return x+b;}

  void operator = (const suma2 &S ) { 
        x = S.x;}
};

void func1(suma s)
{
  for(int i=1;i<=10;i++)
    cout<<"s("<<i<<") = "<<s(i)<<endl;
}

void func2(mult s)
{
  for(int i=1;i<=10;i++)
    cout<<"s("<<i<<") = "<<s(i)<<endl;
}

template<class T>
void func3(T s)
{
  for(int i=1;i<=10;i++)
    cout<<"s("<<i<<") = "<<s(i)<<endl;
}

int main() {

  suma s1(2); //llamando al constructor
  mult m1(2);
  suma2 s2(5);

  cout<<"Functor suma"<<endl;
  cout<<s1(3)<<endl;
  cout<<s1(8)<<endl;
  cout<<"Functor mult"<<endl;
  cout<<m1(3)<<endl;
  cout<<m1(8)<<endl;
  cout<<"Tabla suma de 5"<<endl;
  func1(suma(5));
  cout<<"Tabla suma de 7"<<endl;
  func1(suma(7));
  cout<<"Tabla mult de 5"<<endl;
  func2(mult(5));
  cout<<"Tabla mult de 7"<<endl;
  func2(mult(7));
  cout<<"Tabla suma de 5"<<endl;
  func3(suma(5));
  cout<<"Tabla mult de 7"<<endl;
  func3(mult(7));

  cout<<s2(3)<<endl;
  s2=10;
  cout<<s2(3)<<endl;

}