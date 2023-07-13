#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string str;
    int n;
    cin>>str>>n;

    if (n,str.length()>=1 && n<=5 && str.length()<=10)
    {
        for(int i=1; i<=n; i++)
        {
            cout<<str;
        }
    }
    else
        cout<<-1<<endl;

    return 0;
}