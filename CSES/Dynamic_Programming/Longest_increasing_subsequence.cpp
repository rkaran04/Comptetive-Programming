#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define mod 1000000007
// nlogn---non-trivial algo...see strivers video (LIS binary search)
int main()
{

    int t ;
    // cin >> t;
    t = 1;
    for (int T = 0; T < t; T++) {
        int  n;
        cin >> n;

        vector<int>nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];

        vector<int>temps;
        temps.push_back(nums[0]);

        for (int i = 1; i < n; i++) {
            if (temps.back() < nums[i]) temps.push_back(nums[i]);
            else {
                auto l = lower_bound(temps.begin(), temps.end(), nums[i]);
                temps[l - temps.begin()] = nums[i];
                // cout << l << endl;
            }
        }
        cout << temps.size() << endl;

    }
    return 0;
}
