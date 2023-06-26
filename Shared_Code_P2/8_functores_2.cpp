#include <iostream>

using namespace std;

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

template <class T>
class operador
{
  public:
  void op(T opr)
  {
    for(int i=1;i<=10;i++)
    cout<<"opr("<<i<<") = "<<opr(i)<<endl;
  }
};

template <class T,int N>
class operador1
{   
  T opr = T(N);
  public:
  
  void op()
  {
    for(int i=1;i<=10;i++)
    cout<<"opr("<<i<<") = "<<opr(i)<<endl;
  }
};

int main() {
  operador<suma> a1;
  operador<mult> a2;

  operador1<suma,5> b1;
  operador1<mult,5> b2;
  
  cout<<"Tabla de la suma de 5"<<endl;
  a1.op(suma(5));

  cout<<"Tabla de la multiplicación de 5"<<endl;
  a2.op(mult(5));

  cout<<"Tabla de la suma de 5"<<endl;
  b1.op();

  cout<<"Tabla de la mult de 5"<<endl;
  b2.op();
}

/*OUTPUT

Tabla de la suma de 5
opr(1) = 6
opr(2) = 7
opr(3) = 8
opr(4) = 9
opr(5) = 10
opr(6) = 11
opr(7) = 12
opr(8) = 13
opr(9) = 14
opr(10) = 15
Tabla de la multiplicaci├│n de 5
opr(1) = 5
opr(2) = 10
opr(3) = 15
opr(4) = 20
opr(5) = 25
opr(6) = 30
opr(7) = 35
opr(8) = 40
opr(9) = 45
opr(10) = 50
Tabla de la suma de 5
opr(1) = 6
opr(2) = 7
opr(3) = 8
opr(4) = 9
opr(5) = 10
opr(6) = 11
opr(7) = 12
opr(8) = 13
opr(9) = 14
opr(10) = 15
Tabla de la mult de 5
opr(1) = 5
opr(2) = 10
opr(3) = 15
opr(4) = 20
opr(5) = 25
opr(6) = 30
opr(7) = 35
opr(8) = 40
opr(9) = 45
opr(10) = 50

*/