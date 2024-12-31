#include <iostream>
#include <string>

using namespace std;

int main() {
    int cases, a, b;
    int count = 1;
    string str;
    cin >> cases;
    while(cases--){
        cin >> a >> b;
        cout << "Case #" << count++ << ": " << a << " + " << b << " = " << a + b << endl;
    }
    
    return 0;
}
