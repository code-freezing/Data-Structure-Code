#include "BiTree.h"
#include <queue>

// ��������������� -> ������ -> ���ڵ�
void Node::PostOrder(vector<int>& vec) {
    if (left) left->PostOrder(vec);  // ����������
    if (right) right->PostOrder(vec); // ����������
    vec.push_back(val);               // ���ʸ��ڵ�
}

// ��α�����ʹ�ö��У������ʽڵ�
void Node::LevelOrder(vector<int>& vec) {
    queue<Node*> q;
    q.push(this); // �Ӹ��ڵ㿪ʼ

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        vec.push_back(current->val); // ���ʵ�ǰ�ڵ�

        if (current->left) q.push(current->left);   // ���ӽڵ����
        if (current->right) q.push(current->right); // ���ӽڵ����
    }
}
