#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    vector<int> arr;

    while(n--) {
        int i;
        cin >> i;
        arr.push_back(i);
    }

    vector<int> maxSum(arr.size(), -1001);

    int temp = -1001;
    for(int i = 0; i < arr.size(); i++) {
        if(temp + arr[i] > arr[i]) {
            temp += arr[i];
        }
        else {
            temp = arr[i];
        }

        maxSum[i] = temp;
    }

    cout << *max_element(maxSum.begin(), maxSum.end());

    return 0;
}