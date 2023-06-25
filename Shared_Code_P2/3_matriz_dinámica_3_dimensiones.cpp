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