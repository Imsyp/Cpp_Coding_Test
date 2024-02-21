#include <iostream>

using namespace std;

int main(void) {
    int cardNum, goal, temp, cardSet[100000];
    temp = 0;

    cin >> cardNum >> goal;


    for(int i = 0; i < cardNum; i++) {
        cin >> cardSet[i];
    }

    for(int i = 0; i < cardNum - 2; i++) {
        for(int j = i + 1; j < cardNum - 1; j++) {
            for(int k = j + 1; k < cardNum; k++) {
                int sum = cardSet[i] + cardSet[j] + cardSet[k];
                if( temp < sum && sum <= goal) {
                    temp = sum;
                }
            }
        }
    } 

    cout << temp << endl;

    return 0;
}