#ifndef BITREE_H
#define BITREE_H

#include<iostream>
#include<vector>
using namespace std;

// class Node 是二叉树结点 
struct Node {
	int val; // 结点的值 
	Node* left, * right; // 左子，右子结点 

	// 构造函数
	Node(int v = 0) :val(v), left(NULL), right(NULL) {}

	// 以先序遍历 pre 和中序遍历 in 构造二叉树结点 
	void construct(vector<int>& pre, int l1, int r1, vector<int>& in, int l2, int r2) {
		if (r1 < l1) return;

		val = pre[l1];

		int pos = 0;
		for (int i = l2; i <= r2; i++) {
			if (in[i] == pre[l1]) {
				pos = i;
				break;
			}
		}
		// 构造左子树 
		if (l2 <= pos - 1) {
			left = new Node();
			left->construct(pre, l1 + 1, pos + l1 - l2, in, l2, pos - 1);
		}
		// 构造右子树 
		if (pos + 1 <= r2) {
			right = new Node();
			right->construct(pre, r1 + pos + 1 - r2, r1, in, pos + 1, r2);
		}
	}
	// 保存后序遍历到 vec 
	void PostOrder(vector<int>& vec);
	// 保存层次遍历到 vec 
	void LevelOrder(vector<int>& vec);
};

struct BiTree {
	Node root; // 二叉树的根结点 

	// 默认构造函数
	BiTree() {}
	// 以先序遍历 pre 和中序遍历 in 构造二叉树
	BiTree(vector<int> pre, vector<int> in) {
		int n = pre.size();
		root.construct(pre, 0, n - 1, in, 0, n - 1);
	}
	// 获得二叉树的后序遍历 
	vector<int> PostOrder() {
		vector<int> ans;
		root.PostOrder(ans);
		return ans;
	}
	// 获得二叉树的层次遍历 
	vector<int> LevelOrder() {
		vector<int> ans;
		root.LevelOrder(ans);
		return ans;
	}
};

#endif