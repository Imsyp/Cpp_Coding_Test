#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(const string &str1, const string &str2) {
    if(str1 + str2 > str2 + str1) {
        return true;
    }
    return false;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> sorted;
    
    for(int i = 0; i < numbers.size(); i++) {
        sorted.push_back(to_string(numbers[i]));
    }
    
    sort(sorted.begin(), sorted.end(), cmp);
    
    for(int i = 0; i < sorted.size(); i++) {
        answer += sorted[i];
    }
    
    return answer;
}

// 풀이 보고 풀었음......