#include <iostream>

using namespace std;

int gcd(int a, int b) {
    int q = a/b;
    int r1 = a%b;
    int r2 = b%r1;
    
    if(a == 0) {
        return r1;
    }

    gcd(r1, r2);

    return 0;
}

int main(void) {
    int a, b;
    cin >> a >> b;

    cout << gcd(a, b) << endl;

    return 0;
}