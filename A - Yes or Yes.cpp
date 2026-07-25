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
        string s; cin >> s;
        ll cnt = 0;
        for(char c : s) {
            if(c == 'Y') cnt++;
        }
        cout << (cnt <= 1 ? "YES\n" : "NO\n");
    }
    
    return 0;
}