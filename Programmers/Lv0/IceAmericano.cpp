#include <string>
#include <vector>

using namespace std;

vector<int> solution(int money) {
    vector<int> answer(2, 0);

    int americano = money / 5500;
    int remain = money % 5500;

    answer[0] = americano;
    answer[1] = remain;

    return answer;
}