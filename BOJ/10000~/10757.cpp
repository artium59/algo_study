#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int x, y, z = 0;
    string a, b, c;
    
    cin >> a >> b;
    
    while (!a.empty() && !b.empty()) {
        x = a.back() - '0';
        y = b.back() - '0';
        
        c += (x + y + z)%10 + '0';
        z = (x + y + z)/10;
        
        a.pop_back();
        b.pop_back();
    }
    
    while (!a.empty()) {
        z += a.back() - '0';
        c += z%10 + '0';
        z /= 10;
        
        a.pop_back();
    }
    
    while (!b.empty()) {
        z += b.back() - '0';
        c += z%10 + '0';
        z /= 10;
        
        b.pop_back();
    }
    
    if (z > 0) cout << z;
    while (!c.empty()) {
        cout << c.back();
        c.pop_back();
    }
    
    return 0;
}
