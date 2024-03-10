#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define mod 1000000007

// bipartite

int main()
{

    int t ;
    // cin >> t;
    t = 1;
    for (int T = 0; T < t; T++) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>>graph(n + 1);
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        vector<int>team(n + 1, -1);
        vector<int>vis(n + 1, 0);
        queue<int>q;
        int flag = 0;
        for (int i = 1; i <= n; i++) {
            if (vis[i] == 1) continue;
            vis[i] = 1;
            team[i] = 1;
            q.push(i);

            while (!q.empty()) {
                int i = q.front();
                q.pop();

                for (auto nbor : graph[i]) {
                    if (vis[nbor] == 1) {
                        if (team[nbor] == team[i]) {
                            flag = 1;
                            break;
                        }
                        else continue;
                    }
                    else {
                        q.push(nbor);
                        team[nbor] = !team[i];
                        vis[nbor] = 1;
                    }
                }
            }
        }

        if (flag == 0) {

            for (int i = 1; i <= n; i++) {
                if (team[i] == 1) cout << 1 << " ";
                else cout << 2 << " ";
            }
        }
        else cout << "IMPOSSIBLE" << endl;

    }
    return 0;
}
