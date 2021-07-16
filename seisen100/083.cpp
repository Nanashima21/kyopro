#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
typedef long long ll;
typedef pair<ll,ll> pl;
typedef tuple<ll,ll,ll> tupl;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<ll> p(m),v(n+1,0);
    rep(i,m) cin >> p[i];
    rep(i,m-1) {
        if(p[i]<p[i+1]) {
            v[p[i]]++;
            v[p[i+1]]--;
        } else {
            v[p[i]]--;
            v[p[i+1]]++;
        }
    }
    for(int i=1;i<n;i++) v[i]+=v[i-1];
    ll ans=0;
    for(int i=1;i<n;i++) {
        ll a,b,c;
        cin >> a >> b >> c;
        ll cost=min(v[i]*a,v[i]*b+c);
        ans+=cost;
    }
    cout << ans << endl;
    return 0;
}
