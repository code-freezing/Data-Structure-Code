#include <iostream>
#include "list.h"
using namespace std;

int a[3] = { 2, 3, 4 };
SqList sq1(a, 3), sq(sq1);

void print();

int main() {
    int x;
    cin >> x; // x = 1
    print();
    sq.insert(0, x);
    cout << "insert(0,1)\n";
    print();
    sq.push_back(5);
    cout << "push_back(5)\n";
    print();
    sq.push_front(0);
    cout << "push_front(0)\n";
    print();
    sq.erase(3);
    cout << "erase(3)\n";
    print();
    sq.pop_front();
    cout << "pop_front\n";
    print();
    sq.pop_back();
    cout << "pop_back\n";
    print();
    cout << "back()=" << sq.back() << endl;
    sq.clear();
    cout << "clear()\n";
    cout << "size()=" << sq.size() << endl;
    return 0;
}

void print() {
    cout << "sq=[";
    for (size_t i = 0; i < sq.size(); i++) {
        cout << sq[i];
        if (i + 1 != sq.size()) cout << " ";
    }
    cout << "]" << endl;
}
