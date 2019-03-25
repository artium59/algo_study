#include <iostream>
#include <queue>

int arr[100];
std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

int abs(int a) {
    return a < 0 ? -a : a;
}

int GCD(int a, int b) {
    int c;
    while(b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

void Print(int s) {
    for (int i = 1; i*i <= s; i++) {
        if (s % i == 0) { pq.push(i);
            if (s/i != i) pq.push(s/i);
        }
    }

    pq.pop();
    while (!pq.empty()) {
        printf("%d ", pq.top());
        pq.pop();
    }
}

int main() {
    int n;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (int i = 0; i < n-1; i++)
        arr[i] = abs(arr[i] - arr[i+1]);

    while (--n > 1) {
        for (int i = 0; i < n-1; i++)
            arr[i] = GCD(arr[i], arr[i+1]);
    }

    Print(arr[0]);

    return 0;
}
