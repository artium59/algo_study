#include <iostream>

const char vowels[10] = {'A','E','I','O','U','a','e','i','o','u'};

int main() {
    int s, a, b;
    bool swch;
    char str[1001];
    scanf("%d%c", &s);

    for (int h = 0; h < s; h++) {
        a = 0; b = 0;
        for (int i = 0; i < 1001; i++) {
            scanf("%c", &str[i]);
            if (str[i] == '\n') break;
        }

        for (const auto& s : str) {
            swch = true;
            if (s == '\n') break;
            if (s == ' ') continue;

            for (const auto& v : vowels) {
                if (v == s) {
                    swch = false; b++; break;
                }
            }

            if (swch) a++;
        }

        printf("%d %d\n", a, b);
    }

    return 0;
}
