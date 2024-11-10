#include "kmp.h"

// 计算模式串 str 的 next 数组
vector<int> getNext(const string& str) {
    int m = str.length();
    vector<int> next(m, 0); // 初始化 next 数组，长度为模式串长度
    int j = 0; // 表示当前匹配的前缀长度

    // 构造 next 数组
    for (int i = 1; i < m; i++) {
        // 如果当前字符不匹配，则回退到前一个最长前缀的位置
        while (j > 0 && str[i] != str[j]) {
            j = next[j - 1];
        }
        // 如果字符匹配，前缀长度增加
        if (str[i] == str[j]) {
            j++;
        }
        // 设置 next 数组中当前索引的值
        next[i] = j;
    }
    return next;
}

// KMP 算法，用于在主串 s 中查找模式串 t 的首次出现位置
int kmp(const string& s, const string& t, vector<int>& next) {
    int n = s.length(); // 主串长度
    int m = t.length(); // 模式串长度
    int j = 0; // 模式串当前匹配位置

    // 遍历主串
    for (int i = 0; i < n; i++) {
        // 如果字符不匹配，使用 next 数组回退 j 的位置
        while (j > 0 && s[i] != t[j]) {
            j = next[j - 1];
        }
        // 如果字符匹配，增加 j
        if (s[i] == t[j]) {
            j++;
        }
        // 如果模式串全部匹配，返回匹配的起始位置
        if (j == m) {
            return i - m + 1;
        }
    }
    // 如果没有找到匹配，返回 -1
    return -1;
}
