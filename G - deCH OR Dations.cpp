#include <bits/stdc++.h>
#define LAPDZ ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define task "lapdz"
#define el '\n'
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

struct XBIT{
    ll n;vector<ull> bit;
    XBIT(ll _n=0){n=_n;bit.assign(n+1,0);}
    void upd(ll i,ull v){for(;i<=n;i+=i&-i)bit[i]^=v;}
    ull qry(ll i){ull r=0;for(;i>0;i-=i&-i)r^=bit[i];return r;}
    ull get(ll l,ll r){return l>r?0:qry(r)^qry(l-1);}
};

ull mix64(ull &x){
    x+=0x9e3779b97f4a7c15ULL;
    ull z=x;
    z=(z^(z>>30))*0xbf58476d1ce4e5b9ULL;
    z=(z^(z>>27))*0x94d049bb133111ebULL;
    return z^(z>>31);
}

signed main(){
    LAPDZ;
    if(fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    ll test;cin>>test;
    while(test--){
        ll n;cin>>n;
        vector<pair<ll,ll>> seg(n);
        for(ll i=0;i<n;i++){ll l,r;cin>>l>>r;if(l>r)swap(l,r);seg[i]={l,r};}
        ll lim=2*n;
        XBIT bh(lim),bp(lim);
        ull sed=chrono::steady_clock::now().time_since_epoch().count();
        ull cur=0;
        string ans;ans.reserve(n);
        for(ll i=0;i<n;i++){
            ll l=seg[i].fi,r=seg[i].se;
            ull rnd=mix64(sed);
            ull h=bh.get(l,r);
            ull p=bp.get(l,r)&1ULL;
            ull tag=h^(p?0ULL:rnd);
            cur^=tag;
            bh.upd(l,tag);bh.upd(r,tag);
            bp.upd(l,p^1);bp.upd(r,p^1);
            ans.pb(cur==0?'1':'0');
        }
        cout<<ans<<el;
    }
    return 0;
}
/* lapdz */
