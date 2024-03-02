#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define mod 1000000007

// We are just looking at inversions of every number with its adjascent ones. So whe we swap, 
// We see the two numbers involved, note its adjascent numbers( wrt 1,2,...,n 
// eg. if 3 is there, then (2,3) and (3,4)). We subtract this amount from answer, then swap 
// the numbers, and add new inversions.
// https://www.youtube.com/watch?v=LEL3HW4dQew&t=212s


int main()
{

    int t ;
    // cin >> t;
    t = 1;
    for (int j = 0; j < t; j++) {

        ll n, m;
        cin >> n >> m;

        vector<ll>pos(n + 1, 0);
        vector<ll>arr;
        arr.push_back(0);
        for (int i = 1; i <= n; i++) {
            ll x;
            cin >> x;
            arr.push_back(x);
            pos[x] = i;
        }

        ll ans = 1;
        for (int i = 2; i <= n; i++) if (pos[i - 1] > pos[i]) ans++;

        for (int i = 0; i < m; i++) {
            ll a, b;
            cin >> a >> b;

            set<pair<ll, ll>> s;
            if (arr[a] != 1) s.insert({arr[a] - 1, arr[a]});
            if (arr[b] != 1) s.insert({arr[b] - 1, arr[b]});
            if (arr[a] != n) s.insert({arr[a], arr[a] + 1});
            if (arr[b] != n) s.insert({arr[b], arr[b] + 1});

            for (auto it : s) {
                ll x = it.first;
                ll y = it.second;

                if (pos[x] > pos[y]) ans--;
            }
            ll temp = arr[b];
            arr[b] = arr[a];
            arr[a] = temp;

            pos[arr[a]] = a;
            pos[arr[b]] = b;

            for (auto it : s) {
                ll x = it.first;
                ll y = it.second;

                if (pos[x] > pos[y]) ans++;
            }
            cout << ans << endl;
        }
    }
    return 0;
}
