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
    ll n,m;
    cin >> n >> m;
    vector<vector<ll>> v(n+2,vector<ll> (n+2,0));
    rep(i,m) {
        ll a,b,x;
        cin >> a >> b >> x;
        v[a][b]=max(v[a][b],x+1);
    }
    ll ans=0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=i;j++) {
            v[i+1][j+1]=max(v[i][j]-1,v[i+1][j+1]);
            v[i+1][j]=max(v[i][j]-1,v[i+1][j]);
            if(v[i][j]>0) ans++; 
        }
    }
    cout << ans << endl;
    return 0;
}