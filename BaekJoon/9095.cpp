#include <iostream>
#include <cstring>

using namespace std;

int cache[11];

//정수 N을 1, 2, 3의 합으로 나타내는 방법의 수를 반환
int sum123(int N) {
    //base case: N이 1, 2, 3일 때
    if(N == 1) {
        return 1;
    }

    if(N == 2) {
        return 2;
    }

    if(N == 3) {
        return 4;
    }

    int &ret = cache[N];
    if(ret != -1) {
        return ret;
    }

    //1로만 더하는 경우
    int sum = 0;
    //sum123(N) = sum123(N - 1) + sum123(N - 2) + sum123(N - 3)
    for(int i = 1; i <= 3; i++) {
        sum += sum123(N - i);
    }

    ret = sum;

    return ret;
}

int main(void) {
    int cases;
    cin >> cases;

    while(cases--) {
        memset(cache, -1, sizeof(cache));

        int N;
        cin >> N;

        cout << sum123(N) << endl;
    }
}
