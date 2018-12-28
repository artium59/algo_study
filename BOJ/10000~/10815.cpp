#include <iostream>
#include <vector>

int main() {
	int n, m, t;
	bool isHave[20000001];
	std::vector<int> detects;
	
	std::fill(isHave, isHave+20000001, false);
	
	scanf("%d", &n);
	for (int h = 0; h < n; h++) {
		scanf("%d", &t);
		isHave[t + 10000000] = true;
	}
	
	scanf("%d", &m);
	for (int h = 0; h < m; h++) {
		scanf("%d", &t);
		detects.push_back(t);
	}
	
	for (const auto& d : detects) {
		if (isHave[d+10000000]) printf("1 ");
		else printf("0 ");
	}
	
	return 0;
}