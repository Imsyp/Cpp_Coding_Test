#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) 
{
    int answer = 0;

    string sa = to_string(a);
    string sb = to_string(b);

    int ab = stoi(sa+sb);
    int ba = stoi(sb+sa);

    if(ab>ba)
        answer = ab;
    else 
        answer = ba;

    return answer;
}