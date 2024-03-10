#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define mod 1000000007

// BFS and store the dir from the parent in a separate matrix

int main()
{

    int t ;
    // cin >> t;
    t = 1;
    for (int T = 0; T < t; T++) {
        int n, m;
        cin >> n >> m;

        // int nodes=n*m;

        vector<vector<char>>map(n, vector<char>(m));
        int A_i = 0;
        int A_j = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char x;
                cin >> x;
                map[i][j] = x;
                if (x == 'A') {
                    A_i = i;
                    A_j = j;
                }
            }
        }
        vector<vector<char>>dir(n, vector<char>(m));
        vector<vector<int>>vis(n, vector<int>(m, 0));

        
        string ans = "";

        queue < pair<int, int>>q;

        q.push({A_i, A_j});
        vis[A_i][A_j] = 1;

        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            // string curr = q.front().second;
            q.pop();
            // cout << i << " " << j << endl;

            if (map[i][j] == 'B') {
                int r = i;
                int c = j;
                char curr;
                while (1) {
                    if (map[r][c] == 'A') break;
                    curr = dir[r][c];
                    ans.push_back(curr);

                    if (curr == 'R')c--;
                    else if (curr == 'L')c++;
                    else if (curr == 'U')r++;
                    else r--;
                }
                break;
            }

            char dirn[] = {'R', 'D', 'L', 'U'};
            int dr[] = {0, 1, 0, -1};
            int dc[] = {1, 0, -1, 0};
            for (int k = 0; k < 4; k++) {
                int nr = i + dr[k];
                int nc = j + dc[k];
                if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
                if (map[nr][nc] == '#' || vis[nr][nc] == 1) continue;
                
                q.push({nr, nc});
                vis[nr][nc] = 1;
                dir[nr][nc] = dirn[k];
               
            }

        }
        if (ans.size() == 0) cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            cout << ans.size() << endl;
            reverse(ans.begin(), ans.end());
            cout << ans << endl;

        }
    }
    return 0;
}
