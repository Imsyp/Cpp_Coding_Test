#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void) {
    long long divNum;
    vector<long long> divisors;

    cin >> divNum;

    long long odd = divNum % 2;

    while(divNum--) {
        long long divisor;
        cin >> divisor;

        divisors.push_back(divisor);
    }

    sort(divisors.begin(), divisors.end());

    long long answer;
    if(odd) {
        answer = pow(divisors[(divisors.size() - 1)/ 2], 2);
        cout << answer << endl;
    }
    else {
        answer = divisors[0] * divisors.back();
        cout << answer << endl;
    }

    return 0;
}