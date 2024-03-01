#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main(void) {
    long N;
    cin >> N;
    long M = N - 1;

    vector<long> distances;
    while(M--) {
        long distance;
        cin >> distance;
        distances.push_back(distance);
    }

    vector<long> prices;
    while(N--) {
        long price;
        cin >> price;
        prices.push_back(price);
    }

    vector<long> stopStation;
    stopStation.push_back(0);
    long stop = 0;
    for(int i = 0; i < prices.size() - 1; i++) {
        if(prices[stop] > prices[i]) {
            stop = i;
            stopStation.push_back(stop);
        }
    }

    long priceSum = 0;
    for(int i = 0; i < stopStation.size(); i++) {
        if(i != stopStation.size() - 1) {
            priceSum += prices[stopStation[i]] * accumulate(distances.begin() + stopStation[i], distances.begin() + stopStation[i + 1], 0);
        }
        else {
            priceSum += prices[stopStation[i]] * accumulate(distances.begin() + stopStation[i], distances.end(), 0);
        }
    }

    cout << priceSum << endl;

    return 0;
}