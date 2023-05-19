// created on Lucian Xu's Laptop

#include <bits/stdc++.h>

// using namespace std;

typedef unsigned int UI;
typedef unsigned long long ULL;
typedef long long LL;
typedef unsigned long long ULL;
typedef __int128 i128;
typedef std::pair<int, int> PII;
typedef std::pair<int, LL> PIL;
typedef std::pair<LL, int> PLI;
typedef std::pair<LL, LL> PLL;
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::vector<LL> vl;
typedef std::vector<vl> vvl;
typedef std::vector<PII> vpi;

#define typet typename T
#define typeu typename U
#define types typename... Ts
#define tempt template <typet>
#define tempu template <typeu>
#define temps template <types>
#define tandu template <typet, typeu>

#define ff first
#define ss second
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) \
    do {           \
    } while (false)
#endif

constexpr int mod = 998244353;
constexpr int inv2 = (mod + 1) / 2;
constexpr int inf = 1000000;
constexpr LL INF = 1e18;
constexpr double pi = 3.141592653589793;
constexpr double eps = 1e-6;

constexpr int lowbit(int x) { return x & -x; }
constexpr int add(int x, int y) { return x + y < mod ? x + y : x - mod + y; }
constexpr int sub(int x, int y) { return x < y ? mod + x - y : x - y; }
constexpr int mul(LL x, int y) { return x * y % mod; }
constexpr void Add(int& x, int y) { x = add(x, y); }
constexpr void Sub(int& x, int y) { x = sub(x, y); }
constexpr void Mul(int& x, int y) { x = mul(x, y); }
constexpr int pow(int x, int y, int z = 1) {
    for (; y; y /= 2) {
        if (y & 1) Mul(z, x);
        Mul(x, x);
    }
    return z;
}
temps constexpr int add(Ts... x) {
    int y = 0;
    (..., Add(y, x));
    return y;
}
temps constexpr int mul(Ts... x) {
    int y = 1;
    (..., Mul(y, x));
    return y;
}

tandu bool Max(T& x, const U& y) { return x < y ? x = y, true : false; }
tandu bool Min(T& x, const U& y) { return x > y ? x = y, true : false; }

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n, m;
    std::cin >> n >> m;
    vvi e(n + 1, vi(n + 1, inf));
    for (int i = 1; i <= n; i++) {
        e[i][i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        std::cin >> u >> v;
        e[u][v] = 1;
    }
    vi st(n + 1);
    std::queue<int> q;
    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            for (int w = 1; w <= n; w++) {
                if (e[u][v] + e[v][w] + e[w][u] <= 3) {
                    e[u][v] = 0, e[v][w] = 0, e[w][u] = 0;
                    e[v][u] = 0, e[w][v] = 0, e[u][w] = 0;
                    q.push(u);
                    q.push(v);
                    q.push(w);
                }
            }
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (st[u]) continue;
        st[u] = 1;
        for (int v = 1; v <= n; v++) {
            for (int w = 1; w <= n; w++) {
                if (e[u][v] + e[v][w] + e[w][u] <= 3) {
                    e[u][v] = 0, e[v][w] = 0, e[w][u] = 0;
                    e[v][u] = 0, e[w][v] = 0, e[u][w] = 0;
                    q.push(v);
                    q.push(w);
                }
            }
        }
    }
    vvi d = e;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                Min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        std::cout << (d[1][i] == inf ? -1 : d[1][i]) << ' ';
    }

    return 0;
}
