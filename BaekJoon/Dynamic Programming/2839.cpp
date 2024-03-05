#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int dp[5001];
const int INF = 2000;

//배달해야하는 설탕의 무게를 입력으로 받고, 봉지의 최소 개수를 반환
int bagNum(int sugarWeight) {
    //base case: 설탕의 무게가 음수
    if(sugarWeight < 0) {
        return INF;
    }

    //base case: 설탕의 무게가 0
    if(sugarWeight == 0) {
        return 0;
    }

    //base case: 설탕의 무게가 3 혹은 5이면 1을 반환
    if(sugarWeight == 3 || sugarWeight == 5) {
        return 1;
    }

    //현재 sugarWeight에서 최소 봉지 개수
    int &ret = dp[sugarWeight];

    //이미 cached에 저장되어있으면 해당 값 반환
    if(ret != -1) {
        return ret;
    }

    //3과 5의 case 중 작은 경우를 더함
    int addNum = min(bagNum(sugarWeight - 3), bagNum(sugarWeight - 5));
    ret = addNum + 1;

    return ret;
}

int main(void) {
    int sugarWeight;
    cin >> sugarWeight;

    memset(dp, -1, sizeof(dp));

    if(bagNum(sugarWeight) < INF) {
        cout << bagNum(sugarWeight) <<endl;
    }
    else {
        cout << -1 << endl;
    }

    return 0;
}