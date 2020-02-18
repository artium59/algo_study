#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

const int MODULE = 256;
int tc, sm, sc, si, p, cnt, xx, pro, arr[100000], loc[4096];
char ch;
bool check, visited[4096];
string fuck, program;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> tc;
    while (tc--) {
        stack<int> stk;

        memset(loc, -1, sizeof(loc));
        memset(arr, 0, sizeof(arr));
        memset(visited, false, sizeof(visited));

        cin >> sm >> sc >> si >> fuck >> program;

        for (int i = 0; i < sc; ++i) {
            if (fuck[i] == '[') stk.push(i);
            else if (fuck[i] == ']') {
                loc[i] = stk.top();
                loc[stk.top()] = i;
                stk.pop();
            }
        }

        cnt = p = pro = 0; check = true;
        for (int i = 0; i < sc; ++i) {
            if (cnt >= 50000000) {
                check = false;
                break;
            }

            if (fuck[i] == '+')
                arr[p] = (arr[p] + 1) % MODULE;
            else if (fuck[i] == '-')
                arr[p] = (arr[p] - 1 + MODULE) % MODULE;
            else if (fuck[i] == '<')
                p = (p - 1 + sm) % sm;
            else if (fuck[i] == '>')
                p = (p + 1) % sm;
            else if (fuck[i] == '[') {
                if (arr[p] == 0) {
                    visited[i] = true;
                    visited[loc[i]] = true;
                    i = loc[i];
                }
                else {
                    if (!visited[i]) xx = i;
                }
            }
            else if (fuck[i] == ']') {
                if (arr[p] != 0) {
                    i = loc[i];
                    if (!visited[i]) xx = i;
                }
                else {
                    visited[i] = true;
                    visited[loc[i]] = true;
                }
            }
            else if (fuck[i] == ',') {
                if (pro < si)
                    arr[p] = program[pro] % MODULE;
                else if (pro >= si)
                    arr[p] = 255;
                ++pro;
            }

            ++cnt;
        }

        if (check) cout << "Terminates\n";
        else cout << "Loops " << xx << " " << loc[xx] << "\n";
    }
    return 0;
}
