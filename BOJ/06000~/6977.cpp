#include <cstdio>

int tc, n, k;
bool visited[50];

void find(int idx, int one) {
    if (one <= 0) {
        for (int i = 0; i < n; i++)
            printf("%d", visited[i]);
        printf("\n");
        return;
    }

    for (int i = idx; i < n; i++) {
        visited[i] = true;
        find(i+1, one-1);
        visited[i] = false;
    }
}

int main() {
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d %d", &n, &k);
        printf("The bit patterns are\n");
        find(0, k);
        printf("\n");
    }
    return 0;
}
