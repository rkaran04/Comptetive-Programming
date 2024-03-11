#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define mod 1000000007

// FLOYD WARSHALL ALGO

int main()
{

    int t ;
    // cin >> t;
    t = 1;
    for (int T = 0; T < t; T++) {
        int n, m, q;
        cin >> n >> m >> q;


        // graph input
        // vector<vector<int>>g(n + 1);
        vector<vector<ll>>mat(n + 1, vector<ll>(n + 1, 1e15));

        for (int i = 1; i <= n; i++) mat[i][i] = 0;


        for (int j = 0; j < m; j++) {
            int a, b;
            ll c;
            cin >> a >> b >> c;
            mat[a][b] = min(mat[a][b], c);
            mat[b][a] = mat[a][b];
        }
        // cout << "done1" << endl;
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                    mat[j][i] = mat[i][j];
                }
            }
        }
        // cout << "done2" << endl;
        for (int i = 0; i < q; i++) {
            int a, b;
            cin >> a >> b;
            if (mat[a][b] < 1e15) cout << mat[a][b] << endl;
            else cout << -1 << endl;
        }



    }
    return 0;
}
