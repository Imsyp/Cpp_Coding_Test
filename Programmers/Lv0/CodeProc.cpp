#include <iostream>

#include <string>
#include <vector>

using namespace std;

string solution(string code) 
{
    int idx = 0;
    int mode = 0;
    string ret = "";
    for(idx; idx<code.size()-1; idx++)
    {
        if(code[idx] == '1')
            mode = 1;
        else if(code[idx] == '0')
            mode = 0;
        else
        {
            if(mode == 1)
            {
                if(idx%2 == 0)
                    ret.append(1, code[idx]);
            }
            else
            {
                if(idx%2 != 0)
                    ret.append(1, code[idx]);
            }
        }
    }

    if(ret.size() ==0)
        return "EMPTY";
    else
        return ret;
}

int main(void)
{
    cout<<solution("abc1abc1abc")<<endl;
    return 0;
}