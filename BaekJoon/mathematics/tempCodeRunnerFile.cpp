#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void) {
    int divNum;
    vector<int> divisors;

    cin >> divNum;

    int odd = divNum % 2;

    while(divNum--) {
        int divisor;
        cin >> divisor;

        divisors.push_back(divisor);
    }

    sort(divisors.begin(), divisors.end());

    if(odd) {
        cout << pow(divisors[(divisors.size() - 1)/ 2], 2) << endl;
    }
    else {
        cout << divisors[0] * divisors.back() << endl;
    }

    return 0;
}