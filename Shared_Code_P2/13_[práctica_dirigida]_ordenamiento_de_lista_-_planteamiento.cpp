#include <iostream>

using namespace std;

struct asc
{
  bool operator()(int a, int b)
  {return a<b;}
};

struct desc
{
  bool operator()(int a, int b)
  {return a>b;}
};

struct nodo
{
  int valor;
  nodo * next;
  nodo(int v, nodo* n=nullptr)
  { valor = v; next=n;}
};

void crear(int *p, nodo*& lista)
{
  lista = new nodo(*p);
  p++;
   for(nodo* n =lista;*p>0;p++,n=n->next)
     n->next = new nodo(*p);
     
}

void print(nodo *lista)
{
  cout<<"lista -> ";
  for(;lista;lista=lista->next)
     cout<<lista->valor<<" -> ";
  cout<<"NULL"<<endl;
}

template<typename T>
void ordenar(nodo*& lista, T comp)
{
  //por hacer
}

int main() {
  int A[] = {7,7,27,7,12,9,18,9,8,7,-1};
  nodo *miLista;

  crear(A,miLista);
  print(miLista);

  //orden asc
  ordenar(miLista,asc());
  print(miLista);

//orden desc
  ordenar(miLista,desc());
  print(miLista);

}