#include <bits/stdc++.h>
using namespace std;

int cl () {
	cerr << "Time used: " << 1.0 * clock() / CLOCKS_PER_SEC << "s ";
	return 0;
}

const int N = (int)7e3, mod = 998244353;

void add (int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}

int n;
string s;

int f[N + 1][N + 1], sum[N + 1][N + 1];
int lcp[N + 1][N + 1];

bool check (int i, int j) {
	int id = i - j + lcp[i - j + 1][i - j + 1 - j];
	return id < i && s[id] > s[id - j];
}

void solve () {
	for (int d(0); d < n; ++d) {
		lcp[n][n - d] = (s[n - d - 1] == s[n - 1]);
		for (int i(n - 1); i > d; --i) if (s[i - d - 1] == s[i - 1]) {
			lcp[i][i - d] = lcp[i + 1][i - d + 1] + 1;
		}
	}

	for (int i(1); i <= n; ++i) f[i][i] = 1;
	sum[1][1] = 1;
	for (int i(2); i <= n; ++i) for (int j(1); j <= i; ++j) {
		if (s[i - j] != '0') {
			add(f[i][j], sum[i - j][min(j - 1, i - j)]);
			if (j <= i - j && check(i, j)) add(f[i][j], f[i - j][j]);
		}
		sum[i][j] = sum[i][j - 1];
		add(sum[i][j], f[i][j]);
	}

	cout << sum[n][n];
}

int main () {
	#define PHILE "split"
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if (fopen(PHILE".inp", "r")) {
		freopen(PHILE".inp", "r", stdin); freopen(PHILE".out", "w", stdout);
	}

	cin >> s;
	n = s.size();

	solve();
	
	return cl();
}
