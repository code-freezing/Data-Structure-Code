#include <iostream>
#include <queue>
#include <string>
#include <sstream>
using namespace std;

// ����ǰ n ����С�ļ���Ԫ��
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

// �Ӷ�λ����ɾ�� m λ���Ի�������
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
    result.resize(keep);  // ��������Ҫ����λ
    return result;
}

int main() {
    int n, m;
    cin >> n >> m;

    // Step 1: ����ǰ n ����С�ļ���Ԫ��
    vector<int> elements;
    generate_elements(n, elements);

    // Step 2: ��Ԫ����ϳɶ�λ��
    ostringstream oss;
    for (int x : elements) {
        oss << x;
    }
    string combined_number = oss.str();

    // Step 3: ɾ�� m λ�Եõ������
    string max_number = maximize_number(combined_number, m);

    // ������
    cout << combined_number << endl;
    cout << max_number << endl;

    return 0;
}
