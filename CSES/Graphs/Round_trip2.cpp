#include <bits/stdc++.h>
#define int long long
using namespace std;
#define mod 1000000007
#define INF 1000000000000000000
#define NINF -1000000000000000000

// cycle detection in directed graph

void dfs(vector<vector<int>>&graph, vector<bool>&vis, int i, vector<int>&p,
         vector<int>&parent, vector<bool>&vis_curr) {
    vis[i] = 1;
    vis_curr[i] = 1;
    for (int nbor : graph[i]) {

        if (vis[nbor] != 1) {
            parent[nbor] = i;
            dfs(graph, vis, nbor, p, parent, vis_curr);
            if (p[0] != -1) return;
        }
        else {
            if (vis_curr[nbor]) {
                p[0] = i;
                p[1] = nbor;
                return;
            }
        }

    }
    vis_curr[i] = 0;
    return;
}


int32_t main()
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
            // cout << x << "-->" << y << endl;
        }

        vector<bool>vis(n + 1, 0);
        vector<bool>vis_curr(n + 1, 0);
        vector<int>parent(n + 1, -1);
        vector<int>p = { -1, -1};

        for (int i = 1; i <= n; i++) {
            if (vis[i] == 0) dfs(graph, vis, i, p, parent, vis_curr);
            if (p[0] != -1) break;
        }
        // cout << "DONE";

        if (p[0] == -1) cout << "IMPOSSIBLE" << endl;
        else {
            vector<int>track;
            int curr = p[0];
            while (1) {
                track.push_back(curr);
                if (curr == p[1]) break;
                curr = parent[curr];
            }
            track.push_back(p[0]);
            reverse(track.begin(), track.end());
            cout << track.size() << endl;
            for (auto it : track) cout << it << " ";
            cout << endl;
        }

    }
    return 0;
}
