#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define mod 1000000007


void solve(int from, int via, int to, int n, vector<int>&towers,
           ll & count, vector<pair<int, int>>&moves)
{
    if (n == 0) return;

    solve(from, to, via, n - 1, towers, count, moves); //moving N-1 to via

    // moving largest to target
    towers[from]--;
    towers[to]++;
    count++;

    moves.push_back({from, to}); // moving N-1 from via to target
    solve(via, from, to, n - 1, towers, count, moves);
    return;

}
// the recursive solution follows top down approach. N disks from one tower to
// other requires the smaller N-1 to be transfered to via, then largest to target
// tower and then N-1 from via to target. Thats what the function is doing.

int main()
{
    int t ;
    // cin >> t;
    t = 1;
    for (int j = 0; j < t; j++) {
        int n;
        cin >> n;

        vector<pair<int, int>>moves;
        ll count = 0;
        vector<int>towers = {{n}, {0}, {0}};

        solve(1, 2, 3, n, towers, count, moves);

        cout << count << endl;

        for (auto it : moves) cout << it.first << " " << it.second << endl;


    }
    return 0;
}
