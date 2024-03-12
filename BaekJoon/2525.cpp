#include <iostream>

using namespace std;

int main(void) {
    int minute, hour, cookTime, totalTime;
    cin >> hour >> minute;
    cin >> cookTime;

    //분 단위로 변경 후, 시각으로 변경
    totalTime = minute + (hour * 60) + cookTime;

    totalTime %= 24 * 60;
    int nowHour = totalTime / 60;
    int nowMin = totalTime % 60;

    cout << nowHour << " " << nowMin << endl;
    
    return 0;
}