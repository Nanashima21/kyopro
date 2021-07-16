#include <bits/stdc++.h>
using namespace std;
//using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
typedef long long ll;

int main()
{
    while(true) {
        int n,m;
        cin >> n >> m;
        if(n==0&&m==0) break;
        vector<int> c(m),x(n);
        rep(i,m) cin >> c[i];
        rep(i,n) cin >> x[i];
        vector<vector<ll> > dp(20010,vector<ll> (256,INF));
        dp[0][128]=0;
        for(int i=0;i<n;i++) {
            rep(j,256) {
                if(dp[i][j]!=INF) {
                    rep(k,m) {
                        int nx=j+c[k];
                        if(nx<0) nx=0;
                        if(nx>255) nx=255;
                        ll np=pow(nx-x[i],2);
                        dp[i+1][nx]=min(dp[i+1][nx],np+dp[i][j]);
                    }
                }
            }
        }
        ll ans=INF;
        rep(i,256) ans=min(ans,dp[n][i]);
        cout << ans << endl;
    }
    return 0;
}