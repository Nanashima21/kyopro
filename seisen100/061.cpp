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
    ll G[301][301]={{0}};
    rep(i,n) rep(j,n) G[i][j]=(i!=j)*INF;
    rep(i,m) {
        int a,b,t;
        cin >> a >> b >> t;
        a--; b--;
        G[a][b]=t;
    }
    rep(k,n) rep(i,n) rep(j,n) G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
    vector<ll> v(n,0);
    rep(i,n) rep(j,n) v[i]=max(G[i][j],v[i]);
    cout << *min_element(all(v)) << endl;
    return 0;
}
