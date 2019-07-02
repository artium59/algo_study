#include <iostream>
#include <string>
using namespace std;

int Reverse(string s) {
    char str[3];
    
    for (int i = 2; i > -1; --i)
        str[2-i] = s[i];
    
    return atoi(str);
}

int main() {
    string a, b;
    
    cin >> a >> b;
    
    if (Reverse(a) > Reverse(b))
        cout << Reverse(a);
    else
        cout << Reverse(b);
    
    return 0;
}
