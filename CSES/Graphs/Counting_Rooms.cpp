#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define mod 1000000007

// no. of connected components

void dfs(vector<vector<int>>&map, vector<vector<int>>&vis, int i, int j) {
    // cout << i << " " << j << endl;
    int n = map.size();
    int m = map[0].size();
    if (i < 0 || m < 0 || i >= n || j >= m) return;
    if (map[i][j] == 0 || vis[i][j] == 1) return;

    vis[i][j] = 1;
    int dr[] = {0, 1, 0, -1};
    int dc[] = {1, 0, -1, 0};
    for (int k = 0; k < 4; k++) dfs(map, vis, i + dr[k], j + dc[k]);

    return;
}

int main()
{

    int t ;
    // cin >> t;
    t = 1;
    for (int T = 0; T < t; T++) {
        int n, m;
        cin >> n >> m;

        // int nodes=n*m;

        vector<vector<int>>map(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char x;
                cin >> x;
                if (x == '.') {
                    map[i][j] = 1;
                }
                else map[i][j] = 0;
            }
        }

        vector<vector<int>>vis(n, vector<int>(m, 0));
        int rooms = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (map[i][j] == 1 && vis[i][j] == 0) {
                    // cout << "i j " << i << " " << j << endl;
                    dfs(map, vis, i, j);
                    rooms++;
                }

            }
        }
        cout << rooms << endl;

    }
    return 0;
}
