#include <iostream>

using namespace std;

int main(void) {
    long long sum = 0, N;
    cin >> N;

    for(int i = 1; i <= N; i++) {
        sum += (N / i) * i; //i의 배수는 항상 i를 약수로 가진다. -> i가 등장하는 횟수 = N보다 작은 i의 배수 개수
    }

    cout << sum << endl;

    return 0;
}