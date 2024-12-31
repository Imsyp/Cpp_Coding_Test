#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int DP[1000001];
const int INF = 1000000;

int recurv(int N) {
    // base case: N이 1인 경우
    if(N == 1) {
        return 0;
    }
    
    // DP
    int &ret = DP[N];
    if(ret != -1) {
        return ret;
    }
    
    ret = INF;
    // general case 1: 3으로 나누어 떨어지는 경우 -> 3으로 나눈다.
    if(N % 3 == 0) {
        ret = recurv(N / 3) + 1;
    }
    
    // general case 2: 2로 나누어 떨어지는 경우 -> 2로 나눈다.
    if(N % 2 == 0) {
        int rtn1 = recurv(N / 2) + 1;
        ret = (rtn1 < ret) ? rtn1 : ret;
    }
    
    // general case 3: 1을 뺀다.
    int rtn2 = recurv(N - 1) + 1;
    ret = (rtn2 < ret) ? rtn2 : ret;
    
    return ret;
}

int main() {
    int N;
    memset(DP, -1, sizeof(DP));
    scanf("%d", &N);
    printf("%d", recurv(N));
    
    return 0;
}

