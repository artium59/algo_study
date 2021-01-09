#include <iostream>
#include <vector>
using namespace std;

int r, c, near_seat_num, near_seat_dist, cur_nearest_person, ans;
char tank[100][100];
vector<int> nearest;
vector<pair<int, int>> people, seats;

inline int dist(pair<int, int> p, pair<int, int> s) {
    return (p.first-s.first)*(p.first-s.first) + (p.second-s.second)*(p.second-s.second);
}

int main() {
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            scanf(" %c", &tank[i][j]);
            if (tank[i][j] == 'X') people.push_back({ i, j });
            else if (tank[i][j] == 'L') seats.push_back({ i, j });
        }
    }

    for (int a = 0; a < people.size(); ++a) {
        near_seat_num = -1;
        near_seat_dist = 1e9;
        cur_nearest_person = -1;
        nearest = vector<int>(people.size(), -1);

        for (int p = 0; p < people.size(); ++p) {
            if (tank[people[p].first][people[p].second] != 'X') continue;

            for (int s = 0; s < seats.size(); ++s) {
                if (tank[seats[s].first][seats[s].second] != 'L') continue;

                if (near_seat_num == -1 || dist(people[p], seats[s]) < near_seat_dist) {
                    near_seat_dist = dist(people[p], seats[s]);
                    near_seat_num = s;
                }
            }

            if (near_seat_num == -1) goto ANS;

            nearest[p] = near_seat_num;
            if (cur_nearest_person == -1 || dist(people[p], seats[near_seat_num]) < dist(people[cur_nearest_person], seats[near_seat_num]))
                cur_nearest_person = p;
        }

        if (cur_nearest_person == -1) break;

        vector<int> candidates;
        for (int p = 0; p < people.size(); ++p) {
            if (tank[people[p].first][people[p].second] != 'X') continue;

            if (nearest[p] == nearest[cur_nearest_person] && 
                dist(people[p], seats[nearest[p]]) == dist(people[cur_nearest_person], seats[nearest[p]]))
                candidates.push_back(p);
        }

        if (candidates.size() > 1) ++ans;

        for (const auto& c : candidates)
            tank[people[c].first][people[c].second] = '.';
        tank[seats[nearest[cur_nearest_person]].first][seats[nearest[cur_nearest_person]].second] = '.';
    }

    ANS:
    printf("%d", ans);
    return 0;
}
