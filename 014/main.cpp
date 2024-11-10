#include<iostream>
#include"kmp.h"
using namespace std;

int main() {
	string s, t;
	cin >> s >> t;
	vector<int> next = getNext(t);
	cout << kmp(s, t, next) << endl;
	return 0;
}