#include <iostream>
#include <string>

using namespace std;

int main(void) {
    int n;


    while(cin >> n) {
        int answer = 1;
        int div = 1;
        int ten = 1;

        while(true) {
            if(div % n == 0) {
                break;
            }

            //모듈러 연산
            div = div * 10 + 1;
            answer++;

            div %= n;
        }
        cout << answer << endl;
    }

    return 0;
}