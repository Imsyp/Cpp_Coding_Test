#include <string>
#include <vector>

using namespace std;

int solution(int balls, int share) {
    int answer = 0;
    int bFac = 1;
    int sFac = 1;
    int bsFac = 1;

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