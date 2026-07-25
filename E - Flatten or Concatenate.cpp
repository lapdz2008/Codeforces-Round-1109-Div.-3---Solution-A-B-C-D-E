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

const ll mod = 1e6+7; //998244353;
const ll maxn = 1e6+7;
const db inf = 1e-8;
const ll base = 311;
const db pi = 3.14159265;

ll truyvan(ll l, ll r){
    cout << "? " << l << " " << r << el;
    cout.flush();
    ll x;
    if(!(cin >> x) || x == -1) exit(0);
    return x;
}

signed main(){
    LAPDZ;
    if (fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    ll test; cin >> test;
    while(test--){
        ll n; cin >> n;
        ll left = 1, r = n;
        ll tong = truyvan(left, r);
        while(left < r){
            ll k = tong / 2,L = left, R = r;
            while(L < R){
                ll mid = (L + R) / 2;
                if(truyvan(left, mid) < k) L = mid + 1;
                else R = mid;
            }
            ll fixed = L,a = fixed - left + 1,b = r - fixed;
            tong = k;
            if(a <= b) r = fixed;
            else left = fixed + 1;
        }
        cout << "! " << tong << el;
        cout.flush();
    }
    return 0;
}
