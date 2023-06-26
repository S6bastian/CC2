#include <iostream>

using namespace std;

int main() {
  int mat,fil,col;
  int ***p;

  cout<<"Ingrese la cantidad de matrices ";
  cin>>mat;

  cout<<"Ingrese la cantidad de filas ";
  cin>>fil;

  cout<<"Ingrese la cantidad de columnas ";
  cin>>col;

  p = new int**[mat];
  
  for(int i = 0; i<mat;i++)
  {
    p[i] = new int*[fil];
    for(int j=0; j<fil;j++)
      p[i][j] = new int[col];
  }
  
    
  for(int i=0;i<mat;i++)
    for(int j=0; j<fil; j++)
       for(int k=0; k<col; k++)
     p[i][j][k] = i*1000+j*100+k;

  cout<<endl<<"impresión con índices"<<endl;
  for(int i=0;i<mat;i++)
  {
    for(int j=0; j<fil; j++)
    {
       for(int k=0; k<col; k++)
          cout<<p[i][j][k]<<" ";
       cout<<endl;
    } 
    cout<<endl;
  }

cout<<endl<<"impresión con punteros"<<endl;
for(int ***pt=p;pt<p+mat;pt++)
  {
    for(int **qt= *pt; qt < *pt+fil; qt++)
    {
       for(int *rt=*qt; rt< *qt+col; rt++)
          cout<<*rt<<" ";
       cout<<endl;
    } 
    cout<<endl;
  }

for(int i = 0; i<mat;i++)
  {
    for(int j=0; j<fil;j++)
       delete [] p[i][j];
    delete [] p[i];
  }

delete [] p;
}

/*OUTPUT

Ingrese la cantidad de matrices 3
Ingrese la cantidad de filas 2
Ingrese la cantidad de columnas 4

impresi├│n con ├¡ndices
0 1 2 3
100 101 102 103

1000 1001 1002 1003
1100 1101 1102 1103

2000 2001 2002 2003
2100 2101 2102 2103


impresi├│n con punteros
0 1 2 3
100 101 102 103

1000 1001 1002 1003
1100 1101 1102 1103

2000 2001 2002 2003
2100 2101 2102 2103

*/