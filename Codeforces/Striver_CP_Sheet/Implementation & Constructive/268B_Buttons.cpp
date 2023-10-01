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
	// cin >> test;
	test = 1;

	for (int t = 0; t < test; t++) {

		ll n;
		cin >> n;

		ll sq = n * n;
		ll cu = sq * n;

		ll x = (cu - sq) / 2;
		ll y = (2 * cu - 3 * sq + n) / 6;

		cout << x - y + n << endl;

	}

	//end code
}
