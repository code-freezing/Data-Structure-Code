#include <iostream>
#include <string>
using namespace std;

int findNthDigit(int n) {
    long long digitLength = 1;     // ���ֵ�λ��
    long long count = 9;           // ��ǰλ�����ֵ�����
    long long start = 1;           // ��ǰλ���ĵ�һ������

    // �ҵ� n λ���ڵ����ַ�Χ
    while (n > digitLength * count) {
        n -= digitLength * count;
        digitLength++;
        count *= 10;
        start *= 10;
    }

    // ȷ�����������
    long long num = start + (n - 1) / digitLength;

    // ȷ���������λ
    string numStr = to_string(num);
    return numStr[(n - 1) % digitLength] - '0';
}

int main() {
    int t;
    cin >> t;

    int results[100];  // �������100���������
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        results[i] = findNthDigit(n);
    }

    for (int i = 0; i < t; i++) {
        cout << results[i] << endl;
    }

    return 0;
}
