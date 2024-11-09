#include<iostream>
#define max_size 100 // 定义队列的最大容量为 100
using namespace std;

// 模板类 Queue，用循环数组实现一个队列
template <typename T>
class Queue {
private:
    int count;            // 当前队列中的元素数量
    T array[max_size];    // 用于存储队列元素的静态数组
    int ft;               // 队首元素的索引
    int rear;             // 队尾元素的下一个位置索引

public:
    // 构造函数：初始化空队列
    Queue() {
        count = 0;
        ft = 0;
        rear = 0;
    }

    // 析构函数：队列状态重置
    ~Queue() {
        count = 0;
        ft = 0;
        rear = 0;
    }

    // 拷贝构造函数：从另一个队列 rhs 拷贝元素到当前队列
    Queue(const Queue& rhs) {
        count = rhs.count;
        ft = rhs.ft;
        rear = rhs.rear;
        // 复制 rhs 队列中的元素
        for (int i = 0; i < count; i++) {
            int j = (ft + i) % max_size; // 计算实际索引，确保循环数组正确访问
            array[j] = rhs.array[j];
        }
    }

    // 赋值运算符重载：将 rhs 队列赋值给当前队列，支持连等赋值
    const Queue& operator=(const Queue& rhs) {
        count = rhs.count;
        ft = rhs.ft;
        rear = rhs.rear;
        // 复制 rhs 队列中的元素
        for (int i = 0; i < count; i++) {
            int j = (ft + i) % max_size; // 计算实际索引
            array[j] = rhs.array[j];
        }
        return *this;
    }

    // 判断队列是否为空
    bool empty() const {
        return count <= 0;
    }

    // 判断队列是否已满
    bool full() const {
        return count >= max_size;
    }

    // 返回队列中元素数量
    int size() const {
        return count;
    }

    // 入队操作：将元素 x 添加到队尾
    bool push(const T& x) {
        if (!full()) {
            count++;
            array[rear] = x;
            rear = (rear + 1) % max_size; // 更新 rear 索引，循环回到数组开头
            return true;
        }
        return false; // 队列已满，入队失败
    }

    // 出队操作：删除队首元素
    bool pop() {
        if (!empty()) {
            count--;
            ft = (ft + 1) % max_size; // 更新 ft 索引，循环到数组开头
            return true;
        }
        return false; // 队列为空，出队失败
    }

    // 返回队首元素的引用
    const T& front() const {
        return array[ft];
    }
};
