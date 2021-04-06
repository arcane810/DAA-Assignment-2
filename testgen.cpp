#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define sz(x) (int)x.size()
#define int long long
#define ld long double

const int MOD = 1e9 + 7;
const int MAX_N = 1e6 + 5;
using pii = pair<long long, long long>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int32_t main(int32_t argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = atoi(argv[1]);
    int p = atoi(argv[2]);
    cout << n << " " << p << "\n";

    for (int i = 0; i < 5; i++) {
        int m = rng() % 5;
        int c = rng() % 5;
        for (int j = 0; j < n / 5; j++) {
            ld x = i * (n / 5.0 * 1) + j * 1;
            ld y = m * x + c + ((int)(rng() % 100) - (int)50) / 100.00;
            cout << x << " " << y << "\n";
        }
    }

    return 0;
}
