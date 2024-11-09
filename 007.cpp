#include <iostream>
#include <vector>
using namespace std;

const int maxInf = 1e6 + 10; // ����һ���ϴ�ĳ�������ʾ�޽�ʱ�ĳ�ʼֵ

int main() {
    int n, m;
    cin >> n >> m; // ����Ŀ���� n ��ֽ������ m

    vector<int> money;
    for (int i = 0; i < m; i++) { // ����ֽ����ֵ����������
        int tmp;
        cin >> tmp;
        money.push_back(tmp);
    }

    int l_cur = 0, money_sum = 0, answer = maxInf; // ��ʼ��������ʼλ�á���ǰ���ں͡���

    for (int r_cur = 0; r_cur < m; r_cur++) { // ����ֽ����ֵ
        money_sum += money[r_cur]; // ����ǰֽ����ֵ���봰�ں�

        // �����ںͳ���Ŀ���� n ʱ��������С����
        if (money_sum > n) {
            // ��������ֱ�����ں�С��Ŀ����
            while (money_sum >= n) {
                money_sum -= money[l_cur]; // �Ƴ�������˵�ֵ
                l_cur++; // �ƶ����ָ�룬��С����
            }
            // ������С����
            if (answer > r_cur - l_cur + 2)
                answer = r_cur - l_cur + 2;
        }
    }

    // ���û�з��������������У���� 0�����������С����
    if (answer == maxInf)
        cout << 0 << endl;
    else
        cout << answer << endl;

    return 0;
}
