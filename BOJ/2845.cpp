#include <iostream>
using namespace std;

int main() {
    int l, p, arr[5];

    cin >> l >> p;
    for (int i = 0; i < 5; i++)
        cin >> arr[i];

    for (int i = 0; i < 5; i++)
        cout << arr[i] - l*p << (i == 4 ? "" : " ");

    return 0;
}
