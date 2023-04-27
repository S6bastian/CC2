#include <iostream>

using namespace std;

void swap(int *a, int *b)
{
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

void orden(int *A,int Tam)
{
  int *PM;
  for(int *p = A; p < A+Tam; p++)
  { 
    PM = p;
    for(int *q=p; q < A+Tam; q++)
       if( *q < *PM)
           PM = q;
    swap(p,PM);
  }
}

int main() {
  int A[10] = {1,5,9,7,5,3,2,6,4,8};
  
  cout<<"Sin ordenar"<<endl;
  for(int *p = A; p < A+10; p++)
     cout<< *p <<endl;
  
  orden(A,10);
  cout<<"Ordenado"<<endl;
  for(int *p = A; p < A+10; p++)
     cout<< *p <<endl;
  
}

/*OUTPUT

Sin ordenar
1
5
9
7
5
3
2
6
4
8
Ordenado   
1
2
3
4
5
5
6
7
8
9

*/