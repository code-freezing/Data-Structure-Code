#include <iostream>

using namespace std;

int main() {
	int n = 0;
	cin >> n;
	int nums[100];	//int nums[n]不被接受，只能int * nums = new int[n];

	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
	}

	if (n == 0) return 0;	//array is empty, return 0

	//采用快慢指针解决这道题
	int slow = 0;
	for (int fast = 0; fast < n; ++fast) {
		if (nums[fast] != nums[slow]) nums[++slow] = nums[fast];
	}

	for (int i = 0; i <= slow; ++i) {
		cout << nums[i] << endl;
	}
	
	return 0;
}