#include <iostream>

using namespace std;

int suma(int a, int b)
{ 
  return a+b;
}

void operar(int *p, int(*pr)(int,int))
{
  int tmp;
  tmp = pr(*p,*(p+1));
  *p = *(p+1);
  *(p+1)=tmp;
}

int main() {

  int a[2] = {0,1};

  for(int i = 1;i<10;i++)
  {
    cout<<*a<<" ";
    operar(a,suma);
  }

}

/*OUTPUT

0 1 1 2 3 5 8 13 21

*/