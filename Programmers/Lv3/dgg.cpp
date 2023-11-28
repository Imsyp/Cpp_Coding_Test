#include <string>
#include <vector>
#include <cstring>

using namespace std;

int board[101][101];

int dinP(int y, int x, int m, int n) {
    int answer = 0;
    //웅덩이 만나면 return 0
    if(board[y][x] == -2) {
        return 0;
    }
    else if(board[y][x] != -1) {
        return board[y][x];
    }

    //base case: 범위 넘어가면 0 반환
    if(y > m || x > n) {
        return 0;
    }

    //m, n 도착하면 answer++
    if(y == m && x == n) {
        return 1;
    }

    answer += dinP(y+1, x, m, n);
    answer += dinP(y, x+1, m, n);

    board[y][x] = answer % 1000000007;

    return answer % 1000000007;
}

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    memset(board, -1, sizeof(board));

    //board에 물웅덩이 위치 설정
    for(int i = 0; i < puddles.size(); i++) {
        board[puddles[i][0]-1][puddles[i][1]-1] = -2;
    }

    answer = dinP(0, 0, m - 1, n - 1);

    return answer;
}