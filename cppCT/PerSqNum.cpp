#include <iostream>
#include <math.h>
using namespace std;

int main(void)
{
    int M;
    int N;
    int sum = 0;
    cin>>M>>N;

    if(0<M<=N<=10000)
    {
        int i;
        i = M;
        while(i<=N)
        {
            if(sqrt(i)-int(i)==0)
            {
                sum+=i;
            }
            i++;
        } 
    }    
    else
        cout<<-1<<endl;

    cout<<sum<<endl;

    return 0;
}