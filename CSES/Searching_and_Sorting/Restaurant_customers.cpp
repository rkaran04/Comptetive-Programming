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
        vector<ll>entry;
        vector<ll>exit;
        for (int i = 0; i < n; i++) {
            ll a, b;
            cin >> a >> b;
            entry.push_back(a);
            exit.push_back(b);
        }
        sort(entry.begin(), entry.end());
        sort(exit.begin(), exit.end());
 
        ll curr = 0;
        ll maxi = 0;
 
        int l = 0;
        int r = 0;
        while (l < n) {
            if (entry[l] < exit[r]) {
                curr++;
                maxi = max(maxi, curr);
                l++;
            }
            else if (entry[l] > exit[r]) {
                curr--;
                r++;
            }
            else {
                l++;
                r++;
            }
        }
 
        cout << maxi << endl;
    }
    return 0;
}
