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
    int n;
    cin >> n;
    ll G[301][301]={{0}};
    rep(i,n) rep(j,n) cin >> G[i][j];
    vector<pair<ll,pl>> v;
    rep(i,n) for(int j=i+1;j<n;j++) {
        v.push_back({-G[i][j],{i,j}});
    }
    sort(all(v));
    ll ans=0;
    rep(i,n) for(int j=i+1;j<n;j++) ans+=G[i][j];
    for(auto u:v) {
        ll c=-u.first;
        ll a=u.second.first;
        ll b=u.second.second;
        if(G[a][b]==INF) continue;
        rep(i,n) if(i!=a&&i!=b&&G[a][i]!=INF&&G[i][b]!=INF) {
            if(G[a][i]+G[i][b]==c) {
                ans-=c;
                G[a][b]=G[b][a]=INF;
                break;
            } else if(G[a][i]+G[i][b]<c) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
