#include <iostream>
#include <string>

using namespace std;

char firstUniqueChar(const string& str) {	//�������ݷ�ʽ ��ʡ�ڴ�ռ� ��ֹ�����޸�str��ֵ
	int count[256] = { 0 };	//ASCII�빲��256���ַ�

	// ��һ�α�����ͳ��ÿ���ַ��ĳ��ִ���

	//��Ч��
	// for( int i = 0; i < s.length(); i++)
	//{
	//	s[i]...
	//}
	for (char ch : str) {
		count[(unsigned char)ch]++;
	}

	// �ڶ��α������ҵ���һ�����ִ���Ϊ1���ַ�
	for (char ch : str) {
		if (count[(unsigned char)ch] == 1) {
			return ch;
		}
	}

	return '#';  // ���û��ֻ����һ�ε��ַ�
}

int main() {
	string input;
	cin >> input;

	char result = firstUniqueChar(input);
	cout << result << endl;

	return 0;
}