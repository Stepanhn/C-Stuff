
#include <iostream>

struct node {
public:
	int data;
	node *next;
};
class iterator {

private:
	node* i_position;
	node* i_head;

public:
	iterator() {
		i_position = NULL;
		i_head = NULL;
	}
	friend class my_list;

	int get() {
		return i_position->data;
	}
	node* get_node() const{
		return i_position;
	}
	void next() {
		i_position = i_position->next;
	}

	bool operator==(const iterator& right) const {
		return i_position == right.i_position;
	}
	bool operator!=(const iterator& right) const {
		return i_position != right.i_position;
	}
	iterator& operator+() {
		return *this;
	}
	iterator& operator+(int) {
		iterator iter = *this;
		this->i_position = this->i_position->next;
		return iter;
	}
	iterator& operator++() {
		i_position = i_position->next;
		return *this;
	}
	iterator& operator++(int) {
		iterator iter = *this;
		this->i_position = this->i_position->next;
		return iter;
	}
};

class my_list {

private:
	node *head, *tail;

public:
	//default
	my_list() {
		head = NULL;
		tail = NULL;
	}
	// fill constructor
	my_list(int n, const int& a=0)
	{
		for (int i = 0; i < n; i++) {
			add_node(a);
		}
	}
	
	//Copy Constructor
	my_list(my_list& list2) {
		node *list_pointer = list2.get_head();
		while (list_pointer->next != NULL) {
			add_node(list_pointer->data);
			list_pointer = list_pointer->next;
		}
	}
	/*destructor : runtime bug left...
	~my_list() {
		//delete 
		if (head == NULL) {
			return;
		}
		node* temp_head = head;
		node* temp_tail = head->next;
		while(temp_head!=NULL){
			delete temp_head;
			temp_head = temp_tail;
			if (temp_tail->next!=NULL){
				temp_tail = temp_tail->next;
			}
		}
	}
	*/
	my_list& operator=(const my_list& l1) {
		std::cout << "operator=" << std::endl;
		head = l1.get_head();
		tail = l1.get_tail();
		return *this;
	}
	
	
	int len() {
		if (head == NULL) {
			return 0;
		}
		int i = 1;
		node* tmp = head;
		while (tmp != tail) {
			i++;
			tmp = tmp->next;
		}
		return i;
	}

	void add_node(int n) {
		node* tmp = new node;
		tmp->data = n;
		tmp->next = NULL;
		if (head == NULL) {
			head = tmp;
			tail = tmp;
		}
		else {
			tail->next = tmp;
			tail = tail->next;
		}
	}
	
	static void print(node* head2) {
		if (head2 != NULL) {
			std::cout << head2->data << " ";
			print(head2->next);
		}

	}
	node* get_head() const {
		return head;
	}
	node* get_tail() const {
		return tail;
	}

	int size() {
		int size = 0;
		node* tmp_head = head;
		while (tmp_head != NULL) {
			size++;
			tmp_head=tmp_head->next;
		}
		return size;
	};

	iterator& begin() {
		iterator i;
		i.i_head = head;
		i.i_position = head;
		return i;
	};

	iterator end() {
		iterator i;
		i.i_head = head;
		i.i_position = NULL;
		return i;
	}

	const iterator& cbegin() {
		iterator i;
		i.i_head = head;
		i.i_position = head;
		return i;
	};

	const iterator cend() {
		iterator i;
		i.i_head = head;
		i.i_position = NULL;
		return i;
	}

	bool empty() {
		return head == NULL;
	}

	node& front() {
		return *head;
	}

	node& back() {
		return *tail;
	}
	//not very usefull... sort of..
	void update_tail() {
		if (head != NULL) {
			node* tmp = head;
			while (tmp->next != NULL) {
				tmp = tmp->next;
			}
			tail = tmp;
		}
	}
	void push_front(int n);
	void pop_front();
	void push_back(int n);
	void pop_back();
	void assign(int length, int value) {
		//delete if theres any?
		if (head == NULL) {
			for (int i = 0; i < length; i++) {
				add_node(value);
			}
		}
	}
	void assign(iterator begin, iterator end) {
		//delete old one?
		if (head == NULL) {
			iterator tmp = begin;
			while (tmp.i_position->next != end.i_position) {
				add_node(begin.get());
				tmp.next();
			}
		}
	}

	void insert( const iterator& location, int num) {
		node* tmp = head;
		
		std::cout << "\n\n" << location.get_node()->data;
		std::cout << "\n\n" << location.get_node()->next;
		
		while (tmp != location.i_position) {
			tmp = tmp->next;
		}
		if (tmp == head) {
			push_front(num);
			return;
		}
		node* temp = new node;
		temp->data = num;
		temp->next = tmp->next;
		tmp->next = temp;
	}
};
void my_list::push_front(int n) {
	node* new_node = new node;
	new_node->data = n;
	node* old_head = head;
	head = new_node;
	new_node->next = old_head;
	update_tail();
}
void my_list::pop_front() {
	node* tmp = head->next;
	delete head;
	head = tmp;
}
void my_list::push_back(int n) {
	node* tmp = new node;
	tmp->data = n;
	tmp->next = NULL;
	//find last element
	node* tmp2 = head;
	while (tmp2->next != NULL){
		tmp2 = tmp2->next;
	}
	tmp2->next = tmp;
	update_tail();
}
void my_list::pop_back() {
	update_tail();
	if (tail != head) {
		node* tmp = head;
		while (tmp->next != tail) {
			tmp = tmp->next;
		}
		delete tail;
		tail = tmp;
		tail->next = NULL; // as old tail is deleted
	}
}



int main() {
	std::cout << "Print" << std::endl;
	my_list a;
	a.add_node(5);
	a.add_node(6);
	my_list::print(a.get_head());

	
	my_list b(5);
	my_list::print(b.get_head());
	std::cout << b.len() << std::endl;
	//Copy Constructor test
	my_list copy;
	copy = b;
	my_list::print(copy.get_head());

	for (iterator i = b.begin(); i != b.end(); i.next()) {
		std::cout << i.get();
	}

	std::cout << "\nPush test\n" ;
	my_list d;
	d.push_front(5);
	d.push_front(6);
	d.push_back(7);
	d.push_back(8);
	d.push_back(7);
	my_list::print(d.get_head());
	std::cout << "\nPop test\n";
	d.pop_front();
	d.pop_back();
	my_list::print(d.get_head());
	std::cout << "\nassign test\n";
	my_list e;
	e.assign(5, 10);
	my_list::print(e.get_head());
	std::cout << "\nassign test 2\n";
	my_list f;
	f.assign(e.begin(), e.end());
	my_list::print(f.get_head());
	std::cout << "\insert test 2\n";
	
	
	f.insert(f.begin(), 11);
	iterator it = f.begin();
	//++it;
	std::cout << "\n\n" << it.get_node()->data;
	std::cout << "\n\n" << it.get_node()->next;
	//iterator* it2 = &it;
	//f.insert(it, 11);
	//f.insert((f.begin())+1, 11);
	my_list::print(f.get_head());
	system("pause");
	return 0;
}
//questions
// For this list, I dont have revert iterator right? It will be hard to keep as we dont "remember" previous node
//max_size ??? how to relate to system size?
// some bug in destructor