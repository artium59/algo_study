#include <iostream>
#include <stack>

long long n;
bool check = false;
std::stack<long long> three;

void find(long long t) {
    if (t <= 0 || three.empty()) {
        if(t == 0) check = true;
        return;
    }
    long long s = three.top();
    three.pop();
    
    find(t-s);
    find(t);
}

int main() {
    scanf("%lld", &n);

    three.push(1);
    while (three.top() * 3 > 0) {
        three.push(three.top() * 3);
    }
    three.pop();

    if (n != 0) find(n);
    printf(check ? "YES" : "NO");

    return 0;
}
