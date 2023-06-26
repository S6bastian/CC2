#include <iostream>

using namespace std;

template <class T>
class suma
{
  T x;
  public:
  suma(T a):x(a){}; //{ x = a;}
  
  T operator()(T b)
  { return x+b;}
};

template <class T>
class mult
{
  T x;
  public:
  mult(T a):x(a) {};

  T operator()(T b)
  { return x*b;}
};

template <class T,class O>
class operador
{
  public:
  void op(O opr)
  {
    for(T i=1;i<=10;i++)
    cout<<"opr("<<i<<") = "<<opr(i)<<endl;
  }
};

template <class T,class O,T N>
class operador1
{   
  O opr = O(N);
  public:
  
  void op()
  {
    for(T i=1;i<=10;i++)
    cout<<"opr("<<i<<") = "<<opr(i)<<endl;
  }
};

int main() {
  operador<double,suma<double>> a1;
  operador<double,mult<double>> a2;

  operador1<int,suma<int>,5> b1;
  operador1<int,mult<int>,5> b2;
  
  cout<<"Tabla de la suma de 5"<<endl;
  a1.op(suma(5.1));

  cout<<"Tabla de la multiplicación de 5"<<endl;
  a2.op(mult(5.1));

  cout<<"Tabla de la suma de 5"<<endl;
  b1.op();

  cout<<"Tabla de la mult de 5"<<endl;
  b2.op();
}

/*OUTPUT

Tabla de la suma de 5
opr(1) = 6.1
opr(2) = 7.1
opr(3) = 8.1
opr(4) = 9.1
opr(5) = 10.1
opr(6) = 11.1
opr(7) = 12.1
opr(8) = 13.1
opr(9) = 14.1
opr(10) = 15.1
Tabla de la multiplicaci├│n de 5
opr(1) = 5.1
opr(2) = 10.2
opr(3) = 15.3
opr(4) = 20.4
opr(5) = 25.5
opr(6) = 30.6
opr(7) = 35.7
opr(8) = 40.8
opr(9) = 45.9
opr(10) = 51
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