#include <iostream>
#include <vector>
using namespace std;

vector<int> preorder, inorder;

// 递归函数，返回后序遍历结果
void getPostOrder(int preStart, int inStart, int inEnd) {
    if (preStart >= preorder.size() || inStart > inEnd) {
        return;
    }

    // 当前根节点的值
    int root = preorder[preStart];

    // 在中序遍历中找到根节点的位置
    int inIndex = inStart;
    while (inIndex <= inEnd && inorder[inIndex] != root) {
        inIndex++;
    }

    // 递归构造左子树
    getPostOrder(preStart + 1, inStart, inIndex - 1);

    // 递归构造右子树
    getPostOrder(preStart + (inIndex - inStart) + 1, inIndex + 1, inEnd);

    // 输出当前根节点
    cout << root << " ";
}

int main() {
    int n;
    cin >> n;

    preorder.resize(n);
    inorder.resize(n);

    // 输入前序遍历
    for (int i = 0; i < n; ++i) {
        cin >> preorder[i];
    }

    // 输入中序遍历
    for (int i = 0; i < n; ++i) {
        cin >> inorder[i];
    }

    // 获取后序遍历
    getPostOrder(0, 0, n - 1);
    cout << endl;

    return 0;
}
