#include <cstdio>
#include <vector>

const int xrr[4] = {1,-1,0,0}, yrr[4] = {0,0,1,-1};
int n, m, a, b, x, y, ans;
std::vector<std::pair<int, int>> vec, graph[100][100];
bool light[100][100], visited[100][100];

void turn_on() {
    for (const auto& v : vec) {
        y = v.first; x = v.second;
        for (const auto& g : graph[y][x]) {
            if (!light[g.first][g.second]) m++;
            light[g.first][g.second] = true;
        }
    }
}

void BFS() {
    for (int k = 0; k < vec.size(); k++) {
        y = vec[k].first; x = vec[k].second;
        
        for (int i = 0; i < 4; i++) {
            b = y+yrr[i]; a = x+xrr[i];
            
            if (0<=b&&b<n && 0<=a&&a<n && !visited[b][a] && light[b][a]) {
                visited[b][a] = true;
                vec.push_back(std::make_pair(b, a));
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    while (m--) {
        scanf("%d %d %d %d", &b, &a, &y, &x);
        graph[b-1][a-1].push_back(std::make_pair(y-1, x-1));
    }
    
    ans = m = light[0][0] = visited[0][0] = 1;
    vec.push_back(std::make_pair(0, 0));
    
    while (true) {
        turn_on();
        if (ans == m) break;
        BFS();
        ans = m;
    }
    printf("%d", ans);

    return 0;
}
