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
            tmpStack.push(board[j][i]); //가로인지 세로인지 확인하자,,, 너무 헷갈리게 냈더라
        }
        gameBoard.push_back(tmpStack);
    }

    for(int i = 0; i < moves.size(); i++) {
        stack<int>& stackNow = gameBoard[moves[i] - 1]; //참조형으로 선언하지 않으면 복사만 되어 아래에서 pop이 적용되지 않음!!!

        //현재 크레인 라인이 비어있으면 다음 moves로 스킵
        if(stackNow.empty()) {
            continue;
        }

        int tmp = stackNow.top();

        //basket이 비어있으면 basket에 쌓고 stacknow는 pop, basket에 push
        //basket 맨 위에 있던 게 새로 가져온 거랑 일치O -> stacknow, basket 모두 pop -> answer + 2
        //basket 맨 위에 있던 게 새로 가져온 거랑 일치X -> stacknow는 pop, basket에 push
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