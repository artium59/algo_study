#include <bits/stdc++.h>

int cup[4] = {-1, 0, 0, 1};

void Shuffle(int a, int b) {
    int t;
    
    t = cup[a];
    cup[a] = cup[b];
    cup[b] = t;
}

int main() {
    std::string s;
    std::cin >> s;
    
    for (int i = 0; i < s.size(); i++) {
        switch(s[i] - 'A') {
            case 0:
                Shuffle(0, 1);
                break;
            case 1:
                Shuffle(0, 2);
                break;
            case 2:
                Shuffle(0, 3);
                break;
            case 3:
                Shuffle(1, 2);
                break;
            case 4:
                Shuffle(1, 3);
                break;
            case 5:
                Shuffle(2, 3);
                break;
        }
    }
    
    for (int j = 0; j < 4; j++)
        if (cup[j] == -1)
            printf("%d\n", j+1);
    
    for (int j = 0; j < 4; j++)
        if (cup[j] == 1)
            printf("%d", j+1);
    
    return 0;
}