#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define mod 1000000007
 
 
void printPerm(int s, string &ans, vector<int>&arr, vector<string>&store) {
    if (ans.size() == s) {
        store.push_back(ans);
        return;
    }
 
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i]) {
            ans.push_back(char(i + 'a'));
            arr[i]--;
            printPerm(s, ans, arr, store);
            arr[i]++;
            ans.pop_back();
        }
    }
    return;
}
 
 
 
int main()
{
    int t ;
    // cin >> t;
    t = 1;
    for (int j = 0; j < t; j++) {
        string x;
        cin >> x;
 
        vector<int>arr(26, 0);
        for (int i = 0; i < x.size(); i++) {
            arr[int(x[i] - 'a')]++;
        }
 
        string ans = "";
        vector<string>store;
        printPerm(x.size(), ans, arr, store);
 
        cout << store.size() << endl;
 
        for (auto it : store) cout << it << endl;
 
 
    }
    return 0;
}
