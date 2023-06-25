#include <iostream>

using namespace std;

template<class T, int n=0>
class suma
{
  T priv_x = n;
  public:
  //suma(T x):priv_x(x){};
  T operator()(T operador)
  {
    return priv_x+operador;
  }
};

template<class O>
class Ejecuta
{
  public:
    O operador;
};

int main() {
  suma<int> objSuma;
  cout<<objSuma(5)<<endl;

  Ejecuta<suma<int,20>> exe;
  cout<<exe.operador(15)<<endl;
}