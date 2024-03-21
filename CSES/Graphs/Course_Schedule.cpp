#include <bits/stdc++.h>
#define int long long
using namespace std;
#define mod 1000000007
#define INF 1000000000000000000
#define NINF -1000000000000000000

int32_t main()
{

    int t ;
    // cin >> t;
    t = 1;
    for (int T = 0; T < t; T++) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>>g(n + 1);
        vector<int>indegree(n + 1, 0);

        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
            indegree[y]++;
            // cout << x << "-->" << y << endl;
        }

        queue<int>q;
        vector<int>topo;

        for (int i = 1; i < n + 1; i++) if (indegree[i] == 0) q.push(i);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (auto nbor : g[node]) {
                indegree[nbor]--;
                if (indegree[nbor] == 0) q.push(nbor);
            }
        }

        if (topo.size() != n) cout << "IMPOSSIBLE" << endl;
        else {
            for (auto it : topo) cout << it << " ";
            cout << endl;
        }


    }
    return 0;
}
