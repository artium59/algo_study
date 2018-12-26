#include <iostream>

// 1100101 -> 0011010 = 4
// 1010101 -> 0101010 = 2
void PrintAnswer(bool isSame, int t, int length) {
    int i = 0;
    if (isSame) {
        (t == 1) ? printf("0") : printf("1");
        i++;
    }
    
    for (; i < length; i++)
        printf("%d", t);
}

int main() {
    int zero = 0, one = 0;
	std::string str;
	std::cin >> str;
	
	for (const auto& s : str)
        s == '0' ? zero++ : one++;
	
    if (zero > one)
        PrintAnswer(false, 1, str.size());
    else if (zero < one)
        PrintAnswer(false, 0, str.size());
    else
        PrintAnswer(true, str[0] - '0', str.size());
    
    return 0;
}