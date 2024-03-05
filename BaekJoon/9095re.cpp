#include <iostream>
#include <cstring>

using namespace std;

int cache[11];


//정수 n을 1, 2, 3의 합으로 나타내는 경우의 수를 반환
int sum123(int n) {
    cache[1] = 1;
    cache[2] = 2;
    cache[3] = 4;

    int &ret = cache[n];
    if(ret != -1) {
        return ret;
    }

    int sum = 0;
    for(int i = 1; i <= 3; i++) {
        sum += sum123(n - i);
    }
    ret = sum;

    return ret;
}

int main(void) {
    int cases;
    cin >> cases;

    while(cases--) {
        memset(cache, -1, sizeof(cache));

        int n;
        cin >> n;

        cout << sum123(n) << endl;
    }

    return 0;
}