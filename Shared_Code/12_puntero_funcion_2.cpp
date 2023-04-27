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

/*OUTPUT

Con suma
La tabla del 2    
Con 1 = 3
Con 2 = 4
Con 3 = 5
Con 4 = 6
Con 5 = 7
Con 6 = 8
Con 7 = 9
Con 8 = 10        
Con 9 = 11        
Con 10 = 12       

Con multiplicacion
La tabla del 2
Con 1 = 2
Con 2 = 4
Con 3 = 6
Con 4 = 8
Con 5 = 10
Con 6 = 12
Con 7 = 14
Con 8 = 16
Con 9 = 18
Con 10 = 20
Con suma
La tabla del 3
Con 1 = 4
Con 2 = 5
Con 3 = 6
Con 4 = 7
Con 5 = 8
Con 6 = 9
Con 7 = 10
Con 8 = 11
Con 9 = 12
Con 10 = 13

Con multiplicacion
La tabla del 3
Con 1 = 3
Con 2 = 6
Con 3 = 9
Con 4 = 12
Con 5 = 15
Con 6 = 18
Con 7 = 21
Con 8 = 24
Con 9 = 27
Con 10 = 30

*/