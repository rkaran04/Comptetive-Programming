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
        int a, b;
        cin >> a >> b;


        vector<vector<int>>dp(a + 1, vector<int>(b + 1, 0));

        for (int i = 1; i <= a; i++) {
            for (int j = 1; j <= b; j++) {
                if (i == 1 || j == 1) dp[i][j] = i + j - 2; //i==1-->j and vice versa
                else if (i == j) dp[i][j] = 0;
                else {
                    int ans = 1e9;
                    for (int k = 1; k < i; k++) {
                        ans = min(ans, 1 + dp[k][j] + dp[i - k][j]);
                    }
                    for (int k = 1; k < j; k++) ans = min(ans, 1 + dp[i][k] + dp[i][j - k]);
                    dp[i][j] = ans;
                }
            }
        }
        cout << dp[a][b] << endl;
    }
    return 0;
}
