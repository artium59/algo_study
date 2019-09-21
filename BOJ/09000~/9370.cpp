#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int tc, n, m, t, s, g, h, a, b, d, x;
int dist[2001];
bool check[2001];
std::priority_queue<int> ans;

int main() {
	scanf("%d", &tc);
	while (tc--) {
		priority_queue<pair<int, int>> pq;
		vector<pair<int, int>> graph[2001];

		fill(dist, dist + 2001, 987654321);
		memset(check, false, sizeof(check));

		scanf("%d %d %d %d %d %d", &n, &m, &t, &s, &g, &h);
		while (m--) {
			scanf("%d %d %d", &a, &b, &d);
			graph[a].push_back({ b, d });
			graph[b].push_back({ a, d });
		}

		dist[s] = 0;
		pq.push({ 0, s });
		while (!pq.empty()) {
			m = -pq.top().first;
			s = pq.top().second;
			pq.pop();

			for (const auto& gh : graph[s]) {
				if (dist[gh.first] > m + gh.second) {
					pq.push({ -(m + gh.second), gh.first });
					dist[gh.first] = m + gh.second;

					check[gh.first] = check[s];
					if (gh.first == g && s == h) check[gh.first] = true;
					if (gh.first == h && s == g) check[gh.first] = true;
				}
				else if (dist[gh.first] == m + gh.second) {
					if (gh.first == g && s == h) check[gh.first] = true;
					if (gh.first == h && s == g) check[gh.first] = true;
					if (!check[gh.first]) check[gh.first] = check[s];
				}
			}
		}

		while (t--) {
			scanf("%d", &x);
			if (check[x]) ans.push(-x);
		}

		while (!ans.empty()) {
			printf("%d", -ans.top()); ans.pop();
			printf(!ans.empty() ? " " : "\n");
		}
	}

	return 0;
}
