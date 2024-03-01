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

        //���� ��ġ���� f�� ��ġ�ϴ� ��ұ��� Ž��
        //f�� ��ġ�ϴ� �� ã���� ���� ��ġ�� �̵�
        //��ġ���� ������ �� ���� ��ġ��
        //������ �� ������
        while(!friendShip[curPos].empty()) {
            if(friendShip[curPos].top() == f) {
                if(minAns > answer) {
                    minAns = answer;
                    posStack.pop();
                    curPos = posStack.top();
                    answer--;
                }
            }

            //���� ��ġ�� �Ѿ�� ���� ��� ����
            if(!friendShip[curPos].empty()) {
                int tmp = friendShip[curPos].top(); //4
                friendShip[posStack.top()].pop();   //4 ����

                //��ġ���� ������ ���� ��ġ�� �Ѿ
                //���� ��ġ�� �Ѿ�� answer++
                curPos = tmp;  
                posStack.push(curPos);
                answer++;
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