#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define mod 1000000007

// standard bfs and path tracking

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

        vector<int>parent(n + 1, -1);
        vector<int>vis(n + 1, 0);
        queue<pair<int, int>>q;
        q.push({1, 1});
        int flag = 0;
        while (!q.empty()) {
            int i = q.front().first;
            int dist = q.front().second;
            q.pop();
            if (i == n) {
                flag = 1;
                break;
            }

            for (auto nbor : graph[i]) {
                if (vis[nbor] == 0) {
                    q.push({nbor, dist + 1});
                    parent[nbor] = i;
                    vis[nbor] = 1;
                }
            }
        }
        if (flag == 1) {
            vector<int>path;
            int curr = n;
            while (1) {
                path.push_back(curr);
                if (curr == 1) break;
                curr = parent[curr];
            }
            reverse(path.begin(), path.end());
            cout << path.size() << endl;
            for (auto it : path) cout << it << " ";
        }
        else cout << "IMPOSSIBLE" << endl;

    }
    return 0;
}
