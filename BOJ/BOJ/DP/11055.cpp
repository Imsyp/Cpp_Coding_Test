#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int DP[1001];
int mat[1001];


int solution(int n) {
    int ret = mat[1];
    
    // 최솟값은 자기자신
    for(int i = 1; i <= n; i++) {
        DP[i] = mat[i];
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            // mat[i]가 mat[j]보다 큰 경우만 (증가수열인 경우만)
            if(mat[i] > mat[j]) {
                DP[i] = max(DP[i], DP[j] + mat[i]);
            }
        }
    }
    
    // 최댓값 탐색
    for(int i = 2; i <= n; i++) {
        ret = max(ret, DP[i]);
    }
    
    return ret;
}

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> mat[i];
    }
    
    cout << solution(n) << endl;

    return 0;
}
