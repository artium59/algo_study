#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool isChosen[10];
vector<string> cards, ans;

void Find(int n, int k, int cnt, string s) {
    if (k == cnt) {
        ans.push_back(s); return;
    }
    
    for (int i = 0; i < n; i++) {
        string str = s;
        
        if (!isChosen[i]) {
            str += cards[i];
            isChosen[i] = true;
            Find(n, k, cnt+1, str);
            isChosen[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    string str, s;
    
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> str;
        cards.push_back(str);
    }
    
    fill(isChosen, isChosen+10, false);
    Find(n, k, 0, s);
    
    sort(ans.begin(), ans.end());
    cout << unique(ans.begin(), ans.end()) - ans.begin();
    
    return 0;
}
