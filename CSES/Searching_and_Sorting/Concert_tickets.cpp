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
        int n, m;
        cin >> n >> m;
 
        multiset<int>prices;
        vector<int>maxLim(m);
 
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            prices.insert(x);
        }
        for (int i = 0; i < m; i++) cin >> maxLim[i];
 
        for (int it : maxLim) {
            auto x = prices.lower_bound(it);
 
            if (prices.size() == 0 || it < * (prices.begin())) cout << -1 << endl;
            else if (it > *(--prices.end())) {
                cout << *--prices.end() << endl;
                prices.erase(--prices.end());
            }
            else {
                if (*x > it) x--;
                cout << *(x) << endl;
                prices.erase(x);
            }
        }
 
    }
    return 0;
