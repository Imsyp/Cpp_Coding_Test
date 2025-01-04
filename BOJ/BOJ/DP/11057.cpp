#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int DP[1001][10][1001];
const long long MOD = 10007;

// 최대 N자리 수, n번째 자리 수 num
int recursive(int n, int num, int N) {
    // base case: 끝자리에 도달하면 return 1
    if(n == N + 1) {
        return 1;
    }
    
    // DP
    int &ret = DP[n][num][N];
    if(ret != -1) {
        return ret;
    }
    
    // general case: n번째 자리 경우의 수는 n + 1 자리의 0~9 모든 경우의 수의 합
    ret = 0;
    for(int i = num; i <= 9; i++) {
        ret += recursive(n + 1, i, N);
        ret %= MOD;
    }
    
    return ret % MOD;
}

int main() {
    memset(DP, -1, sizeof(DP));
        
    int N;
    cin >> N;
    cout << recursive(1, 0, N) << endl;

    return 0;
}
