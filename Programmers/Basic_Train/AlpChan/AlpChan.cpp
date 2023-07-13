#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

int main(void) 
{
    string str;
    cin >> str;

    for (int i=0; i<=(str.length()-1); i++)
    {
        if (isupper(str[i]))
            str[i] = tolower(str[i]);
        else if (islower(str[i]))
            str[i] = toupper(str[i]); 
        else
            cout<<-1<<endl;
    }
    cout<<str<<endl;
    
    return 0;
}