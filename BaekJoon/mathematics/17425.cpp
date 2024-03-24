#include <iostream>
#include <cmath>

using namespace std;

//n의 약수의 총합
long long divSum(int n) {
    if(n == 1) {
        return 1;
    }

    long long sum = 0;

    for(int i = 1; i <= sqrt(n); i++) {
        if(i == sqrt(n)) {
            sum += i;
            break;
        }
        if(n % i == 0) {
            sum += (i + n/i);
        }
    }

    return sum;
}

//N보다 작은 모든 n의 약수의 합
long long divTotalSum(int N) {
    if(N == 1) {
        return 1;
    }

    long long totalSum = 0;
    
    for(int i = 1; i <= N; i++) {
        totalSum += divSum(i);
    }

    return totalSum;
}

int main(void) {
    int cases;
    cin >> cases;

    while(cases--) {
        int N;
        cin >> N;

        cout << divTotalSum(N) << endl;
    }

    return 0;
}