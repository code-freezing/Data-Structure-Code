#include "List.h"

bool isCircularLinkedList(Node* head) {
    if (!head || !head->next) return false; // 如果链表为空或只有一个节点，则不可能有环

    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;           // 慢指针前进一步
        fast = fast->next->next;      // 快指针前进两步

        if (slow == fast) {           // 如果两指针相遇，说明有环
            return true;
        }
    }

    return false; // 快指针到达链表末尾，说明无环
}
