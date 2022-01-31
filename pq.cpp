#include <iostream>
using namespace std;
class pq {
public:
	int p;
	int info;
	pq* l;
};
class Priority_Queue {
private:
	pq* f;
public:
	Priority_Queue();
	void insert(int, int);
	void del();
	void show();
};
Priority_Queue::Priority_Queue() {
	f = NULL;
}
void Priority_Queue::insert(int i, int p) {
	pq* t, * q;
	t = new pq;
	t->info = i;
	t->p = p;
	if (f == NULL || p < f->p) {
		t->l = f;
		f = t;
	}
	else {
		q = f;
		while (q->l != NULL && q->l->p <= p)
			q = q->l;
		t->l = q->l;
		q->l = t;
	}
}
void Priority_Queue::del() {
	pq* t;
	if (f == NULL)
		cout << "Queue Underflow\n";
	else {
		t = f;
		cout << "Deleted item is: " << t->info << endl;
		f = f->l;
		free(t);
	}
}
void Priority_Queue::show() {
	pq* ptr;
	ptr = f;
	if (f == NULL)
		cout << "Queue is empty\n";
	else {
		cout << "Priority Item\n";
		cout << "Queue is :\n";
		while (ptr != NULL) {
			cout << ptr->p << " " << ptr->info << endl;
			ptr = ptr->l;
		}
	}
}
int main() {
	Priority_Queue pq;
	pq.insert(7, 2);
	pq.insert(6, 1);
	pq.insert(3, 3);
	pq.insert(4, 3);
	pq.show();
	pq.del();
	pq.show();

}