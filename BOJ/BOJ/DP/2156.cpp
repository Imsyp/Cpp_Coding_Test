#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

long long Mat[10001];
long long DP[10001];

long long solution(int N) {
    memset(DP, 0, sizeof(DP));
    DP[1] = Mat[1];
    DP[2] = Mat[2] + DP[1];
    
    for(int i = 3; i <= N; i++) {
        DP[i] = Mat[i] + max(DP[i - 3] + Mat[i - 1], DP[i - 2]);
        DP[i] = max(DP[i], DP[i - 1]);
    }
    
    return DP[N];
}

int main() {
    int N;
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> Mat[i];
    }
    
    cout << solution(N) << endl;
    
    return 0;
}

