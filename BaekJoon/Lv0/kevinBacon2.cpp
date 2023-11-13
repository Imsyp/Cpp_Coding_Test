#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int dfs(vector<vector<int>> friendShip, vector<bool> visited, int person, int f) {
	visited[person] = true;
	for (int i = 0; i < friendShip[person].size(); i++) {
		int y = friendShip[person][i];
		if (!visited[y]) // �湮���� �ʾ����� �� visited�� False�� �� not�� ���ָ� True�� �ǹǷ� �Ʒ� dfs ����
            answer++;
            dfs(friendShip, visited, y, f); // ��������� �湮
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

        //���� ��ġ���� f�� ��ġ�ϴ� ��ұ��� Ž��
        //f�� ��ġ�ϴ� �� ã���� ���� ��ġ�� �̵�
        //��ġ���� ������ �� ���� ��ġ��
        //������ �� ������
        for(int i = 1; i <= friendShip[curPos].size(); i++) {
            if(friendShip[curPos][i] == f) {
                if(minAns > answer) {
                    minAns = answer;
                }
            }

            //�ش� ��ġ Ž�� �������� ���� ��ġ��
            //���� ��ġ�� ���鼭 answer--
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

    //ģ�� ���� ����
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
                kevinBacon += shortestPath(friendShip, i, j);   //i���� j�� ���� �ִܰ��
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