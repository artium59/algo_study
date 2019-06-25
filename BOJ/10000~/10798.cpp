#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string str[5];
    
    for (int i = 0; i < 5; i++) cin >> str[i];
    
    for (int j = 0; j < 15; j++) {
        for (int i = 0; i < 5; i++) {
            if (j < str[i].size()) cout << str[i][j];
        }
    }
    
    return 0;
}
