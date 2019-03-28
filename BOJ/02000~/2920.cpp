#include <iostream>
#include <vector>

using namespace std;

int main() {
    int input, asc = 0, des = 0;
    vector<int> scales;
    
    for (int a = 0; a < 8; ++a) {
        cin >> input;
        scales.push_back(input);
    }
    
    for (int b = 0; b < 7; ++b) {
        if (scales[b] - scales[b + 1] == -1)
            ++asc;
        else if (scales[b] - scales[b + 1] == 1)
            ++des;
    }
    
    if (asc == 7)
        cout << "ascending" << endl;
    else if (des == 7)
        cout << "descending" << endl;
    else
        cout << "mixed" << endl;
    
    // ascending, descending, mixed
    
    return 0;
}