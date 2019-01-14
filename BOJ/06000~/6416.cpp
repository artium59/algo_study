#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int a, b, caseCount = 1;

    while (true) {
        int notNodeCount = 0, i = 0, j = 0;
        bool isTree = true;
        std::vector<int> temp, start, end;

        while (true) {
            scanf("%d %d", &a, &b);
            if (a < 1 && b < 1) break;

            temp.push_back(a);
            end.push_back(b);
        }
        if (a == -1 && b == -1) break;

        if (!temp.empty() && !end.empty()) {
            sort(temp.begin(), temp.end());
            unique(temp.begin(), temp.end());
            sort(end.begin(), end.end());

            start.push_back(temp[0]);
            if (temp[0] != temp[1] && temp.size() > 1) {
                for (int h = 1; h < temp.size(); h++) {
                    if (temp[h-1] > temp[h]) break;
                        start.push_back(temp[h]);
                }
            }

            for ( ; j < end.size(); j++) {
                if (j < end.size() - 1) {
                    if (end[j] == end[j+1]) {
                        isTree = false; break;	
                    }
                }
                if (start[i] == end[j]) {
                    notNodeCount++;
                    if (i < start.size()-1) i++;
                }
                else if (start[i] < end[j]) {
                    if (i < start.size()-1) {
                        i++; j--;
                    }
                }
            }

            if (start.size() - notNodeCount != 1) isTree = false;
        }

        printf("Case %d is ", caseCount);
        if (!isTree) printf("not ");
        printf("a tree.\n");
        caseCount++;
    }

    return 0;
}
