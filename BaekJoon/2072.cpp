#include <iostream>
#include <algorithm>

using namespace std;

int solution(int x, int y, int w, int h) {
    return min({x, y, w - x, h - y});
}


int main(void) {
    int x, y, w, h;
    cin >> x >> y >> w >> h;

    cout << solution(x, y, w, h) << endl;
}