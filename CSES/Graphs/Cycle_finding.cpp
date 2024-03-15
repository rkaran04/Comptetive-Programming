#include <bits/stdc++.h>
#define int long long
using namespace std;
#define mod 1000000007
#define INF 1000000000000000000
#define NINF -1000000000000000000

// https://www.youtube.com/watch?v=kZfm68XKC58

int32_t main()
{

    int t ;
    // cin >> t;
    t = 1;
    for (int T = 0; T < t; T++) {
        int n, m;
        cin >> n >> m;

        // graph input
        vector<vector<int>>edges;
        // pseudo node to handle disconnected nodes
        for (int i = 1; i <= n; i++) edges.push_back({0, i, 0});
        for (int j = 0; j < m; j++) {
            int a, b, c;
            cin >> a >> b >> c;
            edges.push_back({a, b, c});
        }


        vector<int>dist(n + 1, INF);
        vector<int>relaxant(n + 1, -1);
        dist[0] = 0;
        // n iterations
        int flag;
        for (int i = 0; i < n; i++) {
            flag = -1;
            for (auto it : edges) {
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if (dist[u] == INF) continue;
                if (dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                    relaxant[v] = u;
                    flag = v;
                }
            }
        }
        if (flag == -1) {
            cout << "NO" << endl;
            continue; //end of test case
        }

        //n tracebacks to land in a cycle

        for (int i = 0; i < n; i++) flag = relaxant[flag]; //we are moving backwards
        //via affectd nodes

        vector<int>cycle;
        int curr = flag;
        while (1) {
            cycle.push_back(curr);
            curr = relaxant[curr];
            if (curr == flag) break;
        }
        cycle.push_back(flag);
        reverse(cycle.begin(), cycle.end());
        cout << "YES" << endl;
        for (auto it : cycle) cout << it << " ";
        cout << endl;


    }
    return 0;
}
