#include <iostream>

using namespace std;

int main() {
  char A[][5] = {"Hugo","Paco","Luis"};

  cout<<A<<endl;  //A es un char **
  cout<<*A<<endl;  //*A es un char *
  cout<<**A<<endl; //**A es un char

  cout<<*(*A+1)<<endl; //u
  cout<<*A<<endl; //Hugo
  cout<<(*A+1)<<endl; //ugo

  cout<<*(A+1)<<endl; //Paco
  cout<<(*A+1)<<endl; //ugo

  cout<<*(A+2)<<endl; //Luis
  cout<<(*A+2)<<endl; //go

  cout<<(*A+8)<<endl; //o

  cout<<(*A+11)<<endl; //uis
  cout<<*(A+2)+1<<endl; //uis
  cout<<(*A+2)+1<<endl; //o
  cout<<(*A+1)+1<<endl; //go
  cout<<*(*(A+1)+2)<<endl; //c
  cout<< *(*A+7)<<endl; //c

  cout<<**A+7<<endl;
  cout<<**A<<endl;
  cout<<**A+1<<endl; 
  cout<<(char)(**A+1)<<endl;

}
