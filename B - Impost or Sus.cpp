#include<bits/stdc++.h>
#define task "none"

using namespace std;
typedef long long ll;
typedef double db;
/*
    
*/
const ll maxn = 1e6+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if(fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    ll test;
    cin >> test;
    while(test--) {
        string str;
        cin >> str;
        ll n = str.size();
        ll ans = 0;
        for(ll i = 0; i < n; ){
            if(str[i] == 's') {
                i++;
                continue;
            }
            
            ll j = i;
            while(j < n && str[j] == 'u') j++;
            ll len = j - i,cnt = 0;
            if(i == 0) cnt++;
            if(j == n) cnt++;
            ll x = len - cnt;
            if(x < 0) x = 0;
            ans += cnt + x / 2;
            i = j;
        }
        cout << ans << endl;
    }
    return 0;
}