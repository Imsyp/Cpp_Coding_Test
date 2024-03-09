#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> prodList;

//prodList를 받아, 배낭에 넣을 수 있는 물건들의 가치합 maximum을 반환
int backpack(vector<vector<int>> prodList) {

}

int main(void) {
    int prodNum, maxWeight;
    cin >> prodNum >> maxWeight;

    while(prodNum--) {
        //무게, 가치
        int prodWeight, prodVal;
        cin >> prodWeight >> prodVal;

        //index 0 -> wegiht, index 1 -> value
        vector<int> prod;
        prod.push_back(prodWeight);
        prod.push_back(prodVal);
        
        //물건 목록
        prodList.push_back(prod);
    }

    cout << backpack(prodList) << endl;

    return 0;
}

//가방에 물건을 넣을 때, 가치합을 최대치로 만들 수 있는 dp를 생각해보자.