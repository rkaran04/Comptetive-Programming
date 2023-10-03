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

		ll a, b, c, d;
		cin >> a >> b >> c >> d;

		if (d == c) {
			if (b == 0) cout << 1 << " " << c << " " << d << endl;
			else cout << b << " " << c << " " << d << endl;
		}
		else {
			ll x = d - c + 1;
			if (x < a) cout << a << " " << c << " " << d << endl;
			else if (x > b) cout << b << " " << c << " " << c << endl;
			else cout << x << " " << c << " " << d << endl;
		}


	}



	//end code
}
