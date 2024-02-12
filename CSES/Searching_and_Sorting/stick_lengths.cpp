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
        int n;
        cin >> n;
 
        vector<ll>arr;
 
        for (int i = 0; i < n; i++) {
            ll x;
            cin >> x;
            arr.push_back(x);
        }
       // median
        sort(arr.begin(), arr.end());
 
        ll final = arr[arr.size() / 2];
 
        ll ans = 0;
 
        for (auto it : arr) ans += abs(final - it);
 
        cout << ans << endl;
 
    }
    return 0;
}
