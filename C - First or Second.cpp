#include <bits/stdc++.h>
#define LAPDZ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define task "lapdz"
#define el '\n'
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define reset(x) memset(x, (int)0, sizeof(x))
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define REP(i,a,b) for(int i = (a); i <= (b);i++)
#define REPD(i,a,b) for(int i = (a); i >= (b); i--)
#define turn_on(i, m) (m |= (1LL << i))
#define turn_off(i, m) (m &= ~(1LL << i))
#define bit(x, i) ((x >> i) & 1)
#define MASK(i) (1LL<<(i))
#define c_bit(i) __builtin_popcountll(i)

using namespace std;
typedef long long ll;
typedef double db;

const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,1,-1};
const int ddx[8] = {1,-1,1,1,-1,-1,0,0};
const int ddy[8] = {0,0,-1,1,-1,1,-1,1};

const ll mod = 20240131; //998244353;
const ll maxn = 1e6+7;
const db inf = 1e-8;
const ll base = 311;
const db pi = 3.14159265;

signed main(){
    LAPDZ;
    if (fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    ll test;
    cin >> test;
    while(test--){
        ll n; cin >> n;
        vector<ll> a(n);
        FOR(i,0,n) cin >> a[i];
        ll cur = -a[n - 1],best_diff = a[n - 1],ans = 0;
        for(ll i = n - 2;i >= 0; --i){
            ll k = cur + max(0LL,a[i] + best_diff);
            cur -= a[i];
            best_diff=max(best_diff,k - cur);
            if(i == 0) ans = k;
        }
        cout << ans << endl;
    }
    return 0;
}
