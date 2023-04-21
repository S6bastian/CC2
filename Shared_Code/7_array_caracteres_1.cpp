#include <iostream>

using namespace std;

int main() {
  char A[] = {'H','O','L','A'};
  char B[] = {"HOLA"};

  cout << "Tamaño del array A es "<<sizeof(A)<<endl;  
  cout << "Tamaño del array B es "<<sizeof(B)<<endl;

  cout<<"Esto está en B: "<<B<<"-Fin"<<endl;
  cout<<"Esto está en A: "<<A<<"-Fin"<<endl;

 for(char *p=B; *p; p++)
     cout<<*p<<endl;

  cout<<endl;

  for(char *p=A; *p; p++)
     cout<<*p<<endl;
 
}