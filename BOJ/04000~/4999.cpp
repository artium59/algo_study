#include <iostream>
using namespace std;

int main(void) {
    string s1, s2, str;

    cin >> s1 >> s2;
    str = s1.size() >= s2.size() ? "go" : "no";
    
    cout << str;

    return 0;
}
