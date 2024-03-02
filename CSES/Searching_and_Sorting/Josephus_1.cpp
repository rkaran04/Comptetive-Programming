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

        vector<int>children(n);

        for (int i = 0; i < n; i++) {
            children[i] = i + 1;
        }

        while (children.size() > 1) {
            vector<int>next;
            // cout << 1 << endl;
            for (int i = 0; i < children.size(); i++) {
                if (i % 2 == 0) {
                    next.push_back(children[i]);
                }
                else cout << children[i] << " ";
            }
            if (children.size() % 2 == 0) children = next;
            else {
                children.clear();
                children.push_back(next.back());
                next.pop_back();
                for (int i = 0; i < next.size(); i++) children.push_back(next[i]);
            }
        }
        cout << children[0] << endl;
    }
    return 0;
}
