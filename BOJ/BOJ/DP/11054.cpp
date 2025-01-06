#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int ascDP[1001];    // mat[i] 기준 좌측의 가장 긴 증가하는 부분 수열 크기(mat[i]가 최댓값)
int desDP[1001];    // mat[i] 기준 우측의 가장 긴 감소하는 부분 수열 크기(mat[i]가 최댓값)
int bitDP[1001];
int mat[1001];


int solution(int n) {
    int ret = 1;
    
    
    for(int i = 1; i <= n; i++) {
        // mat[i] 기준 좌측의 가장 긴 증가하는 부분 수열 크기(mat[i]가 최댓값)
        for(int j = 1; j <= i; j++) {
            if(mat[i] > mat[j]) {
                ascDP[i] = max(ascDP[j] + 1, ascDP[i]);
            }
        }
    }
    
    for(int i = n; i >= 1; i--) {
        // mat[i] 기준 우측의 가장 긴 감소하는 부분 수열 크기(mat[i]가 최댓값)
        for(int j = n; j > i; j--) {
            if(mat[i] > mat[j]) {
                desDP[i] = max(desDP[j] + 1, desDP[i]);
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        bitDP[i] = ascDP[i] + desDP[i] - 1;
    }
    
    // 가장 긴 바이토닉 수열 계산
    for(int i = 1; i <= n; i++) {
        ret = max(bitDP[i], ret);
    }
    
    return ret;
}

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> mat[i];
        ascDP[i] = 1;
        desDP[i] = 1;
    }
    
    cout << solution(n) << endl;

    return 0;
}
