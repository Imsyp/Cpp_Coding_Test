#include <iostream>
#include <string>

using namespace std;

int main() {
    int N, sum;
    string str;
    sum = 0;
    cin >> N;
    cin >> str;
    for(int i = 0; i < N; i++) {
        sum += str[i] - 48;
    }
    cout << sum << endl;
    return 0;
}
