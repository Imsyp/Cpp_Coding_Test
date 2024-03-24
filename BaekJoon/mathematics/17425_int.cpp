#include <iostream>
#include <cstring>

using namespace std;

const int SIZE = 100001;
int dp[SIZE]; //x보다 작은 약수의 모든 합


int main(void) {
    memset(dp, 0, sizeof(dp));

    int cases;
    cin >> cases;


    for(int i = 1; i <= SIZE; i++) {
        for(int j = 1; i * j <= SIZE; j++) {
            dp[i * j] += i; //i를 약수로 가지는 수들에 i를 더해줌
        }
        dp[i] += dp[i - 1]; //g(x)만드는 과정
    }

    while(cases--) {
        int N;
        cin >> N;

        cout << dp[N] << endl;
    }


    return 0;
}