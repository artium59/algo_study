#include <iostream>
#include <map>
using namespace std;

int n, arr[100000], tmp[100000];
long long ans;
string str;
map<string, int> mymap;

void merge(int start, int end) {
    int loc, s1 = start, e1 = (start+end)/2, s2 = (start+end)/2+1, e2 = end;

    loc = s1;
    while (s1 <= e1 && s2 <= e2) {
        if (arr[s1] < arr[s2]) tmp[loc] = arr[s1++];
        else tmp[loc] = arr[s2++], ans += e1 - s1 + 1;
        ++loc;
    }

    for ( ; s1 <= e1; ++loc)
        tmp[loc] = arr[s1++];

    for ( ; s2 <= e2; ++loc)
        tmp[loc] = arr[s2++];

    for (int i = start; i <= end; i++)
        arr[i] = tmp[i];
}

void divide(int start, int end) {
    if (start >= end) return;

    divide(start, (start+end)/2);
    divide((start+end)/2+1, end);

    merge(start, end);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        cin >> n;
        if (n == 0) break;

        ans = 0;
        mymap.clear();
        for (int i = 0; i < n; ++i) {
            cin >> str;
            mymap.insert({ str, i });
        }
        for (int i = 0; i < n; ++i) {
            cin >> str;
            arr[i] = mymap[str];
        }

        divide(0, n-1);
        printf("%lld\n", ans);
    }

    return 0;
}
