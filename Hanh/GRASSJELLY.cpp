#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define IS_INF(x)   (std::isinf(x))
#define IS_NAN(x)   (std::isnan(x))
#define fi   first
#define se   second
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X, class Y>
    bool minimize(X &x, const Y &y) {
//        assert(y >= 0);
        if (x > y) {
            x = y;
            return true;
        } else return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
//        assert(y >= 0);
        if (x < y) {
            x = y;
            return true;
        } else return false;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }

/* Author: Van Hanh Pham */

/** END OF TEMPLATE. DRINK A CUP OF TIGERSUGAR BEFORE READING MY CODE. **/

const int LIMIT = 169;
int f[15][LIMIT + 1][LIMIT + 1][LIMIT + 1];

#define F(s, i, y, z) ((i) >= (y) ? f[s][i][y][z] : ((i) >= (z) ? f[s][y][i][z] : f[s][y][z][i]))

void precalc(void) {
    FOR(s, 1, 13) FOR(x, s, LIMIT) FOR(y, s, x) FOR(z, s, y) {
        int &res = f[s][x][y][z];
        res = z >= s ? x * y : 0;
        FOR(i, s, x / 2) maximize(res, F(s, i, y, z) + F(s, x - i, y, z));
        FOR(i, s, y / 2) maximize(res, F(s, i, x, z) + F(s, y - i, x, z));
        FOR(i, s, z / 2) maximize(res, F(s, i, x, y) + F(s, z - i, x, y));
    }
}

int main(void) {
#ifdef ONLINE_JUDGE
    freopen("grassjelly.inp", "r", stdin);
    freopen("grassjelly.out", "w", stdout);
#endif // ONLINE_JUDGE

    precalc();

    int t; scanf("%d", &t);
    REP(love, t) {
        int a, b, c, s; scanf("%d%d%d%d", &a, &b, &c, &s);
        if (a < b) swap(a, b);
        if (a < c) swap(a, c);
        if (b < c) swap(b, c);
        printf("%d\n", f[s][a][b][c]);
    }
    return 0;
}

/*** BUBBLE TEA IS GREAT. MY CODE IS AMAZING :D ***/
