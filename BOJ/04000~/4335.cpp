#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    bool check[11];
    string a, b;

    while (true) {
        for (int i = 1; i < 11; i++) check[i] = true;
        
        while (true) {
            cin >> n >> a >> b;
            if (n == 0) break;
            
            if (b == "high") {
                for (int i = n; i < 11; i++) check[i] = false;
            }
            else if (b == "low") {
                for (int i = n; i > 0; i--) check[i] = false;
            }
            else break;
        }
        if (n == 0) break;
        
        if (check[n]) cout << "Stan may be honest\n";
        else cout << "Stan is dishonest\n";
    }

    return 0;
}
