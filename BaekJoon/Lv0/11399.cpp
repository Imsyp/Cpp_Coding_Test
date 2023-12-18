#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int N;
    int sum = 0;
    int answer = 0;
    cin >> N;

    vector<int> times;

    while(N--) {
        int time;
        cin >> time;
        times.push_back(time);
    }

    sort(times.begin(), times.end());

    for(int i = 0; i < times.size(); i++) {
        if(i == 0) {
            sum = times[0];
        }
        else {
            sum = sum + times[i];
        }
        answer += sum;
    }

    cout << answer << endl;

    return 0;
}