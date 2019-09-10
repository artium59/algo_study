#include <stdio.h>
#include <vector>

int k;
bool p[7368788];
std::vector<int> prime(1, 2);

int main() {
    for (int i = 3; i*i < 7368788; i+=2) {
        if (p[i]) continue;
        
        for (int j = i+i; j < 7368788; j+=i) p[j] = true;
    }
    
    for (int i = 3; i < 7368788; i+=2) {
        if (!p[i]) prime.push_back(i);
    }
    
    scanf("%d", &k);
    printf("%d", prime[k-1]);

    return 0;
}
