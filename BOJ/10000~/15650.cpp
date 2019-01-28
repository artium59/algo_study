#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, m;
    vector<string> arr;
    
    cin >> n >> m;
    
    for (int i = 1<<m - 1; i < 1<<n; i++) {
        if (__builtin_popcount(i) == m) {
            int t = i, count = 1;
            string str;
            while (t > 0) {
                if (t % 2 == 1) {
                    str += count + '0'; str += " ";
                }
                count++; t /= 2;
            }
            
            arr.push_back(str);
        }
    }
    
    sort(arr.begin(), arr.end());
    
    for (const auto& a : arr)
        cout << a << "\n";
    
    return 0;
}
