#include <iostream>

using namespace std;

class suma
{
  int x;
  public:
  suma(int a):x(a) {};
  int operator() (int b)
  { return x+b;}
};

template <class T>
class fibo
{
  public:
  void operator() (int *p, T op)
  {
    *p = *(p+1);
    *(p+1) = op(*p);
  }

};

int main() {
  int a[2] ={0,1};
  fibo <suma> f;

  for(int i = 0; i<10; i++)
  {
    cout<<*a<<" ";
    f(a,suma(*a));
  }
}