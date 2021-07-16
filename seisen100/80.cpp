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
    int h,w;
    cin >> h >> w;
    ll k,v;
    cin >> k >> v;
    vector<vector<ll>> g(h+1,vector<ll> (w+1));
    for(int i=1;i<=h;i++) for(int j=1;j<=w;j++) {
        cin >> g[i][j];
        g[i][j]+=g[i][j-1];
    }
    for(int i=1;i<=h;i++) for(int j=1;j<=w;j++) g[i][j]+=g[i-1][j];
    int ans=0;
    if(h==1&&w==1) {
        if(g[1][1]+k<=v) ans=1;
    } else if(h==1) {
        rep(x,w) for(int nx=x;nx<=w;nx++) {
            ll cost=g[1][nx]-g[1][x];
            cost+=k*(nx-x+(nx==x));
            if(cost<=v) ans=max(nx-x,ans);
        }
    } else if(w==1) {
        rep(y,h) for(int ny=y;ny<=h;ny++) {
            ll cost=g[ny][1]-g[y][1];
            cost+=k*(ny-y+(ny==y));
            if(cost<=v) ans=max(ny-y,ans);
        }
    } else {
        rep(y,h) rep(x,w) {
            for(int ny=y;ny<=h;ny++) {
                for(int nx=x;nx<=w;nx++) {
                    if(x==0||y==0) continue;
                    ll cost=g[ny][nx]+g[y-1][x-1]-g[ny][x-1]-g[y-1][nx];
                    cost+=k*(nx-x+1)*(ny-y+1);
                    if(cost<=v) {
                        ans=max((nx-x+1)*(ny-y+1),ans);
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}