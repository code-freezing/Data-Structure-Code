#include<vector>
#include<iostream>
using namespace std;

vector<int> getNext(const string& str);

int kmp(const string& s, const string& t, vector<int>& next);