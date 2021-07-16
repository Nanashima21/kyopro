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
    int n,m,q;
    cin >> n >> m >> q;
    vector<vector<ll>> cnt(n+1,vector<ll> (n+1,0));
    rep(i,m) {
        int a,b;
        cin >> a >> b;
        cnt[a][b]++;
    } 
    for(int i=1;i<=n;i++) {
        for(int j=2;j<=n;j++) {
            cnt[i][j]+=cnt[i][j-1];
            //cout << " " << cnt[i][j];
        }
        //cout << endl;
    }
    rep(i,q) {
        int x,y;
        cin >> x >> y;
        ll ans=0;
        for(int j=x;j<=y;j++) ans+=cnt[j][y];
        cout << ans << endl;
    }
    return 0;
}
