#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define mod 1000000007

// two sum problem
 
int main()
{
    int t ;
    // cin >> t;
    t = 1;
    for (int j = 0; j < t; j++) {
        ll n, x;
        cin >> n >> x;
 
        vector<pair<ll, ll>>nums;
 
        for (ll i = 0; i < n; i++) {
            ll y;
            cin >> y;
            nums.push_back({y, i});
        }
 
        sort(nums.begin(), nums.end());
 
        int l = 0;
        int r = n - 1;
        int flag = 0;
        while (l < r) {
            ll sum = nums[l].first + nums[r].first;
            if (sum == x) {
                cout << nums[l].second + 1 << " " << nums[r].second + 1;
                flag = 1;
                break;
            }
            else if (sum < x) l++;
            else r--;
        }
 
        if (flag == 0) cout << "IMPOSSIBLE" << endl;
 
    }
    return 0;
}
