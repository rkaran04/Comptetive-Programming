#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define mod 1000000007

// identifying disconnected components

void dfs(vector<vector<int>>&graph, vector<int>&vis, int i) {
    vis[i] = 1;
    for (auto nbor : graph[i]) {
        if (vis[nbor] == 0) dfs(graph, vis, nbor);
    }
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

        vector<vector<int>>graph(n + 1);
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        vector<int>component_roots;
        vector<int>vis(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            if (vis[i] == 0) {
                vis[i] = 1;
                component_roots.push_back(i);
                dfs(graph, vis, i);
            }
        }

        cout << component_roots.size() - 1 << endl;
        for (int i = 0; i < component_roots.size() - 1; i++) {
            cout << component_roots[i] << " " << component_roots[i + 1] << endl;
        }
    }
    return 0;
}
