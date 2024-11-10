#include<iostream>
#include<queue>
using namespace std;

// 定义一个函数c，输入先序遍历序列a和中序遍历序列b
void c(string a, string b) {
    // 使用队列来帮助构建树和进行遍历
    queue<string> q;

    // 将先序和中序遍历序列推入队列中
    q.push(a);
    q.push(b);

    // 循环直到队列为空
    while (!q.empty()) {
        // 从队列中取出先序遍历序列（x）和中序遍历序列（y）
        string x = q.front();
        q.pop();
        string y = q.front();
        q.pop();

        // 如果先序遍历序列为空，跳过
        if (x.size() == 0)
            continue;

        // 输出先序遍历的当前根节点
        cout << x[0];

        // 如果先序遍历序列长度为1，直接跳过，已经输出了根节点
        if (x.size() == 1)
            continue;

        int t;
        // 在中序遍历序列中找到当前根节点的位置
        for (int i = 0; i < y.size(); ++i)
            if (x[0] == y[i]) {
                t = i;
                break;
            }

        // 将先序和中序遍历序列的左、右子树分开，分别放入队列中
        // 将左子树的先序遍历和中序遍历放入队列
        q.push(x.substr(1, t)); // 左子树的先序遍历
        q.push(y.substr(0, t)); // 左子树的中序遍历

        // 将右子树的先序遍历和中序遍历放入队列
        q.push(x.substr(t + 1)); // 右子树的先序遍历
        q.push(y.substr(t + 1)); // 右子树的中序遍历
    }
}

int main() {
    string a, b;
    int n;

    // 输入测试用例的数量
    cin >> n;

    // 对每个测试用例进行处理
    while (n--) {
        // 输入先序遍历和中序遍历的序列
        cin >> a >> b;

        // 调用c函数输出广度优先遍历序列
        c(a, b);

        // 输出换行符，表示每个测试用例的结果
        cout << endl;
    }

    return 0;
}
