#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) 
{
    int answer =0;
    if(n % 2 ==0)
    {
        for(int i=1; i<n+1; i++)
        if(i % 2 ==0)
            answer += pow(i, 2);
    }
    else
    {
        for(int j=1; j<n+1; j++)
        {
            if(j % 2 != 0)
                answer += j;
        }
    }

    return answer;
}