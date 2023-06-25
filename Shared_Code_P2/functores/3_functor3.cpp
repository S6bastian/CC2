#include <iostream>
using namespace std;

template<class t>
class funct
{
   t x;
   public:
   funct(t a)
    {
      x=a;
      //cout<<"estoy en el constructor"<<endl;
    }

  t operator()(t b)
  {
    return x+b;
  }
  
};


class funct1
{
   int x;
   public:
  /* funct1(int a)
    {
      x=a;
      //cout<<"estoy en el constructor"<<endl;
    }*/

  funct1(int a):x(a) {};

  int operator()(int b)
  {
    return x*b;
  }
  
};

template<class T>
void tabla(funct<T> a)
{
  for(int i =1; i<=10; i++)
    cout<<"Con "<<i<<" = "<<a(i)<<endl;
}

template<class T>
void tabla2(T a)
{
  for(int i =1; i<=10; i++)
    cout<<"Con "<<i<<" = "<<a(i)<<endl;
}

int main() {

  funct<int> f(8);
  cout<< f(3)<<endl;
  cout<< f.operator()(42)<<endl;

  tabla(f);
  cout<<"==========================="<<endl;
  tabla(funct<int>(9));
   cout<<"==========================="<<endl;
  tabla2(funct<int>(10));
  cout<<"==========================="<<endl;
  tabla2(funct1(10));

  int a[] = {0,1};
  for(int i=0;i<10;i++)
    {
      cout<<*a<<" ";
      funct<int> ff(*a);
      *a = *(a+1);
      *(a+1)=ff(*(a+1));
    }
    
}