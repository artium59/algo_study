#include <iostream>
using namespace std;

const char direction[] { 'N', 'E', 'S', 'W' };
int tc, cur_x, cur_y, min_x, min_y, max_x, max_y, dir;
string str;

void go(char ch) {
    switch (dir) {
        case 0:
            if (ch == 'F') cur_y++;
            else cur_y--;
            break;
        case 1:
            if (ch == 'F') cur_x++;
            else cur_x--;
            break;
        case 2:
            if (ch == 'F') cur_y--;
            else cur_y++;
            break;
        default:
            if (ch == 'F') cur_x--;
            else cur_x++;
    }

    min_y = min(cur_y, min_y);
    max_y = max(max_y, cur_y);

    min_x = min(cur_x, min_x);
    max_x = max(max_x, cur_x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> tc;
    while (tc--) {
        min_x = min_y = 0;
        max_x = max_y = 0;
        cur_x = cur_y = dir = 0;
        cin >> str;

        for (const auto& s : str) {
            switch (s) {
                case 'L':
                    dir = (dir+3) % 4;
                    break;
                case 'R':
                    dir = (dir+1) % 4;
                    break;
                default:
                    go(s);
            }
        }

        cout << (max_x-min_x)*(max_y-min_y) << '\n';
    }

    return 0;
}
