#include "list.h"
#include <stdexcept> // for std::out_of_range

// Ĭ�Ϲ��캯��������һ���ձ�
SqList::SqList() : length(0) {}

// ���캯���������� a[] �п���Ԫ�ص�˳���
SqList::SqList(int a[], size_t n) : length(n) {
    if (n > maxn) throw std::out_of_range("Array size exceeds maximum list capacity.");
    for (size_t i = 0; i < n; i++) {
        data[i] = a[i];
    }
}

// �������캯��
SqList::SqList(const SqList& sq) : length(sq.length) {
    for (size_t i = 0; i < sq.length; i++) {
        data[i] = sq.data[i];
    }
}

// ��ȡ˳���ĳ���
size_t SqList::size() const {
    return length;
}

// �ж��Ƿ�Ϊ�ձ�
bool SqList::empty() const {
    return length == 0;
}

// ���˳���
void SqList::clear() {
    length = 0;
}

// ��������أ����ص� i ��Ԫ�ص�����
int& SqList::operator[](size_t i) {
    if (i >= length) throw std::out_of_range("Index out of range.");
    return data[i];
}

// ��������أ����ص� i ��Ԫ�ص�ֵ��ֻ����
int SqList::operator[](size_t i) const {
    if (i >= length) throw std::out_of_range("Index out of range.");
    return data[i];
}

// �������һ��Ԫ�ص�����
int& SqList::back() {
    if (length == 0) throw std::out_of_range("List is empty.");
    return data[length - 1];
}

// �������һ��Ԫ�ص�ֵ��ֻ����
int SqList::back() const {
    if (length == 0) throw std::out_of_range("List is empty.");
    return data[length - 1];
}

// ��ָ��λ�� i ֮ǰ����Ԫ�� e
void SqList::insert(size_t i, int e) {
    if (i > length || length >= maxn) throw std::out_of_range("Insert position out of range or list is full.");
    for (size_t j = length; j > i; j--) {
        data[j] = data[j - 1];
    }
    data[i] = e;
    length++;
}

// ɾ��λ�� i ����Ԫ��
void SqList::erase(size_t i) {
    if (i >= length) throw std::out_of_range("Erase position out of range.");
    for (size_t j = i; j < length - 1; j++) {
        data[j] = data[j + 1];
    }
    length--;
}

// ��˳���ĩβ���Ԫ�� e
void SqList::push_back(int e) {
    if (length >= maxn) throw std::out_of_range("List is full.");
    data[length++] = e;
}

// ��˳���ͷ���Ԫ�� e
void SqList::push_front(int e) {
    if (length >= maxn) throw std::out_of_range("List is full.");
    for (size_t j = length; j > 0; j--) {
        data[j] = data[j - 1];
    }
    data[0] = e;
    length++;
}

// ɾ��������˳�������һ��Ԫ��
int SqList::pop_back() {
    if (length == 0) throw std::out_of_range("List is empty.");
    return data[--length];
}

// ɾ��������˳���ĵ�һ��Ԫ��
int SqList::pop_front() {
    if (length == 0) throw std::out_of_range("List is empty.");
    int first_element = data[0];
    for (size_t j = 0; j < length - 1; j++) {
        data[j] = data[j + 1];
    }
    length--;
    return first_element;
}
