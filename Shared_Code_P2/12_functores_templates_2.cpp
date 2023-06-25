#include <iostream>

using namespace std;

template <class T>
class suma
{
  T valor;
  public:
  suma(T v):valor(v){};
  T operator()(T x)
  { return valor+x;} 
};

template <class T, int n=0>
class suma2
{
  T valor;
  public:
  suma2():valor(n){};
  T operator()(T x)
  { return valor+x;} 
};

template <class T>
class resta
{
  T valor;
  public:
  resta(T v):valor(v){};
  T operator()(T x)
  { return valor-x;} 
};

int funcion(suma<int> opera,int n=0)
{
  return opera(n);
}

template <class T>
int funcion2(T opera,int n=0)
{
   return opera(n);
}

template<class T, class O>
class opera
{
  public:
  T op(O operador,T val)
  { return operador(val);}
};

template<class T, class O>
class opera2
{
  O operador;
  public:
  T op(T val)
  { return operador(val);}
};

int main() {
  suma<int> s(5);  
  resta<int> r(15);
  opera<int,suma<int> > gg;
  opera2<int,suma2<int,15> > gg2;

  cout << s(13)<<endl;
  cout << r(13)<<endl;
  cout<<funcion(suma<int>(8),9)<<endl;
  cout<<funcion2(suma<int>(8),9)<<endl;
  cout<<funcion2(resta<int>(8),9)<<endl;
  cout<<funcion2(s,9)<<endl;
  cout<<funcion2(r,9)<<endl;
  cout<<gg.op(suma<int>(13),7)<<endl;
  cout<<gg.op(s,7)<<endl;
  cout<<gg2.op(7)<<endl;
}