#include<iostream>
#define max_size 100 // ������е��������Ϊ 100
using namespace std;

// ģ���� Queue����ѭ������ʵ��һ������
template <typename T>
class Queue {
private:
    int count;            // ��ǰ�����е�Ԫ������
    T array[max_size];    // ���ڴ洢����Ԫ�صľ�̬����
    int ft;               // ����Ԫ�ص�����
    int rear;             // ��βԪ�ص���һ��λ������

public:
    // ���캯������ʼ���ն���
    Queue() {
        count = 0;
        ft = 0;
        rear = 0;
    }

    // ��������������״̬����
    ~Queue() {
        count = 0;
        ft = 0;
        rear = 0;
    }

    // �������캯��������һ������ rhs ����Ԫ�ص���ǰ����
    Queue(const Queue& rhs) {
        count = rhs.count;
        ft = rhs.ft;
        rear = rhs.rear;
        // ���� rhs �����е�Ԫ��
        for (int i = 0; i < count; i++) {
            int j = (ft + i) % max_size; // ����ʵ��������ȷ��ѭ��������ȷ����
            array[j] = rhs.array[j];
        }
    }

    // ��ֵ��������أ��� rhs ���и�ֵ����ǰ���У�֧�����ȸ�ֵ
    const Queue& operator=(const Queue& rhs) {
        count = rhs.count;
        ft = rhs.ft;
        rear = rhs.rear;
        // ���� rhs �����е�Ԫ��
        for (int i = 0; i < count; i++) {
            int j = (ft + i) % max_size; // ����ʵ������
            array[j] = rhs.array[j];
        }
        return *this;
    }

    // �ж϶����Ƿ�Ϊ��
    bool empty() const {
        return count <= 0;
    }

    // �ж϶����Ƿ�����
    bool full() const {
        return count >= max_size;
    }

    // ���ض�����Ԫ������
    int size() const {
        return count;
    }

    // ��Ӳ�������Ԫ�� x ��ӵ���β
    bool push(const T& x) {
        if (!full()) {
            count++;
            array[rear] = x;
            rear = (rear + 1) % max_size; // ���� rear ������ѭ���ص����鿪ͷ
            return true;
        }
        return false; // �������������ʧ��
    }

    // ���Ӳ�����ɾ������Ԫ��
    bool pop() {
        if (!empty()) {
            count--;
            ft = (ft + 1) % max_size; // ���� ft ������ѭ�������鿪ͷ
            return true;
        }
        return false; // ����Ϊ�գ�����ʧ��
    }

    // ���ض���Ԫ�ص�����
    const T& front() const {
        return array[ft];
    }
};
