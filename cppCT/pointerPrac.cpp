#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int N;
    int a;
    cin>>N;
    cout<<"int a;"<<endl;

    if(N==1)
        cout<<"int *ptr = &a;"<<endl;

    if(N==2)
    {
        cout<<"int *ptr = &a;"<<endl;
        cout<<"int **ptr2 = &ptr;"<<endl;
    }

    if(N>2 && N<=100)
    {
        cout<<"int *ptr = &a;"<<endl;
        cout<<"int **ptr2 = &ptr;"<<endl;        

        for(int i=3; i<=N; i++)
        {
            string str1 = "int ";
            cout<<str1.append(i,'*');
            cout<<"ptr"<<i<<" = &ptr"<<i-1<<";"<<endl;
        }
    }

    return 0;
}