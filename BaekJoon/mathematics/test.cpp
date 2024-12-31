#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

void print(vector<int> v) {
    for(int i = 0; i < v.size(); i++) {
        if(i == v.size() - 1) {
            cout << v[i] << endl;
            break;
        }
        cout << v[i] << ",";
    }
}

vector<int> Reverse(vector<int> v) {
    vector<int> reversedV;
    
    for(int i = v.size() - 1; i >= 0; i--){
        reversedV.push_back(v[i]);
    }
    
    return reversedV;
}

int main(void) {
    vector<int> v1(5);
    
    srand(static_cast<unsigned>(time(0)));
    for(int i = 0; i < v1.size(); i++) {
        v1.push_back(rand() % 100);
    }
    
    vector<int> v2 = Reverse(v1);
    
    print(v1);
    print(v2);
    
    return 0;
}
