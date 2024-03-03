#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define mod 1000000007


int main()
{

    int t ;
    // cin >> t;
    t = 1;
    for (int T = 0; T < t; T++) {

        int n;
        cin >> n;
        vector<int>dp(n + 1, 1e9);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            int num = i;
            while (num) {
                int d = num % 10;
                dp[i] = min(dp[i], 1 + dp[i - d]);
                num = (num - d) / 10;
            }
        }

        cout << dp[n] << endl;
    }
    return 0;
}
