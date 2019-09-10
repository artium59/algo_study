#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int size;
string key, crypto;
vector<pair<string, int>> vec;
vector<pair<char, int>> order;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> key >> crypto;
    
    for (int i = 0; i < key.size(); i++)
        order.push_back(make_pair(key[i], i));
    sort(order.begin(), order.end());
    
    size = crypto.size() / key.size();
    
    for (int i = 0; i < key.size(); i++)
        vec.push_back(make_pair(crypto.substr(size*i, size), order[i].second));
    
    sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < key.size(); j++)
            cout << vec[j].first[i];
    }

    return 0;
}
