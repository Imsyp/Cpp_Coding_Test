#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

struct product{
    int value;
    int weight;
};

vector<product> prodSet;
int cache[101][100001];
const int INF = -1000000;

//index번째 물건까지 진행했을 때, maxWeight의 물건을 담을 수 있는 backpack에서의 최대 value 반환
int dp(int index, int maxWeight) {
    //base case: maxWeight가 음수가 됐을 때
    if(maxWeight < 0) {
        return INF;
    }

    //base case: maxWeight가 0이 됐을 때
    if(maxWeight == 0) {
        return 0;
    }

    //base case: index가 끝에 도달했을 때
    if(index < 0) {
        return 0;
    }

    int &ret = cache[index][maxWeight];
    if(ret != -1) {
        return ret;
    }

    product prod = prodSet[index];
    return ret = max(dp(index - 1, maxWeight), prod.value + dp(index - 1, maxWeight - prod.weight));
}

int main(void) {
    for(int i = 0; i < 101; i++) {
        fill(cache[i], cache[i] + 100001, -1);
    }

    int prodNum, maxWeight;
    cin >> prodNum >> maxWeight;

    for(int i = 0; i < prodNum; i++) {
        int weight, value;
        product prod;

        cin >> weight >> value;
        prod.weight = weight;
        prod.value = value;

        prodSet.push_back(prod);
    }

    cout << dp(prodNum, maxWeight) << endl;

    return 0;
}