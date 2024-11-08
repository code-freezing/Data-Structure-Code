#include "list.h"
#include <stdexcept> // for std::out_of_range

// 默认构造函数：创建一个空表
SqList::SqList() : length(0) {}

// 构造函数：从数组 a[] 中拷贝元素到顺序表
SqList::SqList(int a[], size_t n) : length(n) {
    if (n > maxn) throw std::out_of_range("Array size exceeds maximum list capacity.");
    for (size_t i = 0; i < n; i++) {
        data[i] = a[i];
    }
}

// 拷贝构造函数
SqList::SqList(const SqList& sq) : length(sq.length) {
    for (size_t i = 0; i < sq.length; i++) {
        data[i] = sq.data[i];
    }
}

// 获取顺序表的长度
size_t SqList::size() const {
    return length;
}

// 判断是否为空表
bool SqList::empty() const {
    return length == 0;
}

// 清空顺序表
void SqList::clear() {
    length = 0;
}

// 运算符重载，返回第 i 个元素的引用
int& SqList::operator[](size_t i) {
    if (i >= length) throw std::out_of_range("Index out of range.");
    return data[i];
}

// 运算符重载，返回第 i 个元素的值（只读）
int SqList::operator[](size_t i) const {
    if (i >= length) throw std::out_of_range("Index out of range.");
    return data[i];
}

// 返回最后一个元素的引用
int& SqList::back() {
    if (length == 0) throw std::out_of_range("List is empty.");
    return data[length - 1];
}

// 返回最后一个元素的值（只读）
int SqList::back() const {
    if (length == 0) throw std::out_of_range("List is empty.");
    return data[length - 1];
}

// 在指定位置 i 之前插入元素 e
void SqList::insert(size_t i, int e) {
    if (i > length || length >= maxn) throw std::out_of_range("Insert position out of range or list is full.");
    for (size_t j = length; j > i; j--) {
        data[j] = data[j - 1];
    }
    data[i] = e;
    length++;
}

// 删除位置 i 处的元素
void SqList::erase(size_t i) {
    if (i >= length) throw std::out_of_range("Erase position out of range.");
    for (size_t j = i; j < length - 1; j++) {
        data[j] = data[j + 1];
    }
    length--;
}

// 在顺序表末尾添加元素 e
void SqList::push_back(int e) {
    if (length >= maxn) throw std::out_of_range("List is full.");
    data[length++] = e;
}

// 在顺序表开头添加元素 e
void SqList::push_front(int e) {
    if (length >= maxn) throw std::out_of_range("List is full.");
    for (size_t j = length; j > 0; j--) {
        data[j] = data[j - 1];
    }
    data[0] = e;
    length++;
}

// 删除并返回顺序表的最后一个元素
int SqList::pop_back() {
    if (length == 0) throw std::out_of_range("List is empty.");
    return data[--length];
}

// 删除并返回顺序表的第一个元素
int SqList::pop_front() {
    if (length == 0) throw std::out_of_range("List is empty.");
    int first_element = data[0];
    for (size_t j = 0; j < length - 1; j++) {
        data[j] = data[j + 1];
    }
    length--;
    return first_element;
}
