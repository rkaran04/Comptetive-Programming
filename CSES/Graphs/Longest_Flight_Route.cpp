#include <bits/stdc++.h>
#define int long long
using namespace std;
#define mod 1000000007
#define INF 1000000000000000000
#define NINF -1000000000000000000

// 2 times toposort, first excluding 1 so that all paths except the ones leading from 1 get the indegree reduced. Then we do toposort from 1, so that paths from 1
// get covered. 
void topo(vector<vector<int>>&g, queue<int>&q, vector<int>&indegree, vector<int>&parent) {
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto nbor : g[node]) {
            indegree[nbor]--;
            if (indegree[nbor] == 0 && nbor != 1) q.push(nbor);
            parent[nbor] = node;
        }
    }
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

        vector<vector<int>>g(n + 1);
        vector<int>indegree(n + 1, 0);
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
            indegree[y]++;
        }

        vector<int>parent(n + 1, -1);


        queue<int>q;
        for (int i = 2; i <= n; i++) if (indegree[i] == 0) q.push(i);

        topo(g, q, indegree, parent);

        q.push(1);
        parent[1] = -1;
        parent[n] = -1; //if already visited, it can't be reached from 1, we make it -1 just
        // as check

        topo(g, q, indegree, parent);



        if (parent[n] == -1) cout << "IMPOSSIBLE" << endl;
        else {
            vector<int>path;

            int curr = n;
            while (1) {
                path.push_back(curr);
                curr = parent[curr];
                if (curr == -1) break;
            }
            reverse(path.begin(), path.end());
            cout << path.size() << endl;
            for (auto it : path) cout << it << " ";
            cout << endl;
        }

    }
    return 0;
}
