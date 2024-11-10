#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> scores(n);

    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }

    deque<int> dq;  // �洢����������
    vector<int> results;

    for (int i = 0; i < n; i++) {
        // �Ƴ����ڴ��ڷ�Χ�ڵ�Ԫ��
        if (!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front();
        }

        // �Ƴ�����С�ڵ�ǰԪ�ص�Ԫ�أ����ǲ����ܳ�Ϊ���ֵ
        while (!dq.empty() && scores[dq.back()] <= scores[i]) {
            dq.pop_back();
        }

        // �ѵ�ǰԪ�ص��������뵽����
        dq.push_back(i);

        // �ӵ� k �ܿ�ʼ����¼ÿ�ܵġ����ѡ�֡�����
        if (i >= k - 1) {
            results.push_back(scores[dq.front()]);
        }
    }

    // ������
    for (int score : results) {
        cout << score << endl;
    }

    return 0;
}
