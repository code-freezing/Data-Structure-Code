#include <iostream>
#include <vector>
using namespace std;

vector<int> preorder, inorder;

// �ݹ麯�������غ���������
void getPostOrder(int preStart, int inStart, int inEnd) {
    if (preStart >= preorder.size() || inStart > inEnd) {
        return;
    }

    // ��ǰ���ڵ��ֵ
    int root = preorder[preStart];

    // ������������ҵ����ڵ��λ��
    int inIndex = inStart;
    while (inIndex <= inEnd && inorder[inIndex] != root) {
        inIndex++;
    }

    // �ݹ鹹��������
    getPostOrder(preStart + 1, inStart, inIndex - 1);

    // �ݹ鹹��������
    getPostOrder(preStart + (inIndex - inStart) + 1, inIndex + 1, inEnd);

    // �����ǰ���ڵ�
    cout << root << " ";
}

int main() {
    int n;
    cin >> n;

    preorder.resize(n);
    inorder.resize(n);

    // ����ǰ�����
    for (int i = 0; i < n; ++i) {
        cin >> preorder[i];
    }

    // �����������
    for (int i = 0; i < n; ++i) {
        cin >> inorder[i];
    }

    // ��ȡ�������
    getPostOrder(0, 0, n - 1);
    cout << endl;

    return 0;
}
