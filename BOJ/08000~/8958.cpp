#define MAX 90

#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int testCase, score, sum;
    
    cin >> testCase;
    cin.ignore();
    
    for (int t = 0; t < testCase; ++t) {
        char quiz[MAX];
        
        cin.getline(quiz, MAX);
        
        sum = 0;
        score = 0;
        
        for (int b = 0; b <= strlen(quiz); ++b) {
            if (quiz[b] == 'O') {
                score++;
                sum += score;   
            }
            else {
                score = 0;
            }
        }
        
        cout << sum << endl;
    }
    
    return 0;
}