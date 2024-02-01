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
        int n, m, k;
        cin >> n >> m >> k;

        vector<ll>desired;
        vector<ll>availbl;
        for (int i = 0; i < n; i++) {
            ll x;
            cin >> x;
            desired.push_back(x);
        }

        for (int i = 0; i < m; i++) {
            ll x;
            cin >> x;
            availbl.push_back(x);
        }

        sort(desired.begin(), desired.end());
        sort(availbl.begin(), availbl.end());

        // for (auto it : desired)cout << it << endl;

        ll i = 0, l = 0;
        int ans = 0;
        while (i < n && l < m) {
            if (availbl[l] >= desired[i] - k && availbl[l] <= desired[i] + k) {
                ans++;
                l++;
                i++;
            }
            else if (availbl[l] < desired[i] - k) l++;
            else i++;
        }

        cout << ans << endl;


    }
    return 0;
}
