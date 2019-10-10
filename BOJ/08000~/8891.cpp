#include <cstdio>
#include <vector>

int t, a, b, c, d, s;
std::vector<int> vec(1, 0);

int main() {
    for (int i = 1; vec.back() < 40000; i++)
        vec.push_back(vec.back()+i);

    s = vec.size();
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &a, &c);

        for (int i = 1; i < s; i++) {
            if (a <= vec[i]) {
                b = 1 + vec[i] - a;
                a += i - vec[i];
                break;
            }
        }
        for (int i = 1; i < s; i++) {
            if (c <= vec[i]) {
                d = 1 + vec[i] - c;
                c += i - vec[i];
                break;
            }
        }

        a += c; b += d;
        printf("%d\n", vec[a+b-1]-b+1);
    }

    return 0;
}
