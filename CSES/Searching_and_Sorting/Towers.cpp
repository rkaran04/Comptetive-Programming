#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define mod 1000000007

// greedy: add cube to just greater one

ll binary(vector<ll>&arr, ll x) {
    ll l = 0;
    ll r = arr.size() - 1;
    ll ans = arr.size() - 1;
    while (l < r) {
        ll mid = l + (r - l) / 2;
        if (arr[mid] > x) r = mid;
        else l = mid + 1;
    }
    return r;
}


int main()
{

    int t ;
    // cin >> t;
    t = 1;
    for (int j = 0; j < t; j++) {

        ll n;
        cin >> n;

        vector<ll>arr;
        for (ll i = 0; i < n; i++) {
            ll x;
            cin >> x;
            if (i == 0) arr.push_back(x);
            else {
                if (x >= arr.back()) arr.push_back(x);
                else arr[binary(arr, x)] = x;
            }
        }
        cout << arr.size() << endl;
    }
    return 0;
}
