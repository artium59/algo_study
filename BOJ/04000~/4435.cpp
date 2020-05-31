#include <iostream>
using namespace std;

int n, t, good, evil;
string str[3] = {
    ": Good triumphs over Evil\n",
    ": Evil eradicates all trace of Good\n",
    ": No victor on this battle field\n"
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int z = 1; z <= n; ++z) {
        good = evil = 0;
        
        for (int i = 0; i < 6; ++i) {
            cin >> t;
            switch(i) {
                case 0:
                    good += t*1;
                    break;
                case 1:
                    good += t*2;
                    break;
                case 2:
                case 3:
                    good += t*3;
                    break;
                case 4:
                    good += t*4;
                    break;
                case 5:
                    good += t*10;
            }
        }
        for (int i = 0; i <7; ++i) {
            cin >> t;
            switch(i) {
                case 0:
                    evil += t*1;
                    break;
                case 1:
                case 2:
                case 3:
                    evil += t*2;
                    break;
                case 4:
                    evil += t*3;
                    break;
                case 5:
                    evil += t*5;
                    break;
                case 6:
                    evil += t*10;
            }
        }

        if (good > evil) t = 0;
        else if (good < evil) t = 1;
        else t = 2;

        cout << "Battle " << z << str[t];
        
    }

    return 0;
}
