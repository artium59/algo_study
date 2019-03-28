#include <iostream>

bool col[50], row[50];

void Init() {
    for (int i = 0; i < 50; i++) {
        row[i] = false;
        col[i] = false;
    }
}

int main() {
    int n, m, c = 0, r = 0;
    char ch;

Init();

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &ch);
            if (ch == 'X') {
                row[i] = true; col[j] = true;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (!row[i]) r++;
    }

    for (int i = 0; i < m; i++) {
        if (!col[i]) c++;
    }

    printf("%d", c > r ? c : r);

    return 0;
}
