#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int DP[101][10];    // DP[i][j], i자리 계단수 중 맨 끝이 j인 수의 개수
const long long MOD = 1000000000;

int solution(int n) {
    int ret = 0;
    
    // 2 ~ n자리 계단수
    for(int i = 2; i <= n; i++) {
        // 이전 단계 계단수에서 1로 끝나는 수의 개수 -> 0으로 끝나는 수의 개수
        DP[i][0] = DP[i - 1][1] % MOD;
        
        // general case(1 ~ 8)
        // 이전 단계 +-1의 개수
        for(int j = 1; j <= 8; j++) {
            DP[i][j] = ((DP[i - 1][j - 1]) % MOD + (DP[i - 1][j + 1]) % MOD) % MOD;
        }
        
        // 이전 단계 계단 수에서 8로 끝나는 수의 개수 -> 9로 끝나는 수의 개수
        DP[i][9] = DP[i - 1][8] % MOD;
    }
    
    for(int i = 0; i < 10; i++) {
        ret += DP[n][i];
        ret %= MOD;
    }
    
    return ret % MOD;
}

int main() {
    memset(DP, 0, sizeof(DP));
    
    // 1자리 계단수에서는 모두 하나씩 존재
    for(int i = 1; i < 10; i++) {
        DP[1][i] = 1;
    }
        
    int n;
    cin >> n;
    cout << solution(n) << endl;

    return 0;
}
