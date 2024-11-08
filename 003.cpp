#include <iostream>

using namespace std;

int main() {
	int n = 0;
	cin >> n;
	int nums[100];	//int nums[n]�������ܣ�ֻ��int * nums = new int[n];

	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
	}

	if (n == 0) return 0;	//array is empty, return 0

	//���ÿ���ָ���������
	int slow = 0;
	for (int fast = 0; fast < n; ++fast) {
		if (nums[fast] != nums[slow]) nums[++slow] = nums[fast];
	}

	for (int i = 0; i <= slow; ++i) {
		cout << nums[i] << endl;
	}
	
	return 0;
}