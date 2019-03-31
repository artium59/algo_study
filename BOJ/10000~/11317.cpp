#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int tc;
    long double a, b, c, s, t, root, p, n;

    cin >> tc;
    for (int h = 0; h < tc; h++) {
        cin >> a >> b >> c >> s >> t;

        root = b*b - a*c*(long double)4.0L;

        if (root < 0)
            cout << "No\n";
        else {
            p = (-b+sqrtl(root))/(a*(long double)2.0L);
            n = (-b-sqrtl(root))/(a*(long double)2.0L);

            if ((s<=p&&p<=t) || (s<=n&&n<=t)) cout << "Yes\n";
            else cout <<"No\n";
        }
    }

    return 0;
}
