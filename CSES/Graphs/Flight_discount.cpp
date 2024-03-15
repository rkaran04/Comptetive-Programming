#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define mod 1000000007
#define INF 1000000000000000000
#define NINF -1000000000000000000

// dijkstra from source, then from dest in reverse graph, then go to each edge, and find smallest (dist_src+edge/2+dist_dest)
void dijkstra(vector<vector<pair<ll, ll>>>&g, ll s, vector<ll>&dist) {

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>pq;

    pq.push({0, s});
    dist[s] = 0;

    while (!pq.empty()) {
        ll node = pq.top().second;
        ll curr_dist = pq.top().first;
        pq.pop();
        if (curr_dist > dist[node]) continue;

        for (auto it : g[node]) {
            ll nbor = it.first;
            ll d = it.second;

            if (curr_dist + d >= 0 && curr_dist + d < dist[nbor]) {
                dist[nbor] = curr_dist + d;
                pq.push({dist[nbor], nbor});
            }
        }
    }
    return;
}


int main()
{

    int t ;
    // cin >> t;
    t = 1;
    for (int T = 0; T < t; T++) {
        ll n, m;
        cin >> n >> m;


        // graph input
        vector<vector<pair<ll, ll>>>g(n + 1);
        vector<vector<pair<ll, ll>>>g2(n + 1);
        vector<vector<ll>>edge;
        for (int j = 0; j < m; j++) {
            ll a, b, c;
            cin >> a >> b >> c;
            // if(a==b) continue;
            g[a].push_back({b, c});
            g2[b].push_back({a, c});
            edge.push_back({a, b, c});
        }

        vector<ll>dist_src(n + 1, INF);
        vector<ll>dist_dest(n + 1, INF);
        dijkstra(g, 1, dist_src);
        dijkstra(g2, n, dist_dest);
        ll ans = INF;

        for (int i = 0; i < m; i++) {
            ll u = edge[i][0];
            ll v = edge[i][1];
            ll wt = edge[i][2];
            if (dist_src[u] == INF || dist_dest[v] == INF) continue;
            ans = min(ans, dist_src[u] + (wt / 2) + dist_dest[v]);
        }
        cout << ans << endl;
    }
    return 0;
}
