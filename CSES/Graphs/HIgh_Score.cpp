#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define mod 1000000007
#define INF 1000000000000000000
#define NINF -1000000000000000000

// BELLMAN FORD

int main()
{

    int t ;
    // cin >> t;
    t = 1;
    for (int T = 0; T < t; T++) {
        ll n, m;
        cin >> n >> m;


        // graph input
        vector<vector<ll>>g;

        for (int j = 0; j < m; j++) {
            ll a, b, c;
            cin >> a >> b >> c;
            // if(a==b) continue;
            g.push_back({a, b, -1 * c});
        }


        vector<ll>dist(n + 1, INF);
        dist[1] = 0;

        if (n == 1) {
            for (int j = 0; j < m; j++) {
                int u = g[j][0];
                int v = g[j][1];
                int wt = g[j][2];
                if (dist[u] == INF) continue;
                dist[v] = min(dist[v], dist[u] + wt);
                // dist[v] = max(dist[v], NINF);

            }
            if (dist[1] != 0) {
                cout << -1 << endl;
            }
            else cout << 0 << endl;
            continue;
        }


        for (int i = 0; i < (n - 1); i++) {
            // cout << i << endl;
            for (int j = 0; j < m; j++) {
                int u = g[j][0];
                int v = g[j][1];
                int wt = g[j][2];
                if (dist[u] == INF) continue;
                dist[v] = min(dist[v], dist[u] + wt);
                // dist[v] = max(dist[v], NINF);

            }
        }

        for (int i = 0; i < (n - 1); i++) {
            // cout << i << endl;
            for (int j = 0; j < m; j++) {
                int u = g[j][0];
                int v = g[j][1];
                int wt = g[j][2];
                if (dist[u] == INF) continue;
                if (dist[u] + wt < dist[v]) dist[v] = NINF;

            }
        }
        if (dist[n] == NINF) cout << -1 << endl;
        else cout << dist[n] * -1 << endl;
    }
    return 0;
}
