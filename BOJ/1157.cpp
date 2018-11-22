#include <bits/stdc++.h>

using namespace std;

int main() {
    int num;
    string str;
    vector<int> alphabet(26, 0), ans(26, 0);
    
    cin >> str;
    
    for (int h = 0; h < str.size(); h++) {
        num = (str[h] > 96) ? (str[h] - 'a') % 26 : (str[h] - 'A') % 26;
        alphabet[num]++;
        ans[num]++;
    }
    
    sort(ans.begin(), ans.end());
    
    if (ans[25] == ans[24])
        printf("?");
    else {
        for (int i = 0; i < 26; i++) {
            if (ans[25] == alphabet[i]) {
                printf("%c", i + 'A');
                break;
            }
        }
    }
    
    return 0;
}