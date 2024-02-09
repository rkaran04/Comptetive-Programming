#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define mod 1000000007
 
 // kadane's algorithm
 
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
        ll curr_sum = arr[0];
        ll maxi = arr[0];
 
        for (int i = 1; i < n; i++) {
            if (curr_sum < 0) { //handling if negative elements in the starting..important if array has all negative
                if (arr[i] >= 0) curr_sum = arr[i];
                else curr_sum = max(curr_sum, arr[i]);
            }
            else if (curr_sum + arr[i] <= 0) {
                curr_sum = 0;
            }
            else {
                curr_sum += arr[i];
            }
            maxi = max(maxi, curr_sum);
        }
        cout << maxi << endl;
 
    }
    return 0;
}
