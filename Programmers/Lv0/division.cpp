#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

int solution(int num1, int num2) 
{
    double answer ;
    double thous = 1000;
    double a, b;

    answer = (num1/(double)num2)*thous;
    a= modf(answer, &b);

    answer = b;
    (int) answer;
    return answer;
}

int main(void)
{
    cout<<solution(3,2)<<endl;

    return 0;
}