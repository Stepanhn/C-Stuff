

#include <iostream>
#include <queue>
#include <algorithm>


struct node {
	int data;
	node* left;
	node* right;
};


class binary_tree {
private:
	node* head;
public:
	binary_tree() {
		head = NULL;
	}
	

	void add_node(int n=0) {
		node* tmp = new node;
		tmp->data = n;
		tmp->left = NULL;
		tmp->right = NULL;
		if (head == NULL) {
			head = tmp;
			return;
		}
		int flag = 1;
		node* cur_pos = head;
		while (flag) {
		if (n > cur_pos->data) { //check right
			if (cur_pos->right == NULL) { // right is empty
				cur_pos->right = tmp;
				flag = 0;
			}
			else { //right side is full
				cur_pos = cur_pos->right;
			}
			}
		else { //check left
			if (cur_pos->left == NULL) {
				cur_pos->left = tmp;
				flag = 0;
			}
			else {
				cur_pos = cur_pos->left;
			}
		}
		}
	}

	static int count_nodes(node* ptr) {
		if (ptr == NULL) {
			return 0;
		}
		return 1 + count_nodes(ptr->left) + count_nodes(ptr->right);
	}

	void print() {

		if (head == NULL) {
			return;
		}

		std::queue<std::pair<node*, int>> q;
		std::pair<node*, int> p;

		q.push({ head,1 });
		while (!q.empty()) {
			p = q.front();
			q.pop();
			std::cout << "Data " << p.first->data << " On lvl " << p.second << std::endl;
			if (p.first->left != NULL) {
				q.push({ p.first->left,p.second + 1 });
			}
			if (p.first->right != NULL) {
				q.push({ p.first->right,p.second + 1 });
			}
		}


		/*		if (head->left != NULL) {
			print(head->left);
		}
		else {
			std::cout << head->data << " ";
			return;
		}
		
		if (head->right != NULL) {
			print(head->right);
		}else {
			std::cout << head->data <<" ";
			return;
		}
		std::cout << head->data << " ";
		*/
		}
	node* get_head() const {
		return head;
	}
};



int main() {

	binary_tree	 a;
	a.add_node(5);
	a.add_node(6);
	a.add_node(4);
	a.add_node(2);
	a.add_node(10);

	a.print();
	std::cout << binary_tree::count_nodes(a.get_head())<<std::endl;

	system("pause");
	return 0;
}