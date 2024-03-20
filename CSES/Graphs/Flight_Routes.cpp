#include <bits/stdc++.h>
#define int long long
using namespace std;
#define mod 1000000007
#define INF 1000000000000000000
#define NINF -1000000000000000000

// simple dijkstra with k least distances per node
void dijkstra(vector<vector<pair<int, int>>>&g, int s, vector<vector<int>>&dist, int k) {

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;

    pq.push({0, s});
    dist[s][0] = 0;

    while (!pq.empty()) {
        int node = pq.top().second;
        int curr_dist = pq.top().first;
        pq.pop();
        if (curr_dist > dist[node][k - 1]) continue;

        for (auto it : g[node]) {
            int nbor = it.first;
            int d = it.second;
            if (curr_dist + d < dist[nbor][k - 1]) {
                dist[nbor][k - 1] = curr_dist + d;
                pq.push({curr_dist + d, nbor});
                sort(dist[nbor].begin(), dist[nbor].end());
            }
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
        int n, m, k;
        cin >> n >> m >> k;

        // graph input
        vector<vector<pair<int, int>>>g(n + 1);

        for (int j = 0; j < m; j++) {
            int a, b, c;
            cin >> a >> b >> c;
            g[a].push_back({b, c});
        }


        vector<vector<int>>dist(n + 1, vector<int>(k, INF));

        dijkstra(g, 1, dist, k);

        for (auto it : dist[n]) cout << it << " ";


    }
    return 0;
}
