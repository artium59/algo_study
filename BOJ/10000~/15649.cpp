#include <iostream>
#include <cstring>

using namespace std;

int n, m;
bool isChosen[8];

void Select(int t, string str) {
    if (t == m) {
        cout << str << "\n";
        return;
    }
	
    for (int i = 0; i < n; i++) {
        string s = str;
	
        if (!isChosen[i]) {
            isChosen[i] = true;
            s += i+1+'0';
            if (t != m-1) s += " ";
            Select(t+1, s);
            isChosen[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    string s;
	
    memset(isChosen, false, sizeof(isChosen));
	
    cin >> n >> m;
	
    Select(0, s);
	
    return 0;
}
