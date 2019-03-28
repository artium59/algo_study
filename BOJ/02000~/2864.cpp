#include <bits/stdc++.h>

int main() {
    char a[8], b[8];
    int maximum, minimum;
    
    scanf("%s %s", a, b);
    
    for (int i = 0; i < strlen(a); i++)
        if (a[i] == '5') a[i] = '6';

    for (int i = 0; i < strlen(b); i++)
        if (b[i] == '5') b[i] = '6';

    maximum = atoi(a) + atoi(b);
    
    for (int i = 0; i < strlen(a); i++)
        if (a[i] == '6') a[i] = '5';

    for (int i = 0; i < strlen(b); i++)
        if (b[i] == '6') b[i] = '5';

    minimum = atoi(a) + atoi(b);
    
    printf("%d %d", minimum, maximum);
    
    return 0;
}