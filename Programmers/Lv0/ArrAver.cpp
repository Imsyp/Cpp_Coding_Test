#include <string>
#include <vector>
#include <numeric>

using namespace std;

double solution(vector<int> numbers) {
    double sum = accumulate(numbers.begin(), numbers.end(), double(0));
    double average = sum / double(numbers.size());
    return average;
}