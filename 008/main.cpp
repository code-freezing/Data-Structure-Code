#include <iostream>
#include "List.h"
using namespace std;

int main() {
	int kase;
	cin >> kase;
	while (kase--) {
		int n, isCircul;
		Node* head = nullptr, * cur = nullptr;
		cin >> isCircul >> n;
		Node* in_head = nullptr;
		int in_loc = rand() % n;
		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			Node* node_ptr = new Node(tmp);
			if (in_loc == i) in_head = node_ptr;
			if (head == nullptr) {
				head = node_ptr;
				cur = node_ptr;
			}
			else {
				cur->next = node_ptr;
				cur = cur->next;
			}
		}

		if (isCircul) cur->next = in_head;

		if (isCircularLinkedList(head)) cout << "true" << endl;
		else cout << "false" << endl;

	}

	return 0;
}