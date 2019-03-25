#include <iostream>

using namespace std;

bool swch = false;

bool isGood(string str) {
    int size = str.size();
  
    for (int i = 1; i <= size/2; i++) {
        string a = str.substr(size-i, i);
        string b = str.substr(size-2*i, i);
    
        if (a == b) return false;
    }
  
    return true;
}

void Search(string str, int n, int len) {
    if (len == n) {
        if (!swch) cout << str;
        swch = true; return;
    }
    string s;
  
    if (!swch) {
        for (int i = 1; i < 4; i++) {
            s = str;
            s += i+'0';
            if (isGood(s)) Search(s, n, len+1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  
    int n;
    string s;
  
    cin >> n;
  
    Search(s, n, 0);
  
    return 0;
}
