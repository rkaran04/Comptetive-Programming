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
		int n, x;
		cin >> n >> x;

		if (n <= 2) cout << 1 << endl;
		else {
			if ((n - 2) % x == 0) cout << ((n - 2) / x) + 1 << endl;
			else cout << ((n - 2) / x) + 2 << endl;
		}
	}
	//end code
}
