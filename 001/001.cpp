#include <iostream>
#include <string>
using namespace std;

int findNthDigit(int n) {
    long long digitLength = 1;     // 数字的位数
    long long count = 9;           // 当前位数数字的数量
    long long start = 1;           // 当前位数的第一个数字

    // 找到 n 位所在的数字范围
    while (n > digitLength * count) {
        n -= digitLength * count;
        digitLength++;
        count *= 10;
        start *= 10;
    }

    // 确定具体的数字
    long long num = start + (n - 1) / digitLength;

    // 确定具体的数位
    string numStr = to_string(num);
    return numStr[(n - 1) % digitLength] - '0';
}

int main() {
    int t;
    cin >> t;

    int results[100];  // 假设最多100组测试数据
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
