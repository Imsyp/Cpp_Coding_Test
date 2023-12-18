#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int N, K;
    int sum = 0;
    cin >> N >> K;

    vector<int> prices; 

    while(N--) {
        int price;
        cin >> price;

        prices.insert(prices.begin(), price);
    }

    for(int i = 0; i < prices.size(); i++) {
        if(K / prices[i] > 0) {
            sum += K / prices[i];
            K %= prices[i];
        }
    }

    cout << sum << endl;

    return 0;
}