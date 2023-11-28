#include <iostream>
#include <cmath>

using namespace std;

int gcd()

int main(void) {
    int cases;
    cin >> cases;

    while(cases--) {
        int people, candy;
        cin >> people >> candy;

        int total = 1;

        while(true) {
            total *= candy;

            if(gcd) {
                cout << total/candy << endl;
                break;
            }

            if(total > pow(10, 9)) {
                cout << "IMPOSSIBLE" << endl;
                break;
            }
        }

        
    }
}