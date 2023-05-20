#include <iostream>

using namespace std;

int main() {
  int **p = new int*[3];

  for(int i=0; i<3; i++){
      p[i] = new int[3];

      for(int j=0; j<3; j++)
        p[i][j] = (i+1)*10+j+1;
    }

  for(int i=0; i<3; i++){
      for(int j=0;j<3;j++)
        cout<<p[i][j]<<" ";
      cout<<endl;
    }

  int *q=*p;
  for(int i=0; i<9; i++, q++)
    cout<<*q<<" ";

  cout<<endl<<endl;

  for(int **i=p; i<p+3; i++){
      for(int* j=*i; j<(*i)+3; j++)
        cout<<*j<<" ";
      cout<<endl;
    }

 for(int i=0;i<3;i++)
   delete [] p[i];

  delete[] p;

}

/*OUTPUT

11 12 13 
21 22 23 
31 32 33 
11 12 13 527 972823168 527 972816720 527 0 

11 12 13 
21 22 23 
31 32 33 

*/