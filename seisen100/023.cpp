#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
typedef long long ll;

int main()
{
    ll n,m;
    cin >> n >> m;
    vector<ll> p(n),v;
    rep(i,n) cin >> p[i];
  	p.push_back(0);
  	rep(i,n+1) rep(j,n+1) v.push_back(p[i]+p[j]);
    sort(all(v));
    ll ans=0;
    int x=v.size();
    rep(i,x) {
        ll y=v[i],sum=v[i];
        auto z=upper_bound(all(v),m-y);
      	if(z-v.begin()-1>1) sum+=v[z-v.begin()-1];
        if(sum<=m) ans=max(ans,sum);   
    }
    cout << ans << endl;
    return 0;
}
