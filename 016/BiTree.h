#ifndef BITREE_H
#define BITREE_H

#include<iostream>
#include<vector>
using namespace std;

// class Node �Ƕ�������� 
struct Node {
	int val; // ����ֵ 
	Node* left, * right; // ���ӣ����ӽ�� 

	// ���캯��
	Node(int v = 0) :val(v), left(NULL), right(NULL) {}

	// ��������� pre ��������� in ������������ 
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
		// ���������� 
		if (l2 <= pos - 1) {
			left = new Node();
			left->construct(pre, l1 + 1, pos + l1 - l2, in, l2, pos - 1);
		}
		// ���������� 
		if (pos + 1 <= r2) {
			right = new Node();
			right->construct(pre, r1 + pos + 1 - r2, r1, in, pos + 1, r2);
		}
	}
	// ������������ vec 
	void PostOrder(vector<int>& vec);
	// �����α����� vec 
	void LevelOrder(vector<int>& vec);
};

struct BiTree {
	Node root; // �������ĸ���� 

	// Ĭ�Ϲ��캯��
	BiTree() {}
	// ��������� pre ��������� in ���������
	BiTree(vector<int> pre, vector<int> in) {
		int n = pre.size();
		root.construct(pre, 0, n - 1, in, 0, n - 1);
	}
	// ��ö������ĺ������ 
	vector<int> PostOrder() {
		vector<int> ans;
		root.PostOrder(ans);
		return ans;
	}
	// ��ö������Ĳ�α��� 
	vector<int> LevelOrder() {
		vector<int> ans;
		root.LevelOrder(ans);
		return ans;
	}
};

#endif