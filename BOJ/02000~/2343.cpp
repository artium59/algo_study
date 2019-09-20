#include <cstdio>
using ll = long long;

const ll MAX = 100000;
int n, m;
ll t, cnt, left = 0, right = 1e17, mid, lesson[MAX];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%lld", lesson+i);

		if (left < lesson[i]) left = lesson[i];
	}

	while (left <= right) {
		mid = (left + right) / 2;
		t = cnt = 0;

		for (int i = 0; i < n; i++) {
			if (t + lesson[i] > mid) { t = 0; cnt++; }
			t += lesson[i];
		}
		if (t > 0) cnt++;

		if (cnt > m) left = mid + 1;
		else right = mid - 1;
	}

	printf("%lld", left);

	return 0;
}
