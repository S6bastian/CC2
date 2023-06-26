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

/*OUTPUT

Functor suma
5
10
Functor mult
6
16
Tabla suma de 5
s(1) = 6
s(2) = 7
s(3) = 8
s(4) = 9
s(5) = 10
s(6) = 11
s(7) = 12
s(8) = 13
s(9) = 14
s(10) = 15
Tabla suma de 7
s(1) = 8
s(2) = 9
s(3) = 10
s(4) = 11
s(5) = 12
s(6) = 13
s(7) = 14
s(8) = 15
s(9) = 16
s(10) = 17
Tabla mult de 5
s(1) = 5
s(2) = 10
s(3) = 15
s(4) = 20
s(5) = 25
s(6) = 30
s(7) = 35
s(8) = 40
s(9) = 45
s(10) = 50
Tabla mult de 7
s(1) = 7
s(2) = 14
s(3) = 21
s(4) = 28
s(5) = 35
s(6) = 42
s(7) = 49
s(8) = 56
s(9) = 63
s(10) = 70
Tabla suma de 5
s(1) = 6
s(2) = 7
s(3) = 8
s(4) = 9
s(5) = 10
s(6) = 11
s(7) = 12
s(8) = 13
s(9) = 14
s(10) = 15
Tabla mult de 7
s(1) = 7
s(2) = 14
s(3) = 21
s(4) = 28
s(5) = 35
s(6) = 42
s(7) = 49
s(8) = 56
s(9) = 63
s(10) = 70
8
13

*/