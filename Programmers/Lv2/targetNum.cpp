#include <iostream>
#include <string>
#include <vector>

using namespace std;

int answer = 0;

//base case: 배열의 끝에 도달 -> target과 total 비교하고 answer++
void targetNum(vector<int> numbers, int target, int i, int total, int sign) {
    if (sign == 0) {
        total -= numbers[i];
    }
    else {
        total += numbers[i];
    }

    i++;

    //base case
    if (i == numbers.size()) {
        if (total == target) {
            answer++;
        }
        return ;
    }

    targetNum(numbers, target, i, total, 0);
    targetNum(numbers, target, i, total, 1);

    return ;
}

int solution(vector<int> numbers, int target) {
    targetNum(numbers, target, 0, 0, 0);
    targetNum(numbers, target, 0, 0, 1);
    return answer;
}

int main(void) {
    vector<int> numbers(5, 1);
    int target = 3;

    solution(numbers, target);

    return 0;
}