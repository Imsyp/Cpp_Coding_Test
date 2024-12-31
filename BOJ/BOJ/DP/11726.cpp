#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int DP[1001];

int recurv(int N) {
    // DP
    int &ret = DP[N];
    if(ret != -1) {
        return ret;
    }
    
    // general case
    ret = recurv(N - 1) + recurv(N - 2);
    return ret % 10007;
}

int main() {
    int N;
    memset(DP, -1, sizeof(DP));
    DP[1] = 1;
    DP[2] = 2;
    
    scanf("%d", &N);
    printf("%d", recurv(N) % 10007);
    
    return 0;
}
