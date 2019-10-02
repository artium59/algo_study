#include <cstdio>

struct plant {
    int j, o, i;
    
    plant(int _j=0, int _o=0, int _i=0): j(_j), o(_o), i(_i) {}
    
    plant& operator=(const auto& other) {
        j = other.j;
        o = other.o;
        i = other.i;
        
        return *this;
    }
    
    plant operator+(const auto& other) const {
        return plant(j+other.j, o+other.o, i+other.i);
    }
    
    plant operator-(const auto& other) const {
        return plant(j-other.j, o-other.o, i-other.i);
    }
    
    void print() {
        printf("%d %d %d\n", j, o, i);
    }
};

int n, m, k, a, b, c, d;
char ch;
plant land[1002][1002];

int main() {
    scanf("%d %d %d", &m, &n, &k);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            scanf(" %c", &ch);
            land[i][j] = land[i-1][j] + land[i][j-1] - land[i-1][j-1];
            
            if (ch == 'J') land[i][j].j++;
            else if (ch == 'O') land[i][j].o++;
            else land[i][j].i++;
        }
    }
    while (k--) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        (land[c][d] - land[a-1][d] - land[c][b-1] + land[a-1][b-1]).print();
    }
    
    return 0;
}
