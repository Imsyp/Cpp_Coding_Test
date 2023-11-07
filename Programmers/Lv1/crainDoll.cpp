#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;

    vector<stack<int>> gameBoard;
    stack<int> basket;

    for(int i = 0; i < board.size(); i++) {
        stack<int> tmpStack;
        for(int j = board[i].size() - 1; j >= 0; j--) {
            if(board[j][i] == 0) {
                continue;
            }
            tmpStack.push(board[j][i]);
        }
        gameBoard.push_back(tmpStack);
    }

    for(int i = 0; i < moves.size(); i++) {
        stack<int>& stackNow = gameBoard[moves[i] - 1];

        //���� ũ���� ������ ��������� ���� moves�� ��ŵ
        if(stackNow.empty()) {
            continue;
        }

        int tmp = stackNow.top();

        //basket�� ��������� basket�� �װ� stacknow�� pop, basket�� push
        //basket �� ���� �ִ� �� ���� ������ �Ŷ� ��ġO -> stacknow, basket ��� pop -> answer + 2
        //basket �� ���� �ִ� �� ���� ������ �Ŷ� ��ġX -> stacknow�� pop, basket�� push
        if(basket.empty()) {
            stackNow.pop();
            basket.push(tmp);
        }
        else if(basket.top() == tmp) {
            stackNow.pop();
            basket.pop();
            answer += 2;
        }
        else if(basket.top() != tmp) {
            basket.push(tmp);
            stackNow.pop();
        }
    }

    return answer;
}