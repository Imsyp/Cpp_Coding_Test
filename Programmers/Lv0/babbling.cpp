#include <iostream>

#include <string>
#include <vector>

using namespace std;

int BabDel(string str)
{
    while(1)
    {
        if (str.find("aya") != str.npos)
        {
            str.replace(str.find("aya"), 3, " ");
        }

        if (str.find("ye") != str.npos)
        {
            str.replace(str.find("ye"), 2, " ");
        }

        if (str.find("woo") != str.npos)
        {
            str.replace(str.find("woo"), 3, " ");
        }

        if (str.find("ma") != str.npos)
        {
            str.replace(str.find("ma"), 2, " ");
        }

        if(str.find("aya") == str.npos && str.find("ye") == str.npos && str.find("woo") == str.npos & str.find("ma") == str.npos)
            break;
    }

    if(str == " " || str == "  " || str == "   " || str == "    ")
        return 1;
    else
        return 0;
}

int solution(vector<string> babbling) 
{
    int answer = 0;
    
    for(int i=0; i<babbling.size(); i++)
        answer += BabDel(babbling[i]);

    return answer;
}