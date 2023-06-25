#include <iostream>

using namespace std;

class nodo
{
  public:
  int valor;
  nodo* next;
  nodo(int v, nodo* n=nullptr)
  { 
    valor = v;
    next = n;
  }
};

class LE
{
  nodo* head=nullptr;

  public:
  void print();
  bool find(int v,nodo *&pos);
  void add(int v);
  void del(int v);
  ~LE();
};

void LE::print()
{
  cout<<"Head->";
  for(nodo* p=head;p;p = p->next)
      cout<<p->valor<<"->";
  cout<<"NULL"<<endl;   
}

bool LE::find(int v, nodo *&pos)
{
  bool encontrado =false;
  pos = nullptr;

  for(nodo* p =head;p && p->valor<=v;p=p->next)
  {
    if(p->valor == v)
      {
        encontrado = true;
        break;
      }
    pos = p;
  }
  return encontrado;
}

void LE::add(int v)
{
  nodo* pos_ant;
  if(!find(v,pos_ant))
  {
     if(pos_ant)
       pos_ant->next = new nodo(v,pos_ant->next);
     else
      head = new nodo(v,head);
  }
}

void LE::del(int v)
{
  nodo *pos_ant,*pos_del;
  if(find(v,pos_ant))
  {
    if(pos_ant)
    {
      pos_del = pos_ant->next;
      pos_ant->next = pos_del->next; //pos_ant->next = pos_ant->next->next;
      delete pos_del;
    }
    else
    {
      pos_del = head;
      head = pos_del->next; //head = head->next;
      delete pos_del;
    }
  }
}

LE::~LE()
{
  /*cout<<"Destruyendo lista..."<<endl;
  while(head)
 { 
   cout<<head->valor<<" ";  
    del(head->valor);
 }
 cout<<endl<<"Lista destruida";*/
 while(head)
   del(head->valor);
}

int main() {
  LE lista;
  
  lista.print();
  lista.add(5);
  lista.print();
  lista.add(1);
  lista.print();
  lista.add(3);
  lista.print();
  lista.add(7);
  lista.print();
  lista.add(3);
  lista.print();

  lista.del(3);
  lista.print();
  lista.del(3);
  lista.print();
  lista.del(7);
  lista.print();
  lista.del(1);
  lista.print();
  lista.del(5);
  lista.print();

}