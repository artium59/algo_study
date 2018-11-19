#include <bits/stdc++.h>

int main() {
    int n, l, sum = 0;
    bool isAnswer;
    std::vector<int> arr;
    scanf("%d %d", &n, &l);
    
    while (true) {
        if (l > 100) {
            isAnswer = false;
            break;
        }
        
        for (int a = 0; a < l/2+1; a++) {
            if (a != 0)
                arr.push_back(n/l-a);
            arr.push_back(n/l+a);
        }
        
        sort(arr.begin(), arr.end());
        
        if (l % 2 ==0)
            arr.erase(arr.begin());
            
        //°Ë»ê
        for (int b = 0; b < l; b++)
            sum += arr[b];
            
        if (sum != n) {
            l++;
            sum = 0;
            arr.clear();
        }
        else {
            if (arr[0] < 0)
                isAnswer = false;
            else
                isAnswer = true;
            
            break;
        }
    }
    
    if (!isAnswer)
        printf("-1");
    else
        for (int c = 0; c < l; c++)
            printf("%d ", arr[c]);

    return 0;
}