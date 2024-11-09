#include <iostream>
#include <vector>
using namespace std;

const int maxInf = 1e6 + 10; // 定义一个较大的常数，表示无解时的初始值

int main() {
    int n, m;
    cin >> n >> m; // 输入目标金额 n 和纸币数量 m

    vector<int> money;
    for (int i = 0; i < m; i++) { // 输入纸币面值并存入数组
        int tmp;
        cin >> tmp;
        money.push_back(tmp);
    }

    int l_cur = 0, money_sum = 0, answer = maxInf; // 初始化窗口起始位置、当前窗口和、答案

    for (int r_cur = 0; r_cur < m; r_cur++) { // 遍历纸币面值
        money_sum += money[r_cur]; // 将当前纸币面值加入窗口和

        // 当窗口和超过目标金额 n 时，尝试缩小窗口
        if (money_sum > n) {
            // 收缩窗口直到窗口和小于目标金额
            while (money_sum >= n) {
                money_sum -= money[l_cur]; // 移除窗口左端的值
                l_cur++; // 移动左端指针，缩小窗口
            }
            // 更新最小长度
            if (answer > r_cur - l_cur + 2)
                answer = r_cur - l_cur + 2;
        }
    }

    // 如果没有符合条件的子序列，输出 0，否则输出最小长度
    if (answer == maxInf)
        cout << 0 << endl;
    else
        cout << answer << endl;

    return 0;
}
