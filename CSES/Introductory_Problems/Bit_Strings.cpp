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
        ll ans = 1;
 
        for (int i = 0; i < n; i++) {
            (ans = (ans * 2) % mod) % mod;
        }
        cout << ans;
    }
    return 0;
