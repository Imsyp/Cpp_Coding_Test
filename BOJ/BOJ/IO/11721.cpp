#include <iostream>
#include <string>

using namespace std;

int main() {
    int index = 0;
    string str;
    cin >> str;
    while(index != str.size()) {
        for(int i = 0; i < 10; i++) {
            if(index == str.size()) {
                break;
            }
            cout << str[index++];
        }
        cout << endl;
    }
    return 0;
}
