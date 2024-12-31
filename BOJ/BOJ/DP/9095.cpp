#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int DP[12];

int recurv(int n) {
    int &ret = DP[n];
    if(ret != -1) {
        return ret;
    }
    
    return ret = recurv(n - 1) + recurv(n - 2) + recurv(n - 3);
}

int main() {
    memset(DP, -1, sizeof(DP));
    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 4;
    DP[4] = 7;
    
    int cases, n;
    cin >> cases;
    while(cases--) {
        cin >> n;
        cout << recurv(n) << endl;
    }
    
    
    return 0;
}
