#include <iostream>

using namespace std;

template <class T>
class nodo
{
  public:
  T valor;
  nodo* next;
  nodo(T v, nodo* n=nullptr)
  { 
    valor = v;
    next = n;
  }
};

template <class T>
class LE
{
  nodo<T> * head=nullptr;

  public:
  void print();
  bool find(T v,nodo<T> *&pos);
  void add(T v);
  void del(T v);
  ~LE();
};

template <class T>
void LE<T>::print()
{
  cout<<"Head->";
  for(nodo <T>* p=head;p;p = p->next)
      cout<<p->valor<<"->";
  cout<<"NULL"<<endl;   
}

template <class T>
bool LE<T>::find(T v, nodo<T> *&pos)
{
  bool encontrado =false;
  pos = nullptr;

  for(nodo<T>* p =head;p && p->valor<=v;p=p->next)
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

template <class T>
void LE<T>::add(T v)
{
  nodo<T>* pos_ant;
  if(!find(v,pos_ant))
  {
     if(pos_ant)
       pos_ant->next = new nodo(v,pos_ant->next);
     else
      head = new nodo(v,head);
  }
}

template <class T>
void LE<T>::del(T v)
{
  nodo<T> *pos_ant,*pos_del;
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

template <class T>
LE<T>::~LE()
{
 /* cout<<"Destruyendo lista..."<<endl;
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
  LE<int> lista;
  
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

  cout<<"------------------------"<<endl;

  LE<char> listaChar;
  
  listaChar.print();
  listaChar.add('g');
  listaChar.print();
  listaChar.add('a');
  listaChar.print();
  listaChar.add('d');
  listaChar.print();
  listaChar.add('z');
  listaChar.print();
  listaChar.add('d');
  listaChar.print();

  listaChar.del('d');
  listaChar.print();
  listaChar.del('d');
  listaChar.print();
  listaChar.del('z');
  listaChar.print();
  listaChar.del('a');
  listaChar.print();
  listaChar.del('g');
  listaChar.print();

}

/*OUTPUT

Head->NULL
Head->5->NULL
Head->1->5->NULL
Head->1->3->5->NULL
Head->1->3->5->7->NULL
Head->1->3->5->7->NULL
Head->1->5->7->NULL
Head->1->5->7->NULL
Head->1->5->NULL
Head->5->NULL
Head->NULL
------------------------
Head->NULL
Head->g->NULL
Head->a->g->NULL
Head->a->d->g->NULL
Head->a->d->g->z->NULL
Head->a->d->g->z->NULL
Head->a->g->z->NULL
Head->a->g->z->NULL
Head->a->g->NULL
Head->g->NULL
Head->NULL

*/