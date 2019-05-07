#include <iostream>
#include <vector>

int n, t, cnt = 1;
bool swch = true;
std::vector<int> vec;
std::vector<char> ans;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);

        while (vec.empty() || vec.back() < t) {
            vec.push_back(cnt);
            ans.push_back('+');
            cnt++;
        }

        if (vec.back() > t) {
            swch = false; break;
        }
        else if (vec.back() == t) {
            vec.pop_back(); ans.push_back('-');
        }
    }

    if (!swch)
        printf("NO");
    else {
        for (const auto& a : ans)
            printf("%c\n", a);
    }

    return 0;
}
