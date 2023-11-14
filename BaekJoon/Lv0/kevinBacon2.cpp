#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> makePL(vector<vector<int>> friendShip, int person) {
    queue<int> posQ;
    posQ.push(person);

    int N = friendShip.size();

    vector<int> pathLen(N, 0);

    int curPos;
    while(!posQ.empty()) {
        curPos = posQ.front();
        for(int i = 0; i < friendShip[curPos].size(); i++) {
            //curPos의 주변 사람의 거리가 설정돼있지 않다면, 현재 사람 거리의 +1
            if(pathLen[friendShip[curPos][i]] == 0) {
                posQ.push(friendShip[curPos][i]);
                pathLen[friendShip[curPos][i]] = pathLen[curPos] + 1;   
            }
        }
        posQ.pop();
    }

    return pathLen;
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

    //makePL 함수는 친구 관계와 학생 번호를 input으로 받아, output으로 그 학생의 pathLen 배열 반환
    for(int i = N; i > 0; i--) {
        int kevinBacon = 0;
        vector<int> pathLen;
        pathLen = makePL(friendShip, i);
        for(int j = 1; j <= N; j++) {
            if(i != j) {
                kevinBacon += pathLen[j];
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