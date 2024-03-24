#include <iostream>
#include <cstring>

using namespace std;

const int SIZE = 1000001;
long long dp[SIZE]; //x보다 작은 약수의 모든 합


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    dp[0] = 0;

    int cases;
    cin >> cases;


    for(long long i = 1; i < SIZE; i++) {
        for(long long j = 1; i * j < SIZE; j++) {
            dp[i * j] += i; //i를 약수로 가지는 수들에 i를 더해줌
        }
        dp[i] += dp[i - 1]; //g(x)만드는 과정
    }

    while(cases--) {
        long long N;
        cin >> N;

        cout << dp[N] << '\n';
    }


    return 0;
}