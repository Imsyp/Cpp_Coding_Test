#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) 
{
    vector<int> answer;

    for(int i=0; i<numbers.size(); i++)
    {
        numbers[i] *= 2;
    }

    answer = numbers;

    return answer;
}