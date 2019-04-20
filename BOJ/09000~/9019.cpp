#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int n, x, y, cur, a, b, c, d;
bool visited[10001];
string str;
pair<int, char> p[10001];
stack<char> stk;
queue<int> q;

void Init() {
    for (int i = 0; i < 10001; i++) {
        visited[i] = false;
        p[i].first = -1;
        p[i].second = ' ';
    }

    while (!q.empty()) {
        q.pop();
    }
}

int main() {
    scanf("%d", &n);
    while (n--) {
        Init();

        scanf("%d %d", &x, &y);
        q.push(x);

        while (!q.empty()) {
            cur = q.front();
            q.pop();

            if (cur == y) break;
            if (visited[cur]) continue;
            visited[cur] = true;

            a = (cur*2)%10000;
            b = cur == 0 ? 9999 : cur-1;
            c = (cur%1000)*10 + cur/1000;
            d = cur/10 + (cur%10)*1000;
			
            if (p[a].first == -1) {
                p[a].first = cur; p[a].second = 'D';
                q.push(a);
            }
            if (p[b].first == -1) {
                p[b].first = cur; p[b].second = 'S';
                q.push(b);
            }
            if (p[c].first == -1) {
                p[c].first = cur; p[c].second = 'L';
                q.push(c);
            }
            if (p[d].first == -1) {
                p[d].first = cur; p[d].second = 'R';
                q.push(d);
            }
        }

        while (cur != x) {
            stk.push(p[cur].second);
            cur = p[cur].first;
        }

        while (!stk.empty()) {
            printf("%c", stk.top());
            stk.pop();
        }
        printf("\n");
    }

    return 0;
}
