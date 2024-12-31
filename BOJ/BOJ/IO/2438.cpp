#include <cstdio>
#include <string>

using namespace std;

int main() {
    int N;
    string star = "*";
    scanf("%d", &N);
    
    for(int i = 0; i < N; i++) {
        string temp = star;
        printf("%s\n", temp.append(i, '*').c_str());
    }
    
    return 0;
}
