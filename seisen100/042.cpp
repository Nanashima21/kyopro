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
    vector<int> d(n),c(m);
    rep(i,n) cin >> d[i];
    rep(i,m) cin >> c[i];
    ll dp[1010][1010]={};
    for(int i=1;i<=n;i++) rep(j,m) dp[i][j]=INF;
    rep(i,m) {
        rep(j,i+1) {
            dp[j+1][i+1]=dp[j][i]+d[j]*c[i];
            dp[j][i+1]=min(dp[j][i+1],dp[j][i]);
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}
