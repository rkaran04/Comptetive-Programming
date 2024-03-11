#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define mod 1000000007


int main()
{

    int t ;
    // cin >> t;
    t = 1;
    for (int T = 0; T < t; T++) {
        int n, m;
        cin >> n >> m;
      
      // graph input
        vector<vector<char>>g(n, vector<char>(m));
        int A_i;
        int A_j;
        vector<pair<int, int>>monsters;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char ch;
                cin >> ch;
                g[i][j] = ch;
                if (ch == 'A') {
                    A_i = i;
                    A_j = j;
                }
                if (ch == 'M')monsters.push_back({i, j});
            }
        }
        if (A_i == 0 || A_j == 0 || A_i == n - 1 || A_j == m - 1) {
            cout << "YES" << endl;
            continue;
        }

        int timer = 0;
        vector<vector<int>>vis_time(n, vector<int>(m, 1e9));


        // lava preprocessing
        queue <pair< pair<int, int>, int>>q;

        for (auto m : monsters) {
            int i = m.first;
            int j = m.second;
            q.push({{i, j}, 0});
            vis_time[i][j] = 0;
        }

        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int time = q.front().second;
            q.pop();
            // cout << i << " " << j << endl;


            int dr[] = {0, 1, 0, -1};
            int dc[] = {1, 0, -1, 0};
            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
                if (g[nr][nc] == '#' || vis_time[nr][nc] != 1e9) continue;

                q.push({{nr, nc}, time + 1});
                vis_time[nr][nc] = time + 1;
            }
        }
        // cout << "DONE1" << endl;
        // continue;

        // player bfs

        vector<vector<char>>dir(n, vector<char>(m));
        vector<vector<int>>vis(n, vector<int>(m, 0));

        q.push({{A_i, A_j}, 0});

        int exiti = 0;
        int exitj = 0;
        int flag = 0;

        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int time = q.front().second;
            q.pop();
            // cout << i << " " << j << endl;

            char dirn[] = {'R', 'D', 'L', 'U'};
            int dr[] = {0, 1, 0, -1};
            int dc[] = {1, 0, -1, 0};
            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
                if (g[nr][nc] == '#' || vis[nr][nc] == 1) continue;
                if (time + 1 >= vis_time[nr][nc]) continue;
                if (nr == 0 || nc == 0 || nr == n - 1 || nc == m - 1) {
                    exiti = nr;
                    exitj = nc;
                    flag = 1;
                    dir[nr][nc] = dirn[k];
                    break;
                }
                q.push({{nr, nc}, time + 1});
                vis[nr][nc] = 1;
                dir[nr][nc] = dirn[k];
            }
            if (flag) break;

        }
        // cout << "DONE2" << endl;
        if (flag == 0) cout << "NO" << endl;
        else {
            string ans = "";
            int i = exiti;
            int j = exitj;
            while (1) {
                char x = dir[i][j];
                ans.push_back(x);
                if (x == 'U') i++;
                if (x == 'D') i--;
                if (x == 'R') j--;
                if (x == 'L') j++;
                if (g[i][j] == 'A') break;
            }
            cout << "YES" << endl;
            cout << ans.size() << endl;
            reverse(ans.begin(), ans.end());
            cout << ans << endl;
        }

    }
    return 0;
}
