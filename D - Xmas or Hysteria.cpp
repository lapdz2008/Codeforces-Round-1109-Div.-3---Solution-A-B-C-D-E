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

signed main(){
    LAPDZ;
    if (fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    LAPDZ;
    ll test;
    cin >> test;;
    while(test--){
        ll n, m;
        cin >> n >> m;
        vector<ll> arr(n);
        vector<pair<ll,ll>> ans;
        for(ll i = 0; i < n; i++) cin >> arr[i];
        vector<ll> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](ll x, ll y){
            return arr[x] < arr[y];
        });
        // truong hop 1  
        if(m == 0){
            if(n == 2){
                cout << -1 << "\n";
                continue;
            }
            ll sum = 0,mx = idx[n-1],sc = idx[n-2];
            for(ll x : arr) sum += x;
            if(sum - arr[mx] < arr[mx]){
                cout << -1 << "\n";
                continue;
            }
            ll ned = arr[mx] - arr[sc],cur = 0,ptr = 0;
            while(ptr <= n-3 && cur < ned){
                ans.push_back({idx[ptr] + 1, mx + 1});
                cur += arr[idx[ptr]];
                ptr++;
            }
            if(ptr <= n-3){
                for(ll i = ptr; i < n-3; i++)ans.push_back({idx[i] + 1, idx[i+1] + 1});
                ans.push_back({idx[n-3] + 1, sc + 1});
            }
            ans.push_back({sc + 1, mx + 1});
            cout << ans.size() << "\n";
            for(auto &e : ans)cout << e.first << " " << e.second << "\n";
            continue;
        }
        // truong hop 2
        if(m == 1){
            for(ll i = 0; i < n-1; i++) ans.push_back({idx[i] + 1, idx[i+1] + 1});
            cout << ans.size() << "\n";
            for(auto &e : ans) cout << e.first << " " << e.second << "\n";
            continue;
        }
        if(n < 2 * m){
            cout << -1 << "\n";
            continue;
        }
        // truong hop 3 
        ll fre = n - 2 * m;
        for(ll i = 0; i < m; i++){
            ll L = i * fre / m, R = (i + 1) * fre / m;
            if(R - L >= 2){
                for(ll j = L; j < R - 1; j++) ans.push_back({idx[j] + 1, idx[j+1] + 1});
            }
            if(R - L >= 1) ans.push_back({idx[R-1] + 1, idx[fre + i] + 1});
        }
        for(ll i = 0; i < m; i++)ans.push_back({idx[fre + m + i] + 1, idx[fre + i] + 1});
        cout << ans.size() << "\n";
        for(auto &e : ans)  cout << e.first << " " << e.second << "\n";
        
    }
    return 0;
}
/*
    Do the assignment yourself and don't copy my code =.=
*/