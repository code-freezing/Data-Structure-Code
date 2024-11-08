#ifndef LIST_H
#define LIST_H

#include <cstddef>

const int maxn = 100;

struct SqList {
    int data[maxn]; // 元素存储数组
    size_t length; // 当前长度

    SqList(); // 构造函数：默认为空表

    SqList(int a[], size_t n); // 构造函数：拷贝数组a[]到顺序表

    SqList(const SqList& sq); // 构造函数：复制顺序表sq

    size_t size() const; // 获得顺序表的长度

    bool empty() const; // 判断是否为空表

    void clear(); // 清空

    int& operator [] (size_t i); // 运算符重载，sq[i]获得sq的第i个元素的引用

    int operator [] (size_t i) const; // 运算符重载，sq[i]获得sq的第i个元素的值

    int& back(); // 获得最后一个元素的引用

    int back() const; // 获得最后一个元素的值

    void insert(size_t i, int e); // 在sq[i]的前面插入一个元素e

    void erase(size_t i); // 删除元素sq[i]

    void push_back(int e); // 在最后一个元素后添加元素e

    void push_front(int e); // 在第一个元素前添加元素e

    int pop_back(); // 删除最后一个元素，并返回这个值

    int pop_front(); // 删除第一个元素，并返回这个值
};

#endif
