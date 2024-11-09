#include <iostream>
#include "List.h"
using namespace std;

int main() {
    int tmp;
    Node* head = nullptr, * cur = nullptr;
    while (cin >> tmp) {
        Node* node_ptr = new Node(tmp);
        if (head == nullptr) {
            head = node_ptr;
            cur = node_ptr;
        }
        else {
            cur->next = node_ptr;
            cur = cur->next;
        }

    }

    head = removeDuplicateNodes(head);

    while (head != nullptr) {
        cout << head->value << " ";
        cur = head;
        head = head->next;
        delete cur;
    }

    return 0;
}