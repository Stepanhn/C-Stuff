#include <iostream>

struct node {
	int data;
	node *next;
};

class my_list {

private:
	node *head, *tail;
	
public:
	my_list() {
		head = NULL;
	}

	my_list(size_t n)
	{
		if (n > 0) {
			int i = 0;
			while (i != n) {
				node *temp = new node;
				if (head == NULL){
					head = temp;
					tail = temp;
				}
				else {
					tail->next = temp;
					tail = tail->next;
				}
			}
		}
	}

	my_list(int n, const int& a)
	{
		if (n > 0) {
			int i = 0;
			while (i != n) {
				node *temp = new node;
				temp->data = a;
				if (head == NULL) {
					head = temp;
					tail = temp;
				}
				else {
					tail->next = temp;
					tail = tail->next;
				}
			}
		}
	}
	my_list(const my_list& list2) {
		
		node *list_pointer = list2.get_head();
		head->data = list2.get_head()->data;
		tail = head;
		list_pointer = list_pointer->next;
		while (list_pointer != NULL) {
			node *temp = new node;
			temp->data = list_pointer->data;
			tail->next = temp;
			tail = tail->next;
		}
	}

	node* get_head() const  {
		return head;
	}

	void print() {
		std::cout << "Print" << std::endl;
		node * temp = head;
		while (temp != NULL) {
			std::cout << "Data is: "<< temp->data << std::endl;
			temp = temp->next;
		}
	}
};

int main() {

	my_list a(5,1);
	a.print();

	return 0;
}
