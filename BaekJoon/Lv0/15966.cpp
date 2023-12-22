#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main(void) {
    int N;
    cin >> N;
    
    vector<int> seq;
    while(N--) {
        int term;
        cin >> term;

        seq.push_back(term);
    }

    int result = 1;
    int curPerm = seq[0];
    for(int i = 1; i < seq.size(); i++) {
        if(seq[i] == curPerm + 1) {
            result++;
            curPerm = seq[i];
        }
    }

    cout << result << endl;
}