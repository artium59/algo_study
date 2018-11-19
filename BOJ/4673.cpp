#define MAX 10001

#include <iostream>

using namespace std;

void SelfNumber();
void Initialize(bool a[]);
int Calc(int num);

int main()
{
	SelfNumber();
}

void SelfNumber() {
	bool isSelfNum[MAX];

	Initialize(isSelfNum);

	// i = positive number
	for (int i = 1; i < MAX; i++) {
		isSelfNum[Calc(i)] = false;
	}

	for (int b = 1; b < MAX; ++b) {
		if (isSelfNum[b])
			cout << b << endl;
	}
}

void Initialize(bool a[]) {
	for (int i = 0; i < MAX; ++i) {
		a[i] = true;
	}
}

int Calc(int num) {
	int sum = num;

	if (sum >= 1000) {
		sum += num / 1000;
		num = num % 1000;
	}

	if (sum >= 100) {
		sum += num / 100;
		num = num % 100;
	}

	if (sum >= 10) {
		sum += num / 10;
		num = num % 10;
	}

	return (sum + num);
}