#include <cstdio>
#include <list>

int n, m;
char ch;
std::list<char> lst;
std::list<char>::iterator it;

int main() {
    scanf("%d", &n); m=n+1;
    while (m--) {
        it = lst.begin();
        
        while (true) {
            scanf("%c", &ch);
            if (ch == '\n') break;
            
            if (ch == '<') {
                if (it == lst.begin()) continue;
                --it;
            }
            else if (ch == '>') {
                if (it == lst.end()) continue;
                ++it;
            }
            else if (ch == '-') {
                if (it == lst.begin()) continue;
                
                if (lst.size() == 1) lst.clear(), it = lst.begin();
                else --it, it = lst.erase(it);
            }
            else {
                lst.insert(it, ch);
            }
        }
        
        while (!lst.empty()) {
            printf("%c", lst.front());
            lst.pop_front();
        }
        if (n != m) printf("\n");
    }
    
    return 0;
}
