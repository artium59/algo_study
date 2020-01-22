#include <cstdio>
#include <algorithm>
#include <tuple>
#include <vector>
using namespace std;

const int MAX=30001;
int n, x1, y1, x2, y2, prev_x, ans, tree[65536], line[65536];
vector<tuple<int, int, int, int>> vec;

void update(int node, int start, int end, int left, int right, int num) {
    if (right < start || end < left) return;

    if (left <= start && end <= right)
        tree[node] += num;
    else {
        update(node*2, start, (start+end)/2, left, right, num);
        update(node*2+1, (start+end)/2+1, end, left, right, num);
    }

    if (tree[node] > 0)
        line[node] = end-start+1;
    else {
        if (start >= end) line[node] = 0;
        else line[node] = line[node*2]+line[node*2+1];
    }
}

int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        vec.push_back({ x1, y1+1, y2, 1 });
        vec.push_back({ x2, y1+1, y2, -1 });
    }
    sort(vec.begin(), vec.end());

    prev_x = get<0>(vec[0]);
    for (const auto& v : vec) {
        ans += (get<0>(v) - prev_x) * line[1];
        update(1, 0, MAX-1, get<1>(v), get<2>(v), get<3>(v));
        prev_x = get<0>(v);
    }
    printf("%d", ans);

    return 0;
}
