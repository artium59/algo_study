#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string str;
    vector<bool> detector;
    scanf("%d", &n);
    
    for (int h = 0; h < n; h++) {
        cin >> str;
        
        if (str == "LIE")
            detector.push_back(false);
        else
            detector.push_back(true);
    }
    
    for (int i = n-1; i > 0; i--) {
        if (!detector[i])
            detector[i-1] = !detector[i-1];
    }
    
    if (detector[0])
        printf("TRUTH");
    else
        printf("LIE");
    
    return 0;
}