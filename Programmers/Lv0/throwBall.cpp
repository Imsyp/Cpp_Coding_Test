#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int k) {
    int answer = 0;
    int jump = 0;
    for(int i = 0; i < k - 1; i++) {
        jump += 2;
        if(jump > numbers.size() - 1) {
            jump -= numbers.size();
        }        
        answer = numbers[jump];
    }
    return answer;
}