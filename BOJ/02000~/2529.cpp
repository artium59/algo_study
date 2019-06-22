#include <iostream>
using namespace std;

int k;
char sign[10];
string big="0", small="9876543211";

void Find(string num, int cnt, int visited) {
    if (cnt >= k) {
        if (atoll(big.c_str()) < atoll(num.c_str())) big = num;
        if (atoll(small.c_str()) > atoll(num.c_str())) small = num;
        return;
    }
    
    int cur = num.back() - '0';
    
    if (sign[cnt] == '<') {
        for (int i = cur+1; i < 10; i++) {
            if (visited & 1<<i) continue;
            Find(num+to_string(i) ,cnt+1, visited | 1<<i);
        }
    }
    else {
        for (int i = 0; i < cur; i++) {
            if (visited & 1<<i) continue;
            Find(num+to_string(i) ,cnt+1, visited | 1<<i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> k;
    for (int i = 0; i < k; i++) cin >> sign[i];
    
    for (int i = 0; i < 10; i++)
        Find(to_string(i), 0, 1<<i);
    
    cout << big << "\n" << small;

    return 0;
}
