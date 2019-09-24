#include <iostream>
#include <algorithm>

int l, c;
char arr[15];

bool check(std::string& str) {
    int consonant = 0, vowel = 0;
    
    for (const auto& s : str) {
        if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u')
            vowel++;
        else consonant++;
    }
    
    return consonant > 1 && vowel > 0;
}

void make(std::string str, int loc, int count) {
    if (count == l && check(str)) {
        printf("%s\n", str.c_str());
        return;
    }
    
    if (loc >= c) return;
    
    make(str+arr[loc], loc+1, count+1);
    make(str, loc+1, count);
}

int main() {
    std::string extra = "";
    
    scanf("%d %d", &l, &c);
    for (int i = 0; i < c; i++) scanf(" %c", arr+i);
    std::sort(arr, arr+c);
    
    make(extra+arr[0], 1, 1);
    make(extra, 1, 0);

    return 0;
}
