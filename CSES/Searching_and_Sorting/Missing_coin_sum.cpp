#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define mod 1000000007
 
 
 // first check if sorted array starts with 1.
// Keep a variable ans=1(denotes the number uptil which all the sums are possible)
// Next start from 2nd, do ans+1=next req, if arr[i] is more than this, this is the ans.
// else we can make sums uptil ans+arr[i] now. eg. if ans=k==> means that 1,2,...,k are possible,
// if arr[i]<=k+1, then 1,2,....,k,arr[i],arr[i]+1,.....,arr[i]+k are possible.
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
 
        sort(arr.begin(), arr.end());
 
        if (arr[0] != 1) {
            cout << 1 << endl;
            continue;
        }
        int flag = 0;
        ll ans = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i] > ans + 1) {
                cout << ans + 1 << endl;
                flag = 1;
                break;
            }
            ans = ans + arr[i];
        }
        if (flag == 0) cout << ans + 1 << endl;
    }
    return 0;
}
