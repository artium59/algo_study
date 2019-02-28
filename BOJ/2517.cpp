#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> people;

void merging(int s1, int e1, int e2) {
    int p = s1, q = e1+1, cnt = 0;
    vector<pair<int, int>> temp;

    while (p <= e1 && q <= e2) {
        if (people[p].first > people[q].first) {
            temp.push_back(people[p]); p++; cnt++;
        }
        else {
            temp.push_back(people[q]);
            temp[temp.size()-1].second += cnt;
            q++;
        }
    }

    while (p <= e1) {
        temp.push_back(people[p]); p++;
    }
	
    while (q <= e2) {
        temp.push_back(people[q]);
        temp[temp.size()-1].second += cnt;
        q++;
    }
	
    for (int i = s1; i <= e2; i++)
        people[i] = temp[i-s1];
}

void mergesort(int start, int end) {
    if (start >= end) return;

    int mid = (start + end) / 2;

    mergesort(start, mid);
    mergesort(mid+1, end);

    merging(start, mid, end);
}

int main() {
    int n, t, start, end;
    vector<int> arr;
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        arr.push_back(t);
        people.push_back(make_pair(t, 1));
    }
    
    mergesort(0, n-1);
    
    for (const auto& a : arr) {
        start = 0; end = n-1;

        while (start <= end) {
            t = (start + end) / 2;

            if (people[t].first == a) break;
            else if (people[t].first > a) start = t+1;
            else end = t-1;
        }

        printf("%d\n", people[t].second);
    }
    
    return 0;
}