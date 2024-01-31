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
   //reference: https://www.youtube.com/watch?v=rvHNM0gT0vs
        vector<string>grey = {"0", "1"};
 
        for (int i = 1; i < n; i++) {
            int curr_size = grey.size();
            for (ll k = curr_size - 1; k > -1; k--) {
                grey.push_back(grey[k]);
            }
            for (ll k = 0; k < curr_size; k++) {
                grey[k] = '0' + grey[k];
                grey[k + curr_size] = '1' + grey[k + curr_size];
            }
        }
 
        for (ll i = 0; i < grey.size(); i++) {
            cout << grey[i] << endl;
        }
 
    }
    return 0;
