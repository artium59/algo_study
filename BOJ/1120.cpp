#include <bits/stdc++.h>

using namespace std;

int main() {
    string a, b;
    vector<int> count;
    cin >> a >> b;
    
    // if a.size() = 3, b.size() = 5 b-a = 2
    //    0 1 2
    //    0 1 2 3 4
          
    //    0 1 2
    //  0 1 2 3 4
        
    //    0 1 2
    //0 1 2 3 4
    
    for (int j = 0; j <= (b.size() - a.size()); j++) {
        int c = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i + j])
                c++;
        }
        printf("%d: %d\n", j, c);
        count.push_back(c);
    }
    
    sort(count.begin(), count.end());
    printf("%d", count[0]);
    
    return 0;
}