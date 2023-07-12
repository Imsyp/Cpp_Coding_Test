#include <iostream>
using namespace std;

int main(void)
{
    int M,N;
    int numArr[10000];
    int sum = 0;
    int Min = 10000;
    cin>>M>>N;

    for(int i=1; i<=N; i++)
    {
        numArr[i]=i*i;
    }

    for(int i=1; i<=N; i++)
    {
        if(M <= numArr[i] && numArr[i] <= N)
        {
            sum += numArr[i];
            Min = min(Min, numArr[i]);
        }
    }

    if(sum ==0)
        cout<<-1<<endl;
    else
    {

        cout<<sum<<endl;
        cout<<Min<<endl;
    }

    return 0;
}