#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    int num, temp, result = 0, count = 0, one, ten;
    
    cin >> num;
    
    result = num;
    
    while (1) {
        ten = result / 10;
        one = result % 10;
        temp = ten + one;
        result = one * 10 + (temp % 10);
        count++;
        
        if (result == num)
            break;
    }
    
    cout << count;
    
    return 0;
}