#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	// input output
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif
	// input output



	// start code

	int test;
	cin >> test;
	// test = 1;

	for (int t = 0; t < test; t++) {
		ll l, r;
		cin >> l >> r;

		ll i = 2 * l;
		if (i <= r) cout << l << " " << i << endl;
		else cout << -1 << " " << -1 << endl;




	}
	//end code
}
