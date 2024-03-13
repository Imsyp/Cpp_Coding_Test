#include <iostream>
#include <algorithm>

using namespace std;

char board[50][50];

//board 위의 y, x 위치를 받아, 해당 위치에서 시작하는 8 * 8 크기의 chess판을 만들기 위해 다시 칠해야 하는 정사각형의 최솟값 반환
int make8Chess(int y, int x) {
    int case1 = 0, case2 = 0;

    //case 1
    for(int i = y; i < y + 8; i++) {
        if(i % 2 == 0) {
            for(int j = x; j < x + 8; j += 2) {
                if(board[i][j] != 'B') {
                    case1++;
                }
            }
        }
        else{
            for(int k = x + 1; k < x + 8; k += 2) {
                if(board[i][k] != 'B') {
                    case1++;
                }
            }
        }
    }

    for(int i = y; i < y + 8; i++) {
        if(i % 2 != 0) {
            for(int j = x; j < x + 8; j += 2) {
                if(board[i][j] != 'W') {
                    case1++;
                }
            }
        }
        else{
            for(int k = x + 1; k < x + 8; k += 2) {
                if(board[i][k] != 'W') {
                    case1++;
                }
            }
        }
    }

    //case 2
    for(int i = y; i < y + 8; i++) {
        if(i % 2 == 0) {
            for(int j = x; j < x + 8; j += 2) {
                if(board[i][j] != 'W') {
                    case2++;
                }
            }
        }
        else{
            for(int k = x + 1; k < x + 8; k += 2) {
                if(board[i][k] != 'W') {
                    case2++;
                }
            }
        }
    }

    for(int i = y; i < y + 8; i++) {
        if(i % 2 != 0) {
            for(int j = x; j < x + 8; j += 2) {
                if(board[i][j] != 'B') {
                    case2++;
                }
            }
        }
        else{
            for(int k = x + 1; k < x + 8; k += 2) {
                if(board[i][k] != 'B') {
                    case2++;
                }
            }
        }
    }

    return min(case1, case2);
}

//board의 최대 크기를 받아, 가능한 모든 경우의 make8Chess를 돌려 최솟값을 반환
int makeChess(int Y, int X) {
    int answer = 32;

    for(int i = 0; i <= Y - 8; i ++) {
        for(int j = 0; j <= X - 8; j++) {
            answer = min(answer, make8Chess(i, j));
        }
    }

    return answer;
}


int main(void) {
    int M, N;
    cin >> M >> N;

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    cout << makeChess(M, N) << endl;

    return 0;
}