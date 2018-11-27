#include <bits/stdc++.h>

int main() {
    int n, t, k = 0, score = 0;
    std::vector<int> me, you;
    scanf("%d", &n);
    
    for (int h = 0; h < n; h++) {
        scanf("%d", &t);
        me.push_back(t);
    }
    
    for (int h = 0; h < n; h++) {
        scanf("%d", &t);
        you.push_back(t);
    }
    
    sort(me.begin(), me.end());
    sort(you.begin(), you.end());
    
    for (int i = 0; i < n; i++) {
        for (int j = k; j < n; j++) {
            if (me[i] < you[j]) {
                score++;
                k = j + 1;
                break;
            }
            
            if (score >= (n+1)/2)
                goto Answer;
        }
    }
    
    Answer:
    if (score >= (n+1)/2)
        printf("YES");
    else
        printf("NO");
    
    return 0;
}