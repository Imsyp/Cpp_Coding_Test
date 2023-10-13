#include <iostream>

#include <string>
#include <vector>

using namespace std;

int solution(int n) 
{
    int pizza = 6;
    int i =1;

    while(true)
    {
        pizza *= i;

        if(pizza%n ==0) break;

        i++;
    }

    return i;
}

int main(void)
{
    cout << solution(0) <<endl;

    return 0;
}