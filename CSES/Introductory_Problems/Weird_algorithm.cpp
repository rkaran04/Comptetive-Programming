#include<bits/stdc++.h>
using namespace std;


// checks numbers at every iteration and apply the steps the ques asks
int main() {


    long long n;
    cin >> n;
    cout << n;
    if (n == 1) return 0;
    while (1) {
        cout << " ";
        if (n % 2 == 0) n = n >> 1;
        else n = n * 3 + 1;
        cout << n;
        if (n == 1) break;
    }

    return 0;
}
