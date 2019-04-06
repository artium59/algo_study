#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<string, string>> lists;

inline void Print(const auto& s) { cout << s.first << " " << s.second << "\n"; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, start, mid, end;
    string f, l;

    cin >> n;
    for (int h = 0; h < n; h++) {
        cin >> f >> l;
        lists.push_back(make_pair(f, l));
    }

    sort(lists.begin(), lists.end(), [](const auto& a, const auto& b) {
        if (a.second == b.second) return a.first < b.first;
        else return a.second < b.second;
    });

    cin >> q;
    for (int h = 0; h < q; h++) {
        cin >> f >> l;

        start = 0; end = n-1;
        while (start <= end) {
            mid = (start + end) / 2;

            if (lists[mid].second > l) end = mid-1;
            else if (lists[mid].second < l) start = mid+1;
            else {
                if (lists[mid].first > f) end = mid-1;
                else start = mid+1;
            }
        }

        switch (end % 3) {
            case 0:
                Print(lists[end+1]);
                Print(lists[end+2]);
                break;
            case 1:
                Print(lists[end-1]);
                Print(lists[end+1]);
                break;
            case 2:
                Print(lists[end-2]);
                Print(lists[end-1]);
                break;
            default:
                cout << "fail";
        } 
    }

    for_each(lists.begin(), lists.end(), [](const auto& l) {Print(l);});

    return 0;
}
