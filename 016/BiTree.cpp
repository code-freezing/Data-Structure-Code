#include "BiTree.h"
#include <queue>

// 后序遍历：左子树 -> 右子树 -> 根节点
void Node::PostOrder(vector<int>& vec) {
    if (left) left->PostOrder(vec);  // 遍历左子树
    if (right) right->PostOrder(vec); // 遍历右子树
    vec.push_back(val);               // 访问根节点
}

// 层次遍历：使用队列，逐层访问节点
void Node::LevelOrder(vector<int>& vec) {
    queue<Node*> q;
    q.push(this); // 从根节点开始

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        vec.push_back(current->val); // 访问当前节点

        if (current->left) q.push(current->left);   // 左子节点入队
        if (current->right) q.push(current->right); // 右子节点入队
    }
}
