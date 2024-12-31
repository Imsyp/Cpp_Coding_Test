#include <cstdio>
#include <string>

using namespace std;

int main() {
    int N;
    string star = "*";
    string blank = "";
    scanf("%d", &N);
    
    for(int i = 0; i < N; i++) {
        string tempStar = star;
        string tempBlank = blank;
        printf("%s%s\n", tempBlank.append(N - i - 1, ' ').c_str(),tempStar.append(i * 2, '*').c_str());
    }
    
    return 0;
}
