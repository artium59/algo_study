#include <bits/stdc++.h>

using namespace std;

// 0: Left Turn standard
int Turn[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main() {
    // M is square size
    // n is order count
    int M, n, count = 0, t = 0;
    
    cin >> M >> n;
    cin.ignore();
    // cout << "M is " << M << " and n is " << n << endl;
    
    int grid[2] = {0, 0};
    
    for (int a = 0; a < n; ++a) {
        string order;
        int num;
        cin >> order >> num;
        
        if (order == "MOVE") {
            for (int b = 0; b < 2; ++b) {
                grid[b] += Turn[t][b] * num;
            }
        }
        else if (order == "TURN") {
            if (num == 0) {
                t++;
                if (t > 3)
                    t = t - 4;
            }
            else {
                t--;
                if (t < 0)
                    t = t + 4;
            }
        }
        
        for (int c = 0; c < 2; ++c) {
            if (grid[c] < 0 || grid[c] > M) {
                ++count;
            }
        }
    }
    
    for (int d = 0; d < 2; ++d) {
        if (count > 0) {
            cout << -1;
            return 0;
        }
        else
            cout << grid[d] << " ";
    }
    
    return 0;
}