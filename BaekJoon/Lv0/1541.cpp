#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string str, char Delimiter) {
    istringstream iss(str);
    string buffer;

    vector<string> result;

    while(getline(iss, buffer, Delimiter)) {
        result.push_back(buffer);
    }

    return result;
}

int main(void) {
    string str;
    cin >> str;

    int sum = 0;

    vector<string> strings = split(str, '-');
    for(int i = 0; i < strings.size(); i++) {
        if(i == 0) {
            vector<string> numbers = split(strings[0], '+');
            for(int j = 0; j < numbers.size(); j++) {
                sum += stoi(numbers[j]);
            }
        }
        else {
            vector<string> numbers = split(strings[i], '+');
            for(int j = 0; j < numbers.size(); j++) {
                sum -= stoi(numbers[j]);
            }
        }
    }

    cout << sum << endl;

    return 0;
}