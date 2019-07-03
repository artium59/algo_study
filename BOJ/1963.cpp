#include <iostream>
#include <queue>
using namespace std;

int t, ans;
bool prime[10000], visited[10000];
string a, b, cur;

void Init() {
    for (int i = 1000; i < 10000; i++)
        visited[i] = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    for (int i = 3; i*i < 10000; i+=2) {
        if (prime[i]) continue;
        
        for (int j = i+i; j < 10000; j+=i) prime[j] = true;
    }
    
    cin >> t;
    while (t--) {
        queue<pair<string, int>> q;
        
        cin >> a >> b;
        q.push(make_pair(a, 0));
        Init();
        
        while (!q.empty()) {
            a = q.front().first;
            ans = q.front().second;
            q.pop();
            
            if (a == b) break;
            if (visited[atoi(a.c_str())]) continue;
            visited[atoi(a.c_str())] = true;
            
            for (int i = 0; i < 4; i++) {
                cur = a;
                
                if (i == 0) {
                    for (int j = 1; j < 10; j++) {
                        cur[i] = j+'0';
                        
                        if (!prime[atoi(cur.c_str())] && !visited[atoi(cur.c_str())])
                            q.push(make_pair(cur, ans+1));
                    }
                }
                else if (i == 3) {
                    for (int j = 1; j < 10; j+=2) {
                        cur[i] = j+'0';
                        
                        if (!prime[atoi(cur.c_str())] && !visited[atoi(cur.c_str())])
                            q.push(make_pair(cur, ans+1));
                    }
                }
                else {
                    for (int j = 0; j < 10; j++) {
                        cur[i] = j+'0';
                        
                        if (!prime[atoi(cur.c_str())] && !visited[atoi(cur.c_str())])
                            q.push(make_pair(cur, ans+1));
                    }
                }
            }
        }
        
        if (a != b) cout << "Impossible\n";
        else cout << ans << "\n";
    }

    return 0;
}
