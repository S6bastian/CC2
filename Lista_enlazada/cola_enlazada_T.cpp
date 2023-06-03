#include <iostream>

using namespace std;

template <class T>
struct nodo{
	T valor;
	nodo *next;
	nodo(T v, nodo *n = nullptr) {
		valor = v;
		next = n;
	}
};

template <class T>
struct queue {
	nodo<T> *head = nullptr;
	nodo<T> *tail = nullptr;
	void push(T v);
	bool pop(T& v);
};

template <class T>
void queue<T>::push(T v) {
	if (!head) {
        head = new nodo<T>(v);
		tail = head;
	}
	else {
		tail->next = new nodo<T>(v);
		tail = tail->next;
	}
}

template<class T>
bool queue<T>::pop(T &v) {
	bool key = false;
	if (head) {
		v = head->valor;
		nodo<T> *tmp = head;
		head = head->next;
		delete tmp;
		key = true;
	}
	return key;
}

int main() {
	queue<int> p;
	p.push(1);
	p.push(2);
	p.push(3);

	int x;
	bool cont = true;
	while (cont) {
		cont = p.pop(x);
		if (cont)
			cout << x << endl;
	}
	return 0;
}

/* OUTPUT

1
2
3

*/