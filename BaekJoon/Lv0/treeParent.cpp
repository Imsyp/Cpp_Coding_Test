#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class treeNode {
public:
        int parent = 0;
};

//Ʈ���� num1�� num2 node�� �θ� ���� ����
//base case: �� �� �ϳ��� 1�� ���
//case1: �� �� �ϳ��� ��尡 �θ��尡 �ִ� ���
//case2: �� �� �θ��尡 ���� ���
void setTree(vector<treeNode> &tree, int num1, int num2) {
    //base case
    if(num1 == 1 || num2 == 1) {
        if(num1 == 1) {
            tree[num2].parent = num1;
            return;
        }
        else if(num2 == 1) {
            tree[num1].parent = num2;
            return;
        }}

    //case1
    if (tree[num1].parent != 0) {
        tree[num2].parent = num1;
        return;
    }
    else if (tree[num2].parent != 0) {
        tree[num1].parent = num2;
        return;
    }
}



int main(void) {
    int N;
    cin >> N;

    vector<treeNode> tree;
    vector<queue<int>> inputs;

    //1~N������ tree�� input ����, 0�κ��� ����
    for(int i = 0; i <= N; i++) {
        treeNode newNode;
        tree.push_back(newNode);

        queue<int> input;
        inputs.push_back(input);
    }

    int Re = N-1;
    while(Re--) {
        int num1, num2;
        cin >> num1 >> num2;

        inputs[num1].push(num2);
        inputs[num2].push(num1);
    }

    for (int i = 0; i < inputs.size(); i++) {
        setTree(tree, inputs[i][0], inputs[i][1]);
    }

    for(int i = 2; i <= N; i++) {
        cout << tree[i].parent <<endl;
    }

    return 0;
}
