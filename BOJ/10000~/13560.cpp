#define MAX 10010

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, sum = 0;
    vector<int> scores;
    cin >> n;
    
    for (int a = 0; a < n; ++a) {
        int temp;
        cin >> temp;
        scores.push_back(temp);
    }
    
    sort(scores.begin(), scores.end());
    
    for (int b = 0; b < n; ++b) {
        sum += scores[b];
        
        if (sum < (b * (b + 1) / 2)) {
            cout << "-1";
            return 0;
        }
    }
    
    if (sum != (n * (n - 1) / 2))
        cout << "-1";
    else
        cout << "1";
    
    return 0;
}