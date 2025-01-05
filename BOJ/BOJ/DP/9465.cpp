#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

long long Matrix[2][100001];
long long DP[2][100001];


long long solution(int n) {
    memset(DP, 0, sizeof(DP));
    DP[0][1] = Matrix[0][1];
    DP[1][1] = Matrix[1][1];
    
    for(int j = 2; j <= n; j++) {
        DP[0][j] = Matrix[0][j] + max(DP[1][j - 2], DP[1][j - 1]);
        DP[1][j] = Matrix[1][j] + max(DP[0][j - 2], DP[0][j - 1]);
    }
    
    return max(DP[0][n], DP[1][n]);
}

int main() {
    int cases, n;
    cin >> cases;
    while(cases--) {
        cin >> n;
        for(int i = 0; i < 2; i++) {
            for(int j = 1; j <= n; j++) {
                cin >> Matrix[i][j];
            }
        }
        
        cout << solution(n) << endl;
    }
    
    
    return 0;
}
