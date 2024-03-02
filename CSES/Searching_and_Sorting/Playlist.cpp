#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define mod 1000000007
// keep a map of last appearance. Keep a begin variable for current run of unique songs.
// if an occurence after begin is seen, make begin+1 as new begin
int main()
{

    int t ;
    // cin >> t;
    t = 1;
    for (int j = 0; j < t; j++) {

        ll n;
        cin >> n;

        map<ll, ll>mp;
        ll curr = 0;
        ll maxi = 0;
        ll begin = 0;
        for (int i = 0; i < n; i++) {
            ll x;
            cin >> x;
            if (mp.find(x) == mp.end() || mp[x] < begin) {
                curr++;

                mp[x] = i;
            }
            else {
                begin = mp[x] + 1;
                curr = i - begin + 1;
                mp[x] = i;


            }
            maxi = max(maxi, curr);
        }
        cout << maxi << endl;

    }
    return 0;
}
