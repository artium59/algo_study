#include <iostream>
#include <vector>

int main() {
    int n, k, l = 0, r = 1;
    char ch;
    std::vector<char> arr;

    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf(" %c", &ch);
        arr.push_back(ch);
    }

    while (r < n && k > 0) {
        if (arr[l] < arr[r]) {
            arr[l] = ' ';
            k--;

            while (arr[l] == ' ' && l >= 0) { l--; }
            
            if (l < 0) { l = r; r++; }
        }
        else {
            l = r; r++;
        }
    }

    for (int i = 0; i < n-k; i++) {
        if (arr[i] != ' ') printf("%c", arr[i]);
    }

    return 0;
}
