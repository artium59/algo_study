#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int t;
    std::string str;
    std::vector<int> nums;
    
    for (int i = 0; i < 3; i++) {
        std::cin >> t;
        nums.push_back(t);
    }
    std::cin >> str;
    
    sort(nums.begin(), nums.end());
    
    for (const auto& s : str)
        std::cout << nums[s - 'A'] << " ";
    
    return 0;
}
