#include <iostream>
#include <cstdio>

struct NODE {
    char value; 
    int left = -1, right = -1;
};

struct NODE alphabet[26];

void PreOrder(int a) {
    printf("%c", alphabet[a].value);
    if (alphabet[a].left != -1) PreOrder(alphabet[a].left);
    if (alphabet[a].right != -1) PreOrder(alphabet[a].right);
}

void InOrder(int a) {
    if (alphabet[a].left != -1) InOrder(alphabet[a].left);
    printf("%c", alphabet[a].value);
    if (alphabet[a].right != -1) InOrder(alphabet[a].right);
}

void PostOrder(int a) {
    if (alphabet[a].left != -1) PostOrder(alphabet[a].left);
    if (alphabet[a].right != -1) PostOrder(alphabet[a].right);
    printf("%c", alphabet[a].value);
}

int main() {
    int n;
    char x, y, z;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> x >> y >> z;

        alphabet[x-'A'].value = x;
        if (y != '.') alphabet[x-'A'].left = y-'A';
        if (z != '.') alphabet[x-'A'].right = z-'A';
    }

    PreOrder(0); printf("\n");
    InOrder(0); printf("\n");
    PostOrder(0);

    return 0;
}
