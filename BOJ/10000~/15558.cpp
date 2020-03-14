#include <cstdio>
#include <queue>
using namespace std;

struct Coo {
    int y, block;
    Coo(int a, int b) : y(a), block(b) {}
};

int n, k, s, y, block;
bool check, line[2][200002];
char ch;
queue<Coo> q;

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf(" %c", &ch);
            line[i][j] = ch == '0';
        }
    }

    q.push(Coo(0, 0));
    for (int t = 0; !q.empty(); ++t) {
        s = q.size();

        for (int a = 0; a < s; ++a) {
            y = q.front().y;
            block = q.front().block;
            q.pop();

            if (block > n) {
                check = true; break;
            }

            if (!line[(y+1)%2][block+k]) {
                line[(y+1)%2][block+k] = true;
                q.push(Coo((y+1)%2, block+k));
            }

            if (t < block-1 && !line[y][block-1]) {
                line[y][block-1] = true;
                q.push(Coo(y, block-1));
            }

            if (!line[y][block+1]) {
                line[y][block+1] = true;
                q.push(Coo(y, block+1));
            }
        }

        if (check) break;
    }

    printf("%d", check);
    return 0;
}
