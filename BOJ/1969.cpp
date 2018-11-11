#include <bits/stdc++.h>

using namespace std;

char GetChar(int arr[4], int maximum) {
    char acgt[4] = {'A', 'C', 'G', 'T'};
    
    for (int a = 0; a < 4; a++) {
        if (maximum == arr[a])
            return acgt[a];
    }
}

int main() {
    int n, m, hamming = 0;
    string s;
    scanf("%d %d", &n, &m);
    
    vector<string> dna;
    vector<char> minimum;
    vector<int> dist(n, 0);
    
    for (int i = 0; i < n; i++) {
        cin >> s;
        dna.push_back(s);
    }
    
    for (int k = 0; k < m; k++) {
        //                a  c  g  t
        int nucleic[4] = {0, 0, 0, 0};
        
        for (int j = 0; j < n; j++) {
            switch (dna[j].at(k)) {
                case 'A': nucleic[0]++; break;
                case 'C': nucleic[1]++; break;
                case 'G': nucleic[2]++; break;
                case 'T': nucleic[3]++; break;
            }
        }
        
        int maximum = max(max(nucleic[0],nucleic[1]), max(nucleic[2],nucleic[3]));
        minimum.push_back(GetChar(nucleic, maximum));
        hamming += (n - maximum);
    }
    
    for (int l = 0; l < m; l++) 
        printf("%c", minimum[l]);
    printf("\n%d", hamming);
    
    return 0;
}