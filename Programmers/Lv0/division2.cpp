#include <numeric>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int numer1, int denom1, int numer2, int denom2) 
{
    vector<int> answer;

    int numer3 = numer1 * denom2 + numer2 * denom1;
    int denom3 = denom1 * denom2;

    int GCD = gcd(numer3, denom3); 

    numer3 = numer3/GCD;
    denom3 = denom3/GCD;

    answer.push_back(numer3);
    answer.push_back(denom3);

    return answer;
}