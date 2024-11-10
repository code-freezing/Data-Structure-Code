#include<iostream>
#include<vector>
#include "BiTree.h"
using namespace std;

int main() {
	int n, u;
	vector<int> pre, in;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> u;
		pre.push_back(u);
	}
	for (int i = 0; i < n; i++) {
		cin >> u;
		in.push_back(u);
	}

	BiTree bit(pre, in);

	vector<int> post = bit.PostOrder();
	for (int i = 0; i < n; i++) {
		if (i > 0) cout << " ";
		cout << post[i];

	}
	cout << endl;

	vector<int> level = bit.LevelOrder();
	for (int i = 0; i < n; i++) {
		if (i > 0) cout << " ";
		cout << level[i];

	}
	cout << endl;
	return 0;
}