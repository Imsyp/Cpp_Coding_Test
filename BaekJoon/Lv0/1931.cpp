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

    //end time 기준 정렬 후 가장 이른 end time보다 start time이 늦은 요소만 times에 남긴다
    // sort(times.begin(), times.end());
    // while(!times.empty()) {
    //     vector<vector<int>> newTimes;
    //     for(int i = 1; i < times.size(); i++) {
    //         if(times[0][0] <= times[i][1]) {
    //             newTimes.push_back(times[i]);
    //         }
    //     }
    //     times = newTimes;
    //     sum++;
    // }


    sort(times.begin(), times.end());
    int curEnd = 0;
    //curEnd보다 start가 느리거나 같으면 sum++
    for(int i = 0; i < times.size(); i++) {
        if(curEnd <= times[i][1]) {
            curEnd = times[i][0];
            sum++;
        }
    }  
    cout << sum << endl;

    return 0;
}