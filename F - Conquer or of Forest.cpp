#include <bits/stdc++.h>
#define LAPDZ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define task "lapdz"
#define el '\n'
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define reset(x) memset(x, (int)0, sizeof(x))
#define FOR(i, a, b) for(ll i = (a); i < (b); i++)
#define FORD(i, a, b) for(ll i = (a); i > (b); i--)
#define REP(i,a,b) for(ll i = (a); i <= (b);i++)
#define REPD(i,a,b) for(ll i = (a); i >= (b); i--)
#define turn_on(i, m) (m |= (1LL << i))
#define turn_off(i, m) (m &= ~(1LL << i))
#define bit(x, i) ((x >> i) & 1)
#define MASK(i) (1LL<<(i))
#define c_bit(i) __builtin_popcountll(i)

using namespace std;
typedef long long ll;
typedef double db;

const ll MOD = 998244353;
const ll maxn = 1e6+7;

vector<vector<ll>> adj;
vector<ll> subSize;
vector<ll> comp;

ll fastPow(ll a, ll e){
    ll res = 1;
    a %= MOD;
    while(e){
        if(e & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        e >>= 1;
    }
    return res;
}

ll modInv(ll x){
    return fastPow(x, MOD - 2);
}

void dsu(int u, int par){
    subSize[u] = 1;
    for(int v : adj[u]){
        if(v == par) continue;
        dsu(v, u);
        subSize[u] += subSize[v];
    }
}

ll build(ll u, ll par){
    ll sum = 1;
    for(ll v : adj[u]){
        if(v == par) continue;
        ll cur = build(v, u);
        if(subSize[v] % 2 == 0) comp.pb(cur);
        else sum += cur;
        
    }
    return sum;
}


void solve(){
    ll n; cin >> n;
    adj.assign(n + 1, {});
    subSize.assign(n + 1, 0);
    comp.clear();
    REP(i,1,n-1){
        ll u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dsu(1, 0);
    ll rootVal = build(1, 0),k = sz(comp),fact = 1,prod = 1, sum = 0;
    ll ans = rootVal;
    if(k == 0){
        cout << 1 << el;
        return;
    }
    FOR(i,1,k)fact = (fact * i) % MOD;
    for(ll x : comp){
        ll t = x % MOD;
        prod = (prod * t % MOD * t) % MOD;
        sum = (sum + modInv(x)) % MOD;
    }
    ans = (ans * fact) % MOD;
    ans = (ans * prod) % MOD;
    ans = (ans * sum) % MOD;
    cout << ans << el;
}

signed main(){
    LAPDZ;
    if (fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    ll test;
    cin >> test;
    while(test--) solve();
    
    return 0;
}
