#include <iostream>

using namespace std;

int suma(int a, int b)
{ return a+b;}

int mult(int a, int b)
{ return a*b;}

void tabla(int a, int (*pf)(int, int))
{
  cout<<"La tabla del "<<a<<endl;
  for(int i=1;i<=10;i++)
  {
    cout<<"Con "<<i<<" = "<<pf(a,i)<<endl;
  }
}

typedef int (*PF) (int, int);
void tabla2(int a, PF pf)
{
  cout<<"La tabla del "<<a<<endl;
  for(int i=1;i<=10;i++)
  {
    cout<<"Con "<<i<<" = "<<pf(a,i)<<endl;
  }
}

int main() {
  int (*pf) (int, int);
  
  cout<<"Con suma"<<endl;
  tabla(2,suma);
  
  cout<<endl<<"Con multiplicacion"<<endl;
  tabla(2,mult);

  cout<<"Con suma"<<endl;
  tabla2(3,suma);
  
  cout<<endl<<"Con multiplicacion"<<endl;
  tabla2(3,mult);

}
