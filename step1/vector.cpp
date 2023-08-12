#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main(void)
{
    string str = "yayaeye";

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





    cout<<(str=="    ")<<endl;



    return 0;
}