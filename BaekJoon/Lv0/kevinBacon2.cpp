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
            //curPos�� �ֺ� ����� �Ÿ��� ���������� �ʴٸ�, ���� ��� �Ÿ��� +1
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

    //ģ�� ���� ����
    while(M--) {
        int friend1, friend2;
        cin >> friend1 >> friend2;

        friendShip[friend1].push_back(friend2);
        friendShip[friend2].push_back(friend1);
    }

    int answer = 0;
    int minKB = 1000;

    //makePL �Լ��� ģ�� ����� �л� ��ȣ�� input���� �޾�, output���� �� �л��� pathLen �迭 ��ȯ
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
            answer = i; //���� ���� �ɺ� �������� ���� ����� ����
        }
    }

    cout << answer;

    return 0;
}


//�ִ� �Ÿ� ������ dfs�� �̿��� Ǯ���� �ϸ� ������ ����������! ������ ��Ʋ���� dfs�� Ǯ���� ��� �ϳ� �ߴ�..
//�ִ� �Ÿ� ������ bfs�� �̿��� Ǯ�� �����ϰ� Ǯ �� �ִ�!
//���� ��ġ������ �Ÿ��� �����ϰ� ���� ��ġ���� �Ļ��Ǵ� ��ġ�� ���� ��ġ�� �Ÿ��� +���ָ� �����ϰ� �ذ��� �� �ִ�.