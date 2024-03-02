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

        int x, n;
        cin >> x >> n;

        set<int>pos;
        multiset<int>len;
        pos.insert(0);
        pos.insert(x);
        len.insert(x);

        for (int i = 0; i < n; i++) {
            int v;
            cin >> v;
            pos.insert(v);
            auto it = pos.find(v);
            int prevv = (*prev(it));
            int nextt = (*next(it));
            len.erase(len.find(nextt - prevv));
            len.insert(nextt - v);
            len.insert(v - prevv);
            cout << *len.rbegin() << " ";
        }
        cout << endl;


    }
    return 0;
}
