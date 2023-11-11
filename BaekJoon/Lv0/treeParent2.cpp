#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class treeNode {
public:
        int parent = 0; 
};

//Ʈ���� num1�� num2 node�� �θ� ���� ����
//�� �� �ϳ��� �θ��尡 ������ true ��ȯ
//�� �� �θ��尡 ������ false ��ȯ
//���� �����ϸ� false ��ȯ
bool setTree(vector<treeNode> &tree, int num1, int num2) {
    //base case
    if (tree[num1].parent != 0 && tree[num2].parent != 0) {
        return false;
    }

    if (tree[num1].parent != 0 && tree[num2].parent == 0) {
        tree[num2].parent = num1; 
        return true;
    } 
    else {
        tree[num1].parent = num2;
        return true; 
    } 
}

int main(void) {
    int N;
    cin >> N;

    vector<treeNode> tree;
    vector<vector<int>> inputs;

    //1~N������ tree�� input ����, 0�κ��� ����
    for(int i = 0; i <= N; i++) {
        treeNode newNode;
        tree.push_back(newNode);

        vector<int> input;
        inputs.push_back(input);
    }

    //��Ʈ ��� ó��
    tree[1].parent = 100;

    int Re = N-1;
    while(Re--) {
        int num1, num2;
        cin >> num1 >> num2;

        inputs[num1].push_back(num2);
        inputs[num2].push_back(num1);
    } 

    stack<int> kStack;
    int key;  
    kStack.push(1); 
    while(!kStack.empty()) { 
        key = kStack.top(); 
        cout<<kStack.top()<<endl;
        for (int i = 0; i < inputs[key].size(); i++) {
            //case1: �� �� �ϳ��� �θ� ��尡 ���� ��� -> next key�� �̵�
            //case2: �� �� �θ� ��尡 �ִ� ��� -> ���� key�� ���� ��ҷ� ����
            //���� key�� �迭�� ���� ��� -> ���� key�� ȸ��
            if (setTree(tree, key, inputs[key][i])) {
                kStack.push(inputs[key][i]);
                break; 
            }   
            
            if (i == inputs[key].size() -1) {
                kStack.pop();  
            }
        }
    }

    for(int i = 2; i <= N; i++) {
        cout << tree[i].parent <<endl;
    }

    return 0;
}
