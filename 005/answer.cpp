#include "list.h"

Node* removeDuplicateNodes(Node* h) {
	if (h == nullptr) return nullptr;

	bool visited[1001] = { false }; // ��ʼ����������
	Node* cur = h;
	visited[cur->value] = true; // ��ǵ�һ���ڵ��ֵ

	while (cur->next != nullptr) {
		if (visited[cur->next->value]) {
			Node* dup = cur->next;
			cur->next = cur->next->next; // �����ظ��ڵ�
			delete dup;
		}
		else {
			visited[cur->next->value] = true; // �����ֵ
			cur = cur->next; // �ƶ�����һ���ڵ�
		}
	}
	return h;
}