#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class treeNode {
public:
        int parent = 0; 
};

//트리의 num1과 num2 node의 부모 관계 설정
//둘 중 하나가 부모노드가 없으면 true 반환
//둘 다 부모노드가 있으면 false 반환
//정렬 실패하면 false 반환
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

    //1~N까지의 tree와 input 생성, 0부분은 무시
    for(int i = 0; i <= N; i++) {
        treeNode newNode;
        tree.push_back(newNode);

        vector<int> input;
        inputs.push_back(input);
    }

    //루트 노드 처리
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
            //case1: 둘 중 하나가 부모 노드가 없는 경우 -> next key로 이동
            //case2: 둘 다 부모 노드가 있는 경우 -> 현재 key의 다음 요소로 진행
            //현재 key의 배열이 끝난 경우 -> 이전 key로 회귀
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
