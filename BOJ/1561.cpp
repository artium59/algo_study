#define ll long long

#include <cstdio>
#include <vector>

inline ll min(ll a, ll b) { return a < b ? a : b; }

ll n, cnt, left = 1, mid, right = 50000000000;
int m, ans = 0, arr[10000];
std::vector<int> vec;

int main() {
    scanf("%lld %d", &n, &m);
    for (int i = 0; i < m; i++)
        scanf("%d", &arr[i]);
	
    while (left <= right) {
        cnt = 0;
        mid = (left+right) / 2;

        for (int i = 0; i < m; i++)
            cnt += mid/arr[i] + min(mid%arr[i], 1);

        if (n <= cnt) right = mid-1;
        else left = mid+1;
    }

    cnt = 0;
    for (int i = 0; i < m; i++) {
        cnt += right/arr[i] + min(right%arr[i], 1);
        if (right%arr[i] == 0) vec.push_back(i);
    }

    printf("%d", vec[n-cnt-1]+1);

    return 0;
}
