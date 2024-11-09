#include "list.h"

Node* removeDuplicateNodes(Node* h) {
	if (h == nullptr) return nullptr;

	bool visited[1001] = { false }; // 初始化访问数组
	Node* cur = h;
	visited[cur->value] = true; // 标记第一个节点的值

	while (cur->next != nullptr) {
		if (visited[cur->next->value]) {
			Node* dup = cur->next;
			cur->next = cur->next->next; // 跳过重复节点
			delete dup;
		}
		else {
			visited[cur->next->value] = true; // 标记新值
			cur = cur->next; // 移动到下一个节点
		}
	}
	return h;
}