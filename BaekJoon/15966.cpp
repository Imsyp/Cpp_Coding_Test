#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main(void) {
    int N;
    cin >> N;
    
    vector<int> arrLen(1000001, 0);
    vector<int> seq;
    while(N--) {
        int term;
        cin >> term;

        seq.push_back(term);
    }

    for(int i = 0; i < seq.size(); i++) {
        arrLen[seq[i]] = arrLen[seq[i] - 1] + 1;
    }

    int result = *max_element(arrLen.begin(), arrLen.end());

    cout << result << endl;
}