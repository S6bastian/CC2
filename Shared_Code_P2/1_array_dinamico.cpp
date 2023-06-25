#include <iostream>

using namespace std;

int main() {
  int n;
  int *p;

  cout<<"Ingrese la cantidad de elementos ";
  cin>>n;

  p = new int[n];

  for(int i=0;i<n;i++)
     p[i] = i+10;
  
  for(int *pt = p; pt<p+n;pt++)
     cout<<*pt<<" ";
  
  delete []p;
}