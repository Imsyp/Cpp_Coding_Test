#include <cstdio>
#include <string>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    
    for(int i = 0; i < N - 1; i++) {
        for(int j = 0; j < N - i - 1; j++) {
            printf("%s", " ");
        }
        
        for(int j = 1; j <= 1 + (i * 2); j++) {
            printf("%s", (j == 1 || j == 1 + (i * 2)) ? "*" : " ");
        }
        
        printf("\n");
    }
    
    for(int i = 0; i < (N * 2) - 1; i++) {
        printf("%s", "*");
    }
    
    return 0;
}
