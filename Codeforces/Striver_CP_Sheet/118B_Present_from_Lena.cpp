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

		int n;
		cin >> n;
		for (int j = 0; j < 2 * n; j++) cout << " ";
		cout << 0 << endl;

		for (int row = -n + 1; row < n; row++) {
			// space
			for (int j = 0; j < 2 * (abs(row)); j++) cout << " ";
      //print asceding
			for (int j = 0; j <= n - abs(row); j++) cout << j << " ";
      // print descending
			for (int j = n - abs(row) - 1; j >= 1; j--) cout << j << " ";

			cout << 0 << endl;
		}
		for (int j = 0; j < 2 * n; j++) cout << " ";
		cout << 0 << endl;

	}

	//end code
}
