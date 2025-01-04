#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

long long DP[91];

// 최대 N자리 수, n번째 자리 수 num
long long solution(int N) {
    for(int i = 3; i <= N; i++) {
        DP[i] = DP[i- 1] + DP[i - 2];
    }
    
    return DP[N];
}

int main() {
    memset(DP, 0, sizeof(DP));
    DP[1] = 1;
    DP[2] = 1;
        
    int N;
    cin >> N;
    cout << solution(N) << endl;

    return 0;
}
