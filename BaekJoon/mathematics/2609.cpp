#include <iostream>
#include <algorithm>

using namespace std;

//최대공약수 반환
int GCD(int num1, int num2) {
    int gcd = 1;

    for(int i = 1; i <= max(num1, num2); i++) {
        if(num1 % i == 0 && num2 % i == 0) {
            gcd = i;
        }
    }

    return gcd;
}

//최소공배수 반환
int LCM(int num1, int num2) {
    int lcm = num1 * num2;

    for(int i = 1; i <= num2; i++) {
        for(int j = 1; j <= num1; j++) {
            if(num1 * i == num2 * j) {
                lcm = min(lcm, num1 * i);
            }
        }
    }

    return lcm;
}

int main(void) {
    int num1, num2;
    cin >> num1 >> num2;

    cout << GCD(num1, num2) << endl;
    cout << LCM(num1, num2) << endl;

    return 0;
}