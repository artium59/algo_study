#include <iostream>
#include <iomanip>
#include <cmath>
#include <map>
using namespace std;

float cnt;
string str;
map<string, float> mymap;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (getline(cin, str)) {
        if (mymap.find(str) != mymap.end())
            ++mymap[str];
        else
            mymap.insert({ str, 1 });
        ++cnt;
    }

    for (const auto& m : mymap)
        cout << m.first << " " << fixed << setprecision(4) << m.second/cnt*100 << "\n";

    return 0;
}
