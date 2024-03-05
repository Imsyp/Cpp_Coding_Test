#include <iostream>
#include <cstring>

using namespace std;

int cache0[41], cache1[41];

//피보나치 함수
int fibonacci(int n) {
    if (n == 0) {
        cout << 0;
        return 0;
    } else if (n == 1) {
        cout << 1;
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

//N을 fibonacci 함수에 넣었을 때, 출력되는 0의 횟수를 반환
int fibo0(int N) {
    //base case: N이 0, 1일 때
    if(N == 0) {
        return 1;
    }

    if(N == 1) {
        return 0;
    }

    int &ret = cache0[N];
    if(ret != -1) {
        return ret;
    }

    return ret = fibo0(N - 1) + fibo0(N -2);
}

//N을 fibonacci 함수에 넣었을 때, 출력되는 1의 횟수를 반환
int fibo1(int N) {
    //base case: N이 0, 1일 때
    if(N == 0) {
        return 0;
    }

    if(N == 1) {
        return 1;
    }

    int &ret = cache1[N];
    if(ret != -1) {
        return ret;
    }

    return ret = fibo1(N - 1) + fibo1(N -2);
}

int main(void) {
    int cases;
    cin >> cases;

    while(cases--) {
        memset(cache0, -1, sizeof(cache0));
        memset(cache1, -1, sizeof(cache1));

        int N;
        cin >> N;

        cout << fibo0(N) << " " << fibo1(N) << endl;
    }

    return 0;
}