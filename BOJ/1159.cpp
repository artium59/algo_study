#include <bits/stdc++.h>

int main() {
    int n, zero = 0, alphabet[26];
    std::string s;
    scanf("%d", &n);
    
    for (int h = 0; h < 26; h++)
        alphabet[h] = 0;
    
    for (int i = 0; i < n; i++) {
        std::cin >> s;
        alphabet[s[0]- 'a']++;
    }
    
    for (int j = 0; j < 26; j++) {
        if (alphabet[j] > 4)
            std::cout << (char)(j + 'a');
        else
            zero++;
    }
    
    if (zero > 25)
        std::cout << "PREDAJA";
}