#include <iostream>
#include <list>
using namespace std;

int n, t;
list<pair<int, int>> balloon;
list<pair<int, int>>::iterator it;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        balloon.push_back(make_pair(i, t));
    }

    it = balloon.begin();
    while (!balloon.empty()) {
        if (it == balloon.end()) it = balloon.begin();
        printf("%d ", it->first+1);
        t = it->second;
        it = balloon.erase(it);

        if (balloon.empty()) break;

        if (t > 0) {
            while (--t) {
                if (it == balloon.end()) it = balloon.begin();
                ++it;
            }
        }
        else {
            while (t++) {
                if (it == balloon.begin()) it = balloon.end();
                --it;
            }
        }
    }

    return 0;
}
