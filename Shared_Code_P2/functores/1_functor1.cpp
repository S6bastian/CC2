#include <iostream>
using namespace std;

class funct
{
   int x;
   public:
   funct(int a)
    {
      x=a;
      cout<<"estoy en el constructor"<<endl;
    }

  int operator()(int b)
  {
    return x+b;
  }
  
};


class funct1
{
   int x;
   public:
   funct1(int a)
    {
      x=a;
      cout<<"estoy en el constructor"<<endl;
    }

  int operator()(int b)
  {
    return x*b;
  }
  
};

void tabla(funct a)
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

  funct f(8);
  cout<< f(3);

  tabla(f);
  cout<<"==========================="<<endl;
  tabla(funct(9));
   cout<<"==========================="<<endl;
  tabla2(funct(10));
  cout<<"==========================="<<endl;
  tabla2(funct1(10));
    
}