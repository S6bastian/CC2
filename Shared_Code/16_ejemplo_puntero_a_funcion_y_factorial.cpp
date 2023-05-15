#include <iostream>

using namespace std;

int suma(int a, int b)
{ 
  return a+b;
}

int mult(int a, int b)
{ 
  return a*b;
}

void operar(int *p, int(*pr)(int,int))
{
  int tmp;
  tmp = pr(*p,*(p+1));
  *p = *(p+1);
  *(p+1)=tmp;
}

int main() {

 /* int a[2] = {1,2};

  for(int i = 1;i<10;i++)
  {
    cout<<*a<<" ";
    operar(a,mult);
  }
*/
  int a[2] = {1,4};
  int t;

  for(;*(a+1)>1;)
  {
    operar(a,mult);
    t = *(a+1);
    *(a+1) = *a-1;
    *a=t;
  }
  cout<<*a<<endl;

}

/*OUTPUT

24

*/