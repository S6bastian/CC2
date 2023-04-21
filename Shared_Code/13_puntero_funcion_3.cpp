#include <iostream>

using namespace std;

int suma(int a, int b)
{ return a+b;}

int resta(int a, int b)
{ return a-b;}

typedef int (*PF)(int,int);

int main() {
  PF pf[2] = {suma,resta};
  
  int a[] = {7,2,8,9,4,6,5,1,3,9};
  int b[] = {0,0,1,1,0,1,1,0,1,0};
  int res = 0;

  for(int i = 0; i<10; i++)
  {
    res = pf[b[i]](res,a[i]);
    cout<<res<<endl;
  }

}