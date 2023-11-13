#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//트리의 num1과 num2 node의 부모 관계 설정
//둘 중 하나가 부모노드가 없으면 true 반환
//둘 다 부모노드가 있으면 false 반환
//정렬 실패하면 false 반환
bool setTree(vector<int> &parent, int num1, int num2) {
    //base case
    if (parent[num1] != 0 && parent[num2] != 0) {
        return false;
    }

    if (parent[num1] != 0 && parent[num2] == 0) {
        parent[num2] = num1; 
        return true;
    } 
    else {
        parent[num1] = num2;
        return true; 
    } 
}  

int main(void) {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> parent;
    vector<stack<int>> inputs;

    //1~N까지의 tree와 input 생성, 0부분은 무시
    for(int i = 0; i <= N; i++) {
        parent.push_back(0);

        stack<int> input;
        inputs.push_back(input);
    }

    //루트 노드 처리
    parent[1] = 100;

    int Re = N-1;
    while(Re--) {
        int num1, num2;
        cin >> num1 >> num2;

        inputs[num1].push(num2);
        inputs[num2].push(num1);
    } 

    stack<int> kStack;
    int key;  
    kStack.push(1); 
    while(!kStack.empty()) {  
        key = kStack.top(); 
        if (inputs[key].empty()) { 
            kStack.pop();   
        }
        while(!inputs[key].empty()) { 
            //이미 탐색이 끝난 요소는 삭제
            //case1: 둘 중 하나가 부모 노드가 없는 경우 -> next key로 이동
            //case2: 둘 다 부모 노드가 있는 경우 -> 현재 key 위치 stack의 top 요소
            //현재 key의 배열이 끝난 경우 -> 이전 key로 회귀
            if (setTree(parent, key, inputs[key].top())) {
                kStack.push(inputs[key].top());
                inputs[key].pop();
                break; 
            }   

            inputs[key].pop();

            /*
            if (inputs[key].empty()) {
                kStack.pop();  
            }
            */
        }
        if(inputs[1].empty() && kStack.top() == 1) {
            break;
        }
    }

    for(int i = 2; i <= N; i++) {
        cout << parent[i] << "\n";
    }

    return 0; 
} 