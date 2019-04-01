#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[10], brr[10];
    long long ans = 0;
    string a, b;
    cin >> a >> b;

    for (int i = 0; i < 10; i++)
        arr[i] = brr[i] = 0;

    for (const auto& i : a)
        arr[i-'0']++;

    for (const auto& i : b)
        brr[i-'0']++;

    for (int i = 1; i < 10; i++) {
        for (int j = 1; j < 10; j++)
            ans += i*j*arr[i]*brr[j];
    }

    cout << ans;

    return 0;
}
