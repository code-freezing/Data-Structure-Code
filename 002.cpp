#include <iostream>
#include <string>

using namespace std;

char firstUniqueChar(const string& str) {	//常见传递方式 节省内存空间 防止意外修改str的值
	int count[256] = { 0 };	//ASCII码共有256个字符

	// 第一次遍历：统计每个字符的出现次数

	//等效于
	// for( int i = 0; i < s.length(); i++)
	//{
	//	s[i]...
	//}
	for (char ch : str) {
		count[(unsigned char)ch]++;
	}

	// 第二次遍历：找到第一个出现次数为1的字符
	for (char ch : str) {
		if (count[(unsigned char)ch] == 1) {
			return ch;
		}
	}

	return '#';  // 如果没有只出现一次的字符
}

int main() {
	string input;
	cin >> input;

	char result = firstUniqueChar(input);
	cout << result << endl;

	return 0;
}