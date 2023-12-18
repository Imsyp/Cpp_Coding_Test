#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int N;
    cin >> N;

    int sum = 0;
    vector<vector<int>> times;
    while(N--) {
        int start, end;
        cin >> start >> end;

        vector<int> time;
        time.push_back(end);
        time.push_back(start);
        times.push_back(time);
    }

    while(!times.empty()) {
        sort(times.begin(), times.end());
        vector<vector<int>> newTimes;
        for(int i = 1; i < times.size(); i++) {
            
            if(times[0][0] <= times[i][1]) {
                newTimes.push_back(times[i]);
            }
        }
        times = newTimes;
        sum++;
    }
  
    cout << sum << endl;

    return 0;
}