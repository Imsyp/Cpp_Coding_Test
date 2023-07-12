#include <iostream>
using namespace std;

int AddFunc(int a,int b)
{
    return a+b;
}

int main(void)
{
    int A;
    int B;

    cout<<"A를 입력하시오 :";
    cin>>A;
    cout<<"B를 입력하시오 :";
    cin>>B; 

    if(0<A,B<10)
        cout<<AddFunc(A,B)<<endl;
    else
        cout<<"A,B는 1부터 9까지의 정수입니다.";

    return 0;
}