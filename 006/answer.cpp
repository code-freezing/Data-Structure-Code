#include "List.h"

Node* getReverseLink(Node* head) {
    Node* prev = nullptr;
    Node* cur = head;

    while (cur != nullptr) {
        Node* next = cur->next; // 存储下一个节点
        cur->next = prev;       // 反转当前节点指针
        prev = cur;             // 更新 prev 到当前节点
        cur = next;             // 移动到下一个节点
    }

    return prev; // prev 指向新的头节点
}
