#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

int main(void)
{
    int i;
    vector<int> numStr;
    vector<string> operStr;

    vector<string> formula;

    const char my_string[] = "1 + 2";
    char Space[] = " ";

    string str(my_string);

    for(i=0; i<str.length()-1; i++)
    {
        if(str[i] != Space[0])
            formula.push_back(str[i]);
    }




    return 0;
}