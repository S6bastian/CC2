#include <iostream>

using namespace std;

template <class T>
struct Iterator
{
    T *it;

    void operator=(T *valor)
    {
        it = valor;
    }

    void operator=(T valor)
    {
        it->valor = valor.valor;
    }

    T *operator++(int)
    {
        return it = it->next;
    }

    T operator*()
    {
        return *it;
    }

    bool operator--(int)
    {
        return it->next == nullptr;
    }

    friend istream &operator>>(istream &input, Iterator D)
    {
        input >> (*D.it);
        return input;
    }
    friend ostream &operator<<(ostream &output, Iterator D)
    {
        output << (D.it->valor);
        return output;
    }
};

template <class T>
struct nodo
{
    T valor;
    nodo<T> *next;
    nodo(T v, nodo<T> *n = nullptr)
    {
        valor = v;
        next = n;
    }
};

template <class T, class I>
struct LE
{ // Lista Enlazada
    typedef I it_vector;
    nodo<T> *head = NULL;

    nodo<T> *begin()
    {
        return head;
    }

    bool find(T x, nodo<T> *&pos);
    void add(T x);
    bool del(T x);
    void print();
    //~LE();
};

template <class T, class I>
bool LE<T, I>::find(T x, nodo<T> *&pos)
{
    bool key = false;
    pos = nullptr;

    for (nodo<T> *p = head; p && p->valor <= x; p = p->next)
    {
        if (p->valor == x)
        {
            key = true;
        }
        else
        {
            pos = p;
        }
    }

    return key;
}

template <class T, class I>
void LE<T, I>::add(T x)
{
    nodo<T> *pos;

    if (!find(x, pos))
    {
        if (pos)
        {
            pos->next = new nodo<T>(x, pos->next);
        }
        else
        {
            head = new nodo<T>(x, head);
        }
    }
}

template <class T, class I>
bool LE<T, I>::del(T x)
{
    nodo<T> *pos, *tmp;
    bool key = find(x, pos);

    if (key)
    {
        if (pos)
        {
            tmp = pos->next;
            pos->next = tmp->next;
        }
        else
        {
            tmp = head;
            head = tmp->next;
        }
        delete tmp;
    }

    return key;
}

template <class T, class I>
void LE<T, I>::print()
{
    cout << "HEAD -> ";
    for (nodo<T> *p = head; p; p = p->next)
    {
        cout << p->valor << " -> ";
    }
    cout << "NULL" << endl;
}

int main()
{
    LE<int, Iterator<nodo<int>>> list;
    LE<int, Iterator<nodo<int>>>::it_vector It;
    int x = 100;

    for (int i = 0; i < 10; i++)
    {
        list.add(i);
    }

    for (It = list.begin();; It++)
    {
        It = x;
        x += 100;
        if (It--)
            break;
    }
    
    for (It = list.begin();; It++)
    {
        cout << It << endl;
        if (It--)
            break;
    }
    // list.print();
    return 0;
}