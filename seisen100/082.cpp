#include <bits/stdc++.h>
using namespace std;
//using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
typedef long long ll;
typedef pair<ll,ll> pl;
//typedef tuple<ll,ll,ll> tupl;

int main()
{
    while(true) {
        int n;
        cin >> n;
        if(n==0) break;
        vector<ll> v(240010,0);
        rep(i,n) {
            string s,t;
            cin >> s >> t;
            ll x=0,y=0,z=1;
            reverse(all(s));
            reverse(all(t));
            rep(i,8) {
                if(i==2||i==5) continue;
                x+=(s[i]-'0')*z;
                y+=(t[i]-'0')*z;
                z*=10;
            }
            v[x]++;
            v[y]--;
        }
        ll ans=v[0];
        for(int i=1;i<=240001;i++) {
            v[i]+=v[i-1];
            ans=max(ans,v[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
