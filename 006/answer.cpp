#include "List.h"

Node* getReverseLink(Node* head) {
    Node* prev = nullptr;
    Node* cur = head;

    while (cur != nullptr) {
        Node* next = cur->next; // �洢��һ���ڵ�
        cur->next = prev;       // ��ת��ǰ�ڵ�ָ��
        prev = cur;             // ���� prev ����ǰ�ڵ�
        cur = next;             // �ƶ�����һ���ڵ�
    }

    return prev; // prev ָ���µ�ͷ�ڵ�
}
