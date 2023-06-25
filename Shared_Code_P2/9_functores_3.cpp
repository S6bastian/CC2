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