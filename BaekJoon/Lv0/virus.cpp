#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int dfs(vector<stack<int>> relations) {
    stack<int> pStack;
    pStack.push(1);

    vector<bool> virus(relations.size(), false);

    int curPos;
    while(!pStack.empty()) {
        curPos = pStack.top();
        if (relations[curPos].empty()) { 
            pStack.pop();   
        }

        while(relations[curPos].empty()) {
            if(virus[relations[curPos].top()] == false) {
                virus[relations[curPos].top()] = true;

                pStack.push(relations[curPos].top());
                relations[curPos].pop();
                break;
            }

            relations[curPos].pop();
        }

        if(relations[1].empty() && pStack.top() == 1) {
            break;
        }
    }

    int answer = 0;
    for(int i = 2; i <= virus.size(); i++) {
        if(virus[i] == true) {
            answer++;
        }
    }

    return answer;
}


int main(void) {
    int N;
    cin >> N;

    vector<stack<int>> relations;

    for(int i = 0; i < N; i++) {
        stack<int> relation;
        relations.push_back(relation);
    }

    int M;
    cin >> M;

    for(int i = 0; i < M; i ++) {
        int com1, com2;
        cin >> com1 >> com2;

        relations[com1].push(com2);
        relations[com2].push(com1);
    }

    cout<<endl;

    cout << dfs(relations) << endl;
    
    return 0;
}