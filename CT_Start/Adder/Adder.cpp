#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(int num1, int num2) 
{
    int answer ;
    answer = num1 + num2;
    return answer;
}

int main(void)
{
    int x,y;
    cin>>x>>y;
    cout<<solution(x,y)<<endl;
    return 0;
}

