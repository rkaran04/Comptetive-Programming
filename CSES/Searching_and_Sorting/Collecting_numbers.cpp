#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define mod 1000000007
 
 
// O(N)
// We first note positions of numbers in the array. Then we start by ans=1 and curr_index=position of 1
// we check position of 2, if greater than 1, then we can collect 2 in the traversal only. Otherwise, we 
// increase ans by 1 as we have to collect 2 in next traversal. Then we update curr_index as position of 2

int main()
{
    int t ;
    // cin >> t;
    t = 1;
    for (int j = 0; j < t; j++) {
        int n;
        cin >> n;
 
        vector<int>arr; //stores array
        vector<int>pos(n + 1, 0); //stores position
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            arr.push_back(x);
            pos[x] = i;
        }
 
        int ans = 1;
        int curr_ind = pos[1];
        for (int i = 2; i <= n; i++) {
            if (pos[i] < curr_ind) ans++;
            curr_ind = pos[i];
        }
        cout << ans << endl;
 
    }
    return 0;
}
