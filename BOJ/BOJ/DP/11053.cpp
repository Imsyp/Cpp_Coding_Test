#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int DP[1001];
int mat[1001];


int solution(int n) {
    int ret = 1;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j < i; j++) {
            // mat[i]보다 값이 작은 경우에만
            if(mat[j] < mat[i]) {
                DP[i] = max(DP[j] + 1, DP[i]);
            }
        }
    }
    
    // 최댓값 탐색
    for(int i = 1; i < n; i++) {
        ret = max(DP[i + 1], ret);
    }
    
    return ret;
}

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> mat[i];
        DP[i] = 1;  // 최솟값 1로 모두 초기화 (memset으로는 1로 초기화 불가)
    }
    
    cout << solution(n) << endl;

    return 0;
}
