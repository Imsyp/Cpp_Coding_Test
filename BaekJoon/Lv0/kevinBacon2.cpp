#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int dfs(vector<vector<int>> friendShip, vector<bool> visited, int person, int f) {
	visited[person] = true;
	for (int i = 0; i < friendShip[person].size(); i++) {
		int y = friendShip[person][i];
		if (!visited[y]) // 방문하지 않았으면 즉 visited가 False일 때 not을 해주면 True가 되므로 아래 dfs 실행
            answer++;
            dfs(friendShip, visited, y, f); // 재귀적으로 방문
	}
}

int shortestPath(vector<vector<int>> friendShip, int person, int f) {
    int answer = 0;
    int minAns = 1000;

    stack<int> posStack;
    posStack.push(person);
    while(!posStack.empty()) {
        int curPos = posStack.top();

        if (friendShip[curPos].empty()) { 
            posStack.pop();   
        }

        //현재 위치에서 f와 일치하는 요소까지 탐색
        //f와 일치하는 거 찾으면 이전 위치로 이동
        //일치하지 않으면 그 다음 위치로
        //스택이 빌 때까지
        for(int i = 1; i <= friendShip[curPos].size(); i++) {
            if(friendShip[curPos][i] == f) {
                if(minAns > answer) {
                    minAns = answer;
                }
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
    vector<vector<int>> friendShip;

    int N, M;
    cin >> N >> M;

    for(int i = 0; i <= N; i++) {
        vector<int> person;
        friendShip.push_back(person);
    }

    //친구 관계 설정
    while(M--) {
        int friend1, friend2;
        cin >> friend1 >> friend2;

        friendShip[friend1].push_back(friend2);
        friendShip[friend2].push_back(friend1);
    }

    int answer = 0;
    int minKB = 1000;

    for(int i = N; i > 0; i--) {
        int kevinBacon = 0;
        for(int j = 1; j <= N; j++) {
            if(i != j) {
                kevinBacon += shortestPath(friendShip, i, j);   //i부터 j로 가는 최단경로
            }
        }

        if(minKB >= kevinBacon) {
            minKB = kevinBacon;
            answer = i; //가장 작은 케빈 베이컨을 가진 사람이 정답
        }
    }

    cout << answer;

    return 0;
}