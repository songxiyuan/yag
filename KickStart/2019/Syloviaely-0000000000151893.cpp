#include <bits/stdc++.h>

const int MAXN = 50010;

int n, r, c, sr, sc;
char s[MAXN];

int getid(char t) {
    if (t == 'N') return 0;
    if (t == 'S') return 1;
    if (t == 'W') return 2;
    if (t == 'E') return 3;
    assert(0);
}

int dir[4][2] = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
};

std::map<std::pair<int, int>, bool> vis;
std::map<std::pair<std::pair<int, int>, int>, std::pair<int, int>> map;

int main() {
    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; ++cs) {
        scanf("%d%d%d%d%d", &n, &r, &c, &sr, &sc);
        scanf("%s", s);
        vis.clear();
        map.clear();
        vis[{sr, sc}] = true;
        for (int i = 0; i < n; ++i) {
            int k = getid(s[i]);
            int x = sr + dir[k][0];
            int y = sc + dir[k][1];
            while (vis[{x, y}]) {
                auto it = map.find({{x, y}, k});
                if (it != map.end()) {
                    x = it->second.first;
                    y = it->second.second;
                } else {
                    x += dir[k][0];
                    y += dir[k][1];
                }
            }

            while (sr != x || sc != y) {
                int tx = sr, ty = sc;
                auto it = map.find({{sr, sc}, k});
                if (it != map.end()) {
                    sr = it->second.first;
                    sc = it->second.second;
                } else {
                    sr += dir[k][0];
                    sc += dir[k][1];
                }
                map[{{tx, ty}, k}] = {x, y};
            }
            vis[{x, y}] = true;
        }
        printf("Case #%d: %d %d\n", cs, sr, sc);
    }

    return 0;
}