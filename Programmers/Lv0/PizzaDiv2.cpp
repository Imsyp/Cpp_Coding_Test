#include <iostream>

#include <string>
#include <vector>

using namespace std;

int solution(int n) 
{
    int pizza;
    int i =1;

    while(true)
    {
        pizza = 6 * i;

        if(pizza%n == 0 && i*6 >= n) break;

        i++;
    }

    return i;
}

int main(void)
{
    cout << solution(100) <<endl;

    return 0;
}