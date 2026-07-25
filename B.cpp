#include <bits/stdc++.h>
#define LAPDZ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define task "lapdz"
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define reset(x) memset(x, (int)0, sizeof x)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i > b; i--)
#define REP(i, a, b) for(int i = (a); i <= (b); i++)
#define REPD(i, a, b) for(int i = (a); i >= (b); i--)
#define all(x) x.begin(), x.end()
#define rall(a) (a).rbegin(), (a).rend()
#define turn_on(i, m) (m |= (1LL << i))
#define turn_off(i, m) (m &= ~(1LL << i))
#define bit(x, i) ((x >> i) & 1)
#define MASK(i) (1LL << (i))
#define c_bit(i) __builtin_popcountll(i)
#define el '\n'
using namespace std;

typedef long long ll;
typedef double db;

const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,1,-1};
const int ddx[8] = {1,-1,1,1,-1,-1,0,0};
const int ddy[8] = {0,0,-1,1,-1,1,-1,1};

const ll mod = 1e9 + 7;
const ll maxn = 505;
const ll inf = 4e18;
const ll base = 311;
const db pi = 3.14159265;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    REP(i,1,n) cin >> a[i];
    ll p = 0;
    FOR(i,1,n){
        ll can = p + 1;
        if(a[i] < can){
            cout << "NO" << el;
            return;
        }
        a[i + 1] += a[i] - can;
        p = can;
    }
    if(a[n] > p) cout << "YES\n";
    else cout << "NO\n";
}

signed main() {
    LAPDZ;
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    ll test = 1;
     cin >> test;
    while (test--) solve();

    return 0;
}
