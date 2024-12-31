#include <cstdio>
#include <string>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j < i; j++) {
            printf("%s", " ");
        }
        
        for(int j = 0; j <= (N - i) * 2; j++) {
            printf("%s", "*");
        }
        printf("\n");
    }
    
    for(int i = N - 1; i >= 1; i--) {
        for(int j = 1; j < i; j++) {
            printf("%s", " ");
        }
        
        for(int j = 0; j <= (N - i) * 2; j++) {
            printf("%s", "*");
        }
        printf("\n");
    }
    
    return 0;
}
