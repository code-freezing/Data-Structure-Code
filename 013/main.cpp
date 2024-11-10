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

    deque<int> dq;  // 存储分数的索引
    vector<int> results;

    for (int i = 0; i < n; i++) {
        // 移除不在窗口范围内的元素
        if (!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front();
        }

        // 移除所有小于当前元素的元素，它们不可能成为最大值
        while (!dq.empty() && scores[dq.back()] <= scores[i]) {
            dq.pop_back();
        }

        // 把当前元素的索引加入到队列
        dq.push_back(i);

        // 从第 k 周开始，记录每周的“最佳选手”分数
        if (i >= k - 1) {
            results.push_back(scores[dq.front()]);
        }
    }

    // 输出结果
    for (int score : results) {
        cout << score << endl;
    }

    return 0;
}
