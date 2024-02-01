#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define mod 1000000007



int main()
{
    int t ;
    // cin >> t;
    t = 1;
    for (int j = 0; j < t; j++) {
        int n, x;
        cin >> n >> x;
        vector<ll>wt;
        for (int i = 0; i < n; i++) {
            ll y;
            cin >> y;
            wt.push_back(y);
        }
        sort(wt.begin(), wt.end());
        // for (auto it : wt) cout << it << endl;
        int ans = 0;
        int l = 0;
        int r = wt.size() - 1;
        while (l <= r) {
            if (wt[l] + wt[r] <= x) {
                l++;
                r--;
            }
            else r--;
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
