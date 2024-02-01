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
        set<int>s;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            s.insert(x);
        }
        cout << s.size() << endl;
    }
    return 0;
}
