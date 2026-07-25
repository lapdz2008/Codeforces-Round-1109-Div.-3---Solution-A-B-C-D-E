#include <bits/stdc++.h>
#define LAPDZ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define task "lapdz"
#define pb push_back
#define fi first
#define se second
#define sz(x) (ll)(x).size()
#define reset(x) memset(x, 0, sizeof(x))
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
#define FORD(i,a,b) for(ll i = (a); i > (b); i--)
#define REP(i,a,b) for(ll i = (a); i <= (b); i++)
#define REPD(i,a,b) for(ll i = (a); i >= (b); i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define turn_on(i,m) (m |= (1LL << (i)))
#define turn_off(i,m) (m &= ~(1LL << (i)))
#define bit(x,i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define c_bit(x) __builtin_popcountll(x)
#define el '\n'

using namespace std;

typedef long long ll;
typedef double db;

const ll mod = 1e9 + 7;
const ll inf = 4e18;
const ll maxn = 2e5 + 5;
const ll base = 311;
const db pi = 3.14159265;

void solve(){
    ll n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector<ll> pref(n, 0);

    FOR(i, 0, n - 1) pref[i + 1] = pref[i] + (s[i] == s[i + 1]);
    

    while (q--)
    {
        ll l, r, k;
        cin >> l >> r >> k;

        if (l == r){
            cout << "YES" << el;
            continue;
        }

        ll c = pref[r - 1] - pref[l - 1];
        ll need = (c + 1) / 2;

        if (need <= k) cout << "YES" << el;
        else cout << "NO" << el;
    }
}

signed main(){
    LAPDZ;

    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    ll test;
    cin >> test;

    while (test--) solve();

    return 0;
}