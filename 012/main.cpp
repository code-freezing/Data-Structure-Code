#include <iostream>
#include <queue>
#include <string>
#include <sstream>
using namespace std;

// 生成前 n 个最小的集合元素
void generate_elements(int n, vector<int>& elements) {
    priority_queue<int, vector<int>, greater<int>> q;
    q.push(1);
    while (elements.size() < n) {
        int x = q.top();
        q.pop();
        if (elements.empty() || elements.back() != x) {
            elements.push_back(x);
        }
        q.push(2 * x + 1);
        q.push(4 * x + 5);
    }
}

// 从多位数中删除 m 位数以获得最大数
string maximize_number(const string& num, int m) {
    string result;
    int keep = num.size() - m;
    for (char digit : num) {
        while (m && !result.empty() && result.back() < digit) {
            result.pop_back();
            --m;
        }
        result.push_back(digit);
    }
    result.resize(keep);  // 仅保留需要的数位
    return result;
}

int main() {
    int n, m;
    cin >> n >> m;

    // Step 1: 生成前 n 个最小的集合元素
    vector<int> elements;
    generate_elements(n, elements);

    // Step 2: 将元素组合成多位数
    ostringstream oss;
    for (int x : elements) {
        oss << x;
    }
    string combined_number = oss.str();

    // Step 3: 删除 m 位以得到最大数
    string max_number = maximize_number(combined_number, m);

    // 输出结果
    cout << combined_number << endl;
    cout << max_number << endl;

    return 0;
}
