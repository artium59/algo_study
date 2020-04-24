#include <iostream>
using namespace std;

int n, g, cnt, ans[60], arr[60];
string w, s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> g >> w >> s;

    for (int i = 0; i < n; i++) {
        if ('A' <= w[i] <= 'Z')
            ++ans[w[i]-'A'];
        else
            ++ans[w[i]-'a'+26];
    }

    for (int i = 0; i < n; i++) {
        if ('A' <= s[i] <= 'Z')
            ++arr[s[i]-'A'];
        else
            ++arr[s[i]-'a'+26];
    }
    for (int k = 0; k < 60; k++) {
        if (ans[k] != arr[k]) break;
        if (k == 59) ++cnt;
    }

    for (int i = n; i < g; i++) {
        if ('A' <= s[i-n] <= 'Z')
            --arr[s[i-n]-'A'];
        else
            --arr[s[i-n]-'a'+26];

        if ('A' <= s[i] <= 'Z')
            ++arr[s[i]-'A'];
        else
            ++arr[s[i]-'a'+26];

        for (int k = 0; k < 60; k++) {
            if (ans[k] != arr[k]) break;
            if (k == 59) ++cnt;
        }
    }

    cout << cnt;
    return 0;
}
