#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N, cache[1000001];
const int INF = 1000000;

//N이 1이 되는 연산의 최소 횟수를 반환
int dp(int N) {
    //base case: N이 1보다 작아지는 경우
    if(N < 1) {
        return INF;
    }

    //base case: N이 1인 경우
    if(N == 1) {
        return 0;
    }

    int &ret = cache[N];
    //cache에 값이 저장된 경우
    if(ret != -1) {
        return ret;
    }

    ret = dp(N - 1) + 1;
    if(N % 3 == 0) {
        ret = min(ret, dp(N / 3)) + 1;
    }
    if(N % 2 == 0) {
        ret = min(ret, dp(N / 2)) + 1;
    }

    return ret;
}

int main(void) {
    memset(cache, -1, sizeof(cache));
    cache[1] = 0;

    cin >> N;
    cout << dp(N) << endl;

    return 0;
}