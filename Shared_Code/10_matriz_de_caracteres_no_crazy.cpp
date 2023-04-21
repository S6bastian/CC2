#include <iostream>

using namespace std;

void crazy(char (*p)[5], int tam)
{
  char tmp;
  for(char (*q)[5] = p; q < p+tam; q++)
  {
    for(char *ini = *q,*fin = *q+3; ini < fin; ini++, fin--)
    {
      tmp = *ini;
      *ini = *fin;
      *fin = tmp;
    }
  }

}

int main() {
  char A[][5] = {"Hugo","Paco","Luis"};
  
  for(char (*p)[5] = A; p < A+3; p++)
      cout<<*p<<endl;
  
  crazy(A,3);
  cout<<"---------------"<<endl;
  for(char (*p)[5] = A; p < A+3; p++)
      cout<<*p<<endl;

}
