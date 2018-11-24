#include <bits/stdc++.h>

using namespace std;

int main() {
    int x, y, z;
    string a, b, c, color[10] = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white"};
    
    cin >> a >> b >> c;
    
    for (int i = 0; i < 10; i++) {
        if (a == color[i]) x = i;
        if (b == color[i]) y = i;
        if (c == color[i]) z = i;
    }

    cout << (10 * x + y);
    
    if (10 * x + y != 0) {
        for (int j = 0; j < z; j++)
            cout << 0;
    }
    
    return 0;
}