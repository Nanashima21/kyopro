#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
typedef long long ll;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<ll>> v(n,vector<ll> (m));
    rep(i,n) rep(j,m) cin >> v[i][j];
    ll ans=0;
    rep(i,m) {
        for(int j=i+1;j<m;j++) {
            ll sum=0;
            rep(k,n) sum+=max(v[k][i],v[k][j]);
            ans=max(sum,ans);
        }
    }
    cout << ans << endl;
    return 0;
}