#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    int i = 0;
    while(true) {
        i++;

        vector<int> tmp = arr;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] >= 50 && arr[i] % 2 == 0) {
                arr[i] /= 2;
            }
            else if(arr[i] < 50 && arr[i] % 2 != 0) {
                arr[i] = (arr[i] * 2) + 1;
            }
        }

        if(tmp == arr) {
            break;
        }
    }
    return i - 1;
}