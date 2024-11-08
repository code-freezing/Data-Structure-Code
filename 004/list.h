#ifndef LIST_H
#define LIST_H

#include <cstddef>

const int maxn = 100;

struct SqList {
    int data[maxn]; // Ԫ�ش洢����
    size_t length; // ��ǰ����

    SqList(); // ���캯����Ĭ��Ϊ�ձ�

    SqList(int a[], size_t n); // ���캯������������a[]��˳���

    SqList(const SqList& sq); // ���캯��������˳���sq

    size_t size() const; // ���˳���ĳ���

    bool empty() const; // �ж��Ƿ�Ϊ�ձ�

    void clear(); // ���

    int& operator [] (size_t i); // ��������أ�sq[i]���sq�ĵ�i��Ԫ�ص�����

    int operator [] (size_t i) const; // ��������أ�sq[i]���sq�ĵ�i��Ԫ�ص�ֵ

    int& back(); // ������һ��Ԫ�ص�����

    int back() const; // ������һ��Ԫ�ص�ֵ

    void insert(size_t i, int e); // ��sq[i]��ǰ�����һ��Ԫ��e

    void erase(size_t i); // ɾ��Ԫ��sq[i]

    void push_back(int e); // �����һ��Ԫ�غ����Ԫ��e

    void push_front(int e); // �ڵ�һ��Ԫ��ǰ���Ԫ��e

    int pop_back(); // ɾ�����һ��Ԫ�أ����������ֵ

    int pop_front(); // ɾ����һ��Ԫ�أ����������ֵ
};

#endif
