#include <iostream>
using namespace std;
typedef int Info;
struct Elem
{
	Elem* link;
	Info info;
};
void enqueue(Elem*& first, Elem*& last, Info value);
Info dequeue(Elem*& first, Elem*& last);
void vstavka(Elem* L, Info V1, Info V2);
int main()
{
	Elem* first = NULL,
		* last = NULL;
	// створення черги
	for (int i = 1; i <= 10; i++)
		enqueue(first, last, i);
	// вилучення та вивід елементів
	while (first != NULL)
		cout << dequeue(first, last) << " ";
	cout << endl;
	return 0;
}
void enqueue(Elem*& first, Elem*& last, Info value)
{
	Elem* tmp = new Elem; // 1
	tmp->info = value; // 2
	tmp->link = NULL; // 3
	if (last != NULL)
		last->link = tmp; // 4
	last = tmp; // 5
	if (first == NULL)
		first = tmp; // 6
}
Info dequeue(Elem * &first, Elem * &last)
{
	Elem* tmp = first->link; // 1
	Info value = first->info; // 2
	delete first; // 3
	first = tmp; // 4
	if (first == NULL)
		last = NULL; // 5
	return value; // 6
}
void vstavka(Elem* L, Info V1, Info V2)
{
	if (L->info == V1)
	Elem* tmp = new Elem; // 1
	tmp->info = V2; // 2
	tmp->next = L->next; // 3
	L->next = tmp; // 4
	tmp->next->prev = tmp; // 5
	tmp->prev = L; // 6
}