#include <bits/stdc++.h>

using namespace std;

int main() {
    int sum = 0, i;
    string s;
    vector<int> v;
    cin >> s;
    
    for (i = 0; i < s.size(); i++)
        v.push_back(s[i] - '0');
    
    sort(v.begin(), v.end(), greater<int>());
    
    for (i = 0; i < v.size(); i++)
        sum += v[i];
    
    if (v[v.size() - 1] == 0 && sum % 3 == 0)
        for (i = 0; i < v.size(); i++)
            printf("%d", v[i]);
    else
        printf("-1");
    
    return 0;
}