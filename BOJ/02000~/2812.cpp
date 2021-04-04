#include <iostream>
#include <vector>
using namespace std;

int n, k;
string str;
vector<char> vec;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k >> str;

    for (const auto& s : str) {
        while (!vec.empty() && vec.back() < s && k) {
            vec.pop_back();
            --k;
        }
        vec.push_back(s);
    }

    for (int i = 0; i < vec.size()-k; ++i)
        cout << vec[i];

    return 0;
}
