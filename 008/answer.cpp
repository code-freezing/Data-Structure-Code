#include "List.h"

bool isCircularLinkedList(Node* head) {
    if (!head || !head->next) return false; // �������Ϊ�ջ�ֻ��һ���ڵ㣬�򲻿����л�

    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;           // ��ָ��ǰ��һ��
        fast = fast->next->next;      // ��ָ��ǰ������

        if (slow == fast) {           // �����ָ��������˵���л�
            return true;
        }
    }

    return false; // ��ָ�뵽������ĩβ��˵���޻�
}
