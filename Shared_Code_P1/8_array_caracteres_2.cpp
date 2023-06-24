#include <iostream>

using namespace std;

void Invertido(char *p, char*q)
{
  char temp;
  for(;p < q;p++,q--)
  {
    temp = *p;
    *p = *q;
    *q = temp;
  }
}

void uppermio(char *p)
{
   for(;*p;p++)
   {
     if(*p>=97 && *p<=122)
         *p = *p -32;
   }
}

void lowermio(char *p)
{
   for(;*p;p++)
   {
     if(*p>='A' && *p<='Z')
         (*p)+=32;
   }
}

int main() {
  char C[] = {"Hola Mundo 123"};

  cout<<C<<endl;
  Invertido(C,&C[13]);
  cout<<C<<endl;
  Invertido(C,&C[13]);
  cout<<C<<endl;
  uppermio(C);
  cout<<C<<endl;
  lowermio(C);
  cout<<C<<endl;
}

/*OUTPUT

Hola Mundo 123
321 odnuM aloH
Hola Mundo 123
HOLA MUNDO 123
hola mundo 123

*/