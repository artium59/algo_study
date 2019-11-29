#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

const int xrr[]={-1,0,1,0}, yrr[]={0,-1,0,1};
int tc, h, w;
string room[100], keys;
bool visited[100][100], key[26];
vector<pair<int, int>> door[26];
queue<std::pair<int, int>> q;

inline void init() {
    memset(visited, false, sizeof(visited));
    memset(key, false, sizeof(key));
    for (int i = 0; i < 26; ++i) door[i].clear();
    while (!q.empty()) q.pop();
}

inline void check(int b, int a) {
    if (room[b][a] != '*') visited[b][a] = true, q.push({ b, a });
    if ('a' <= room[b][a] && room[b][a] <= 'z') key[room[b][a]-'a'] = true;
}

int bfs() {
    int x, y, nx, ny, a, b, ret=0;

    while (!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();

        if ('A' <= room[y][x] && room[y][x] <= 'Z') {
            if (!key[room[y][x]-'A']) continue;
        }
        else if ('a' <= room[y][x] && room[y][x] <= 'z') {
            for (const auto& d : door[room[y][x]-'a']) {
                b = d.first; a = d.second;
                if (!visited[b][a]) continue;
                q.push({ b, a });
            }

            key[room[y][x]-'a'] = true;
        }
        else if (room[y][x] == '$') ++ret;

        for (int i = 0; i < 4; ++i) {
            ny = y + yrr[i]; nx = x + xrr[i];

            if (ny<0||ny>=h||nx<0||nx>=w || room[ny][nx]=='*' || visited[ny][nx]) continue;
            visited[ny][nx] = true;
            q.push({ ny, nx });
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> tc;
    while (tc--) {
        init();

        cin >> h >> w;
        for (int i = 0; i < h; ++i) {
            cin >> room[i];

            for (int j = 0; j < w; ++j) {
                if ('A'<= room[i][j] && room[i][j] <= 'Z')
                    door[room[i][j]-'A'].push_back({ i, j });
            }
            for (int j = 0; (i == 0 || i == h-1) && j < w; ++j) check(i, j);

            if (i == 0 || i == h-1) continue;

            check(i, 0);
            check(i, w-1);
        }
        cin >> keys;
        if (keys != "0") {
            for (const auto& k : keys) key[k-'a'] = true;
        }

        cout << bfs() << '\n';
    }

    return 0;
}
