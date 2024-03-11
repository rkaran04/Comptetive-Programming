#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define mod 1000000007

int main()
{

    int t ;
    // cin >> t;
    t = 1;
    for (int T = 0; T < t; T++) {
        int n, m;
        cin >> n >> m;


        // graph input
        vector<vector<pair<int, ll>>>g(n + 1);

        for (int j = 0; j < m; j++) {
            int a, b;
            ll c;
            cin >> a >> b >> c;
            g[a].push_back({b, c});
        }

        // vector<int>vis(n+1,0);
        vector<ll>dist(n + 1, 1e18);
        dist[1] = 0;

        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>pq;
        pq.push({0, 1});

        while (!pq.empty()) {
            int city = pq.top().second;
            ll d = pq.top().first;
            pq.pop();
            if (dist[city] < d) continue;

            for (auto it : g[city]) {
                int nbor = it.first;
                ll dd = it.second;
                if (dist[nbor] <= d + dd) continue;
                dist[nbor] = d + dd;
                pq.push({d + dd, nbor});
            }
        }

        for (int i = 1; i <= n; i++) cout << dist[i] << " ";
        cout << endl;
    }
    return 0;
}
