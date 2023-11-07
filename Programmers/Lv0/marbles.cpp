#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int balls, int share) {
    long double answer = 0;
    long double bFac = 1;
    long double sFac = 1;
    long double bsFac = 1;

    for(int i = 1; i <= balls; i++) {
        bFac *= i; 
    }

    for(int i = 1; i <= share; i++) {
        sFac *= i; 
    }

    for(int i = 1; i <= balls - share; i++) {
        bsFac *= i;
    }

    answer = bFac / (sFac * bsFac);

    return answer;
}