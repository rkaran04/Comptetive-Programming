#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define mod 1000000007

// https://www.youtube.com/watch?v=MJn3ogwsUbo

int main()
{

    int t ;
    // cin >> t;
    t = 1;
    for (int T = 0; T < t; T++) {
        int n;
        cin >> n;

        vector<vector<ll>>nums(n);
        vector<ll>fin(n);
        for (int i = 0; i < n; i++) {
            ll a, b, c;
            cin >> a >> b >> c;
            nums[i] = {b, a, c};
            fin[i] = b;
        }

        sort(nums.begin(), nums.end());
        sort(fin.begin(), fin.end());

        vector<ll>dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            ll ans = 0;
            ans = dp[i - 1];
            if (fin[0] >= nums[i - 1][1]) {
                ans = max(ans, nums[i - 1][2]);
            }
            else {
               
                auto x = lower_bound(fin.begin(), fin.end(), nums[i - 1][1]);


                ans = max(ans, dp[x - fin.begin()] + nums[i - 1][2]);

            }
            dp[i] = ans;
            

        }
        cout << dp[n] << endl;
    }
    return 0;
}
