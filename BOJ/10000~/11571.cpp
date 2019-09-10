#include <stdio.h>
#include <vector>

int t, up, down, check[1025];

int main() {
    scanf("%d", &t);
    while (t--) {
        std::vector<int> vec;
        
        for (int i = 0; i < 1025; i++) check[i] = -1;
        
        scanf("%d %d", &up, &down);
        printf("%d.", up/down); up %= down;
        
        for (int i = 0; check[up] == -1; i++) {
            check[up] = i;
            up *= 10;
            vec.push_back(up/down);
            up %= down;
        }
        
        for (int i = 0; i < check[up]; i++) printf("%d", vec[i]);
        printf("(");
        for (int i = check[up]; i < vec.size(); i++) printf("%d", vec[i]);
        printf(")\n");
    }

    return 0;
}
