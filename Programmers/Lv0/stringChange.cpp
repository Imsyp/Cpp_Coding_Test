#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string overwrite_string, int s) 
{
    string answer = "";

    int length = overwrite_string.length();
    int sum;
    sum = length + s;
    int limit = my_string.length()-sum;

    for(int i=0; i<s; i++)
    {
        answer += my_string[i];
    }

    for(int i=0; i<length; i++)
    {
        answer += overwrite_string[i];
    }

    for(int i=0; i<limit; i++)
    {
        answer += my_string[sum];
        sum++;
    }

    return answer;
}

int main(void)
{
    cout<< solution("hahahahahahahahha", "youretoslow", 4);

    return 0;
}