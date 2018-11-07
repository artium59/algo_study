#include <iostream>
#include <vector>

using namespace std;

vector<int> store;

void function(int num) {
    int sum = 0;
    
    if (num == 1) {
        cout << "HAPPY";
        return;
    }
    
    for(int i = 0; i < store.size(); ++i) {
        if (num == store[i]) {
            cout << "UNHAPPY";
            return;
        }
    }
    
    store.push_back(num);
    
    while (num) {
        int t = num % 10;
        num /= 10;
        sum += t * t;
    }

    function(sum);
}

int main() {
    int x;
    cin >> x;
    
    function(x);
    
    return 0;
}