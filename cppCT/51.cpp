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

    cout<<"A�� �Է��Ͻÿ� :";
    cin>>A;
    cout<<"B�� �Է��Ͻÿ� :";
    cin>>B; 

    if(0<A,B<10)
        cout<<AddFunc(A,B)<<endl;
    else
        cout<<"A,B�� 1���� 9������ �����Դϴ�.";

    return 0;
}