#include <iostream>
#include <vector>
#include <stack>
#include <map>

using namespace std;

//트리의 num1과 num2 node의 부모 관계 설정
//둘 중 하나가 부모노드가 없으면 true 반환
//둘 다 부모노드가 있으면 false 반환
//정렬 실패하면 false 반환
bool setTree(map<int, int> &myMap, int num1, int num2) {
    //base case
    if (myMap[num1] != 0 && myMap[num2] != 0) {
        return false;
    }

    if (myMap[num1] != 0 && myMap[num2] == 0) {
        myMap[num2] = num1; 
        return true;
    } 
    else {
        myMap[num1] = num2;
        return true; 
    } 
}

int main(void) {
    int N;
    cin >> N;

    map<int, int> myMap;
    vector<stack<int>> inputs;

    //1~N까지의 tree와 input 생성, 0부분은 무시
    for(int i = 0; i <= N; i++) {
        myMap.insert({i, 0});

        stack<int> input;
        inputs.push_back(input);
    }

    //루트 노드 처리
    myMap[1] = 100;

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
        while(!inputs[key].empty()) {
            //case1: 둘 중 하나가 부모 노드가 없는 경우 -> next key로 이동
            //case2: 둘 다 부모 노드가 있는 경우 -> 현재 key의 다음 요소로 진행
            //현재 key의 배열이 끝난 경우 -> 이전 key로 회귀
            if (setTree(myMap, key, inputs[key].top())) {
                kStack.push(inputs[key].top());
                inputs[key].pop();
                break; 
            }   

            inputs[key].pop();

            if (inputs[key].empty()) {
                kStack.pop();  
            }
        }
        if(inputs[1].empty() && kStack.top() == 1) {
            break;
        }
    }

    for(int i = 2; i <= N; i++) {
        cout << myMap[i] <<endl;
    }

    return 0;
}