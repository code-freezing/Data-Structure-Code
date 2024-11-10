#include "kmp.h"

// ����ģʽ�� str �� next ����
vector<int> getNext(const string& str) {
    int m = str.length();
    vector<int> next(m, 0); // ��ʼ�� next ���飬����Ϊģʽ������
    int j = 0; // ��ʾ��ǰƥ���ǰ׺����

    // ���� next ����
    for (int i = 1; i < m; i++) {
        // �����ǰ�ַ���ƥ�䣬����˵�ǰһ���ǰ׺��λ��
        while (j > 0 && str[i] != str[j]) {
            j = next[j - 1];
        }
        // ����ַ�ƥ�䣬ǰ׺��������
        if (str[i] == str[j]) {
            j++;
        }
        // ���� next �����е�ǰ������ֵ
        next[i] = j;
    }
    return next;
}

// KMP �㷨������������ s �в���ģʽ�� t ���״γ���λ��
int kmp(const string& s, const string& t, vector<int>& next) {
    int n = s.length(); // ��������
    int m = t.length(); // ģʽ������
    int j = 0; // ģʽ����ǰƥ��λ��

    // ��������
    for (int i = 0; i < n; i++) {
        // ����ַ���ƥ�䣬ʹ�� next ������� j ��λ��
        while (j > 0 && s[i] != t[j]) {
            j = next[j - 1];
        }
        // ����ַ�ƥ�䣬���� j
        if (s[i] == t[j]) {
            j++;
        }
        // ���ģʽ��ȫ��ƥ�䣬����ƥ�����ʼλ��
        if (j == m) {
            return i - m + 1;
        }
    }
    // ���û���ҵ�ƥ�䣬���� -1
    return -1;
}
