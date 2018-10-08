//Rishabh Jain
//CIS554 HW1
//Due: 11:59PM, Friday (9/14)

#include <iostream>
using namespace std;

class node {
public:
	int value;
	node * next;
	node * previous;
	node(int i) { value = i; next = previous = nullptr; }
	node() { next = previous = nullptr; }
};

class doubly_linked_list {
public:
	node * head;
	node * tail;
	doubly_linked_list() { head = tail = nullptr; }
	void make_random_list(int m, int n);
	void print_forward();
	void print_backward();

	//inplement the following member functions:

	void remove_one(int k); //remvoe the first node with value k

	void remove_all(int k); //remove all nodes with value k
	void reverse();//reverse the order of the list
	void sort(); //for the nodes in assending order
	void insert(int k); //insert a node to an already sorted list
};

void doubly_linked_list::make_random_list(int m, int n) {

	for (int i = 0; i < m; i++) {
		node * p1 = new node(rand() % n);
		p1->previous = tail;
		if (tail != nullptr) tail->next = p1;
		tail = p1;
		if (head == nullptr) head = p1;
	}
}

void doubly_linked_list::print_forward() {
	cout << endl;
	node * p1 = head;
	while (p1 != nullptr) {
		cout << p1->value << " ";
		p1 = p1->next;
	}
}

void doubly_linked_list::print_backward() {
	cout << endl;
	node * p1 = tail;
	while (p1 != nullptr) {
		cout << p1->value << " ";
		p1 = p1->previous;
	}
}


void doubly_linked_list::remove_one(int k) {
	node* req_value  = head;
	while ( req_value && req_value-> value!= k)
		req_value= req_value->next;


	if (req_value)
	{
		
		if (req_value == head)
			head = head->next;
		
		if (req_value == tail)
			tail = tail->previous;

	
		if (req_value->next)
			req_value->next->previous = req_value->previous;
		if (req_value->previous)
			req_value->previous->next = req_value->next;

		delete req_value;
	}
}
void doubly_linked_list::remove_all(int k) {
	node* req_value = head;
	while (req_value != nullptr) {
		//while (req_value && req_value->value != k)
			//req_value = req_value->next;


		if (req_value)
		{

			if (req_value == head)
				head = head->next;

			if (req_value == tail)
				tail = tail->previous;


			if (req_value->next)
				req_value->next->previous = req_value->previous;
			if (req_value->previous)
				req_value->previous->next = req_value->next;

			node * p = req_value;

			delete req_value;
			if (p->next != nullptr) {
				req_value = p->next;
			}
			else {
				return;
			}
			
		}
	}
}

void doubly_linked_list::reverse() {
	node *ptr = head;
	while (ptr != NULL) {
		node *tmp = ptr->next;
		ptr->next = ptr->previous;
		ptr->previous = tmp;
		if (tmp == NULL) {
			tail = head;
			head = ptr;
		}
		ptr = tmp;
	}
}
	void doubly_linked_list::sort() {
		node *p1 = head, *p2, *p3;
		p2 = p1->next;
		p3 = p1->next;
		int count = 0;
		while (p3 != nullptr)
		{
			while (p2 != nullptr)
			{
				if (p1->value > p2->value)
				{
					count = p1->value;
					p1->value = p2->value;
					p2->value = count;
				}
				p1 = p2;
				p2 = p2->next;
			}
			p1 = head;
			p2 = p1->next;
			p3 = p3->next;
		}
	}
	

	void doubly_linked_list::insert(int k) {
		{

			node *a = new node(k);
			if (head == nullptr) {
				head = a;
				tail = head;
				return;
			}


			// case 2 - inserting at the head of the list
			if (k < head->value)
			{
				a->next = head;
				head = a;
				return;
			}

			// case 3 - inserting at the end of the list
			if (k >= tail->value)
			{
				a->previous = tail;
				tail->next = a;
				tail = a;
				return;
			}

			// general case - inserting into the middle
			node* temp = head;
			while (temp && (a->value >= temp->value))
			{
				temp = temp->next;
			}
			if (temp)
			{
				a->next = temp;
				a->previous = temp->previous;
				temp->previous->next =a;
				temp->previous = a;
				return;
			}

			return;
		}
	}


int main() {
	doubly_linked_list d1;
	d1.make_random_list(30, 10);
	d1.print_forward();
	d1.print_backward();

	d1.reverse();
	d1.print_forward();
	d1.print_backward();

	d1.remove_one(7);
	d1.remove_one(8);
	d1.print_forward();
	d1.print_backward();

	d1.remove_all(5);
	d1.print_forward();
	d1.print_backward();

	d1.sort();
	d1.print_forward();
	d1.print_backward();

	d1.insert(4);
	d1.insert(9);
	d1.insert(0);
	d1.print_forward();
	d1.print_backward();


	getchar();
	getchar();
	return 0;
}