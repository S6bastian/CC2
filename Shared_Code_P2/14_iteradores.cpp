#include <iostream>

using namespace std;

template <class T>
class Iterator
{
  T *it;
  public:
  void operator =(T *valor)
  {it = valor;}

  void operator =(T valor)
  { *it = valor;}

  T* operator++(int)
  {
    it++;
    return it;
  }

  T operator*()
  { return *it;}

  bool operator<=(T* otro)
  { return it<=otro;}

 friend istream& operator>>(istream &input, Iterator D)
 {
   input>>(*D.it);
   return input;
 }

};

template <class T, class I>
class Vector
{
  T a[10];

  public:
  typedef I it_vector;

  T* begin()
  { return &a[0];}

  T* end()
  { return &a[9];}

};

int main() {
  Vector<int,Iterator<int>> Ent;
  Vector<int,Iterator<int>>::it_vector It;

  int x=100;
  for(It=Ent.begin();It<=Ent.end();It++)
  {   
    It=x;
    x+=100;
  }

  for(It=Ent.begin();It<=Ent.end();It++)
  {   
    cout<<*It<<endl;
  }

  cout<<"-----------------"<<endl;

  for(It=Ent.begin();It<=Ent.end();It++)
  {   
    cout<<"Ingrese un número entero: ";
    cin>>It;
  }

  for(It=Ent.begin();It<=Ent.end();It++)
  {   
    cout<<*It<<endl;
  }

}