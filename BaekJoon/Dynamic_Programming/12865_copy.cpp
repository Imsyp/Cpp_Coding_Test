#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct prod {
    int weight;
    int value;
};

int prodNum, maxWeight, cache[100][100000];
const int INF = -1000000;
vector<prod> prodList;

//i번째 물건까지 진행했을 때, maxWeight만큼 담을 수 있는 가방의 최대 value값 반환
int dp(int i, int maxWeight) { 
    //i번째 물건의 무게와 가치
    int nowWeight = prodList[i].weight;
    int nowVal = prodList[i].value;

    //base case: i가 prodList 범위를 넘어갈 때
    if(i < 0) {
        return 0;
    }

    //base case: maxWeight가 0일 때
    // if(maxWeight == 0) {
    //     return 0;
    // }
    
    //base case: maxWeight가 음수가 될 때
    if(maxWeight < 0) {
        return INF;
    }

    int &ret = cache[i][maxWeight];
    if(ret != -1) {
        return ret;
    }

    //i번째 물건을 넣지 않는 경우와, 넣는 경우 중 큰 값을 저장
    ret = max(dp(i - 1, maxWeight), nowVal + dp(i - 1, maxWeight - nowWeight));

    return ret;
}



int main(void) {
    memset(cache, -1, sizeof(cache));

    cin >> prodNum >> maxWeight;

    while(prodNum--) {
        //무게, 가치
        int prodWeight, prodVal;
        cin >> prodWeight >> prodVal;

        prod product;
        product.value = prodVal;
        product.weight = prodWeight;

        prodList.push_back(product);
    }

    cout << dp(prodNum - 1, maxWeight) << endl;

    return 0;
}

//가방에 물건을 넣을 때, 가치합을 최대치로 만들 수 있는 dp를 생각해보자.