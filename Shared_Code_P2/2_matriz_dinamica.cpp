#include <iostream>

using namespace std;

int main() {
  int fil,col;
  int **p;

  cout<<"Ingrese la cantidad de filas ";
  cin>>fil;

  cout<<"Ingrese la cantidad de columnas ";
  cin>>col;

  p = new int*[fil];
  
  for(int i = 0; i<fil;i++)
     p[i] = new int[col];
  
    
  for(int i=0;i<fil;i++)
    for(int j=0; j<col; j++)
     p[i][j] = 100*(i+1)+j;

  cout<<endl<<"impresión con índices"<<endl;
  for(int i=0;i<fil;i++)
  {
    for(int j=0; j<col; j++)
      cout<<p[i][j]<<" ";
    cout<<endl;  
  }

cout<<endl<<"impresión con punteros"<<endl;
 for(int **pt = p; pt<p+fil;pt++)
  {   for(int *qt = *pt; qt< *pt+col; qt++)
          cout<<*qt<<" ";
     cout<<endl;  
  }
  
  for(int i = 0; i<fil;i++)
     delete[] p[i];
  
  delete [] p;
}

/*OUTPUT

Ingrese la cantidad de filas 3
Ingrese la cantidad de columnas 4

impresi├│n con ├¡ndices
100 101 102 103        
200 201 202 203        
300 301 302 303        

impresi├│n con punteros
100 101 102 103
200 201 202 203
300 301 302 303

*/