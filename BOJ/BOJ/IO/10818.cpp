#include <cstdio>

using namespace std;

int main() {
    int cases, min, max, temp;
    scanf("%d", &cases);
    
    scanf("%d", &temp);
    min = temp;
    max = temp;
    cases--; 
    
    while(cases--) {
        scanf("%d", &temp);
        if(temp > max) {
            max = temp;
        } else if(temp < min) {
            min = temp;
        }
    }
    
    printf("%d %d", min, max);
    
    return 0;
}
