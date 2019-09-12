#include <cstdio>
#include <vector>

int n, l, t;
std::vector<int> vec;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        
        l = lower_bound(vec.begin(), vec.end(), t) - vec.begin();
        
        if (l == vec.size()) vec.push_back(t);
        else vec[l] = t;
    }
    
    printf("%d", vec.size());

    return 0;
}
