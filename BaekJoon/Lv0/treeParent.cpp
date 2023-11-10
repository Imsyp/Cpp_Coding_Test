#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class treeNode {
public:
        int parent = 0;
};

//트리의 num1과 num2 node의 부모 관계 설정
//base case: 둘 중 하나가 1인 경우
//case1: 둘 중 하나의 노드가 부모노드가 있는 경우
//case2: 둘 다 부모노드가 없는 경우
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

    //1~N까지의 tree와 input 생성, 0부분은 무시
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
