#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int shortestPath(vector<stack<int>> friendShip, int person, int f) {
    int answer = 0;
    int minAns = 1000;

    stack<int> posStack;
    posStack.push(person);
    while(!posStack.empty()) {
        int curPos = posStack.top();
        if(curPos == 0) {
            break;
        }

        //현재 위치에서 f와 일치하는 요소까지 탐색
        //f와 일치하는 거 찾으면 이전 위치로 이동
        //일치하지 않으면 그 다음 위치로
        //스택이 빌 때까지
        while(!friendShip[curPos].empty()) {
            if(friendShip[curPos].top() == f) {
                if(minAns > answer) {
                    minAns = answer;
                    posStack.pop();
                    curPos = posStack.top();
                    answer--;
                }
            }

            //다음 위치로 넘어가기 전에 요소 삭제
            if(!friendShip[curPos].empty()) {
                int tmp = friendShip[curPos].top(); //4
                friendShip[posStack.top()].pop();   //4 지워

                //일치하지 않으면 다음 위치로 넘어감
                //다음 위치로 넘어가면 answer++
                curPos = tmp;  
                posStack.push(curPos);
                answer++;
            }


            //해당 위치 탐색 끝났으면 이전 위치로
            //이전 위치로 가면서 answer--
            if(friendShip[curPos].empty()) {
                posStack.pop();
                answer--;
            }
        }
        posStack.pop();
        answer--;
    }

    return answer;
}



int main(void) {
    vector<stack<int>> friendShip;

    int N, M;
    cin >> N >> M;

    for(int i = 0; i <= N; i++) {
        stack<int> person;
        friendShip.push_back(person);
    }

    while(M--) {
        int friend1, friend2;
        cin >> friend1 >> friend2;

        friendShip[friend1].push(friend2);
        friendShip[friend2].push(friend1);
    }

    int answer = 0;
    int minKB = 1000;

    for(int i = N; i > 0; i--) {
        int kevinBacon = 0;
        for(int j = 1; j <= N; j++) {
            if(i != j) {
                kevinBacon += shortestPath(friendShip, i, j);
            }
        }

        if(minKB >= kevinBacon) {
            minKB = kevinBacon;
            answer = i;
        }
    }

    cout << answer;

    return 0;
}