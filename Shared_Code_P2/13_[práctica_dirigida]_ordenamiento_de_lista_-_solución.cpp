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
  nodo *p, *ap, *q, *aq, *m, *am;
  p=lista;
  ap=nullptr;

  while(p)
  {
    q=p;
    aq=ap;
    m=p;
    am=ap;
    for(;q;aq=q,q=q->next)
    {
      if(comp(q->valor,m->valor))//(q->valor<m->valor)
      {
        m=q;
        am=aq;
      }
    }
    if(m!=p)
    {
      am->next=m->next;
      m->next=p;
      if(ap)
         ap->next=m;
      else
        lista=m;
      p=m;
    }
    else
    {
      ap=p;
      p=p->next;
    }
  }

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

/*OUTPUT

lista -> 7 -> 7 -> 27 -> 7 -> 12 -> 9 -> 18 -> 9 -> 8 -> 7 -> NULL
lista -> 7 -> 7 -> 7 -> 7 -> 8 -> 9 -> 9 -> 12 -> 18 -> 27 -> NULL
lista -> 27 -> 18 -> 12 -> 9 -> 9 -> 8 -> 7 -> 7 -> 7 -> 7 -> NULL

*/