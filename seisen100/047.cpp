#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    ll dp[2020][2020]={};
    rep(i,n) cin >> dp[0][i];
    for(int i=1;i<n;i++) {
        rep(j,n) {
            ll a=(j-1+n)%n;
            ll b=(j+i)%n;
            if(i%2==1) {
                if(dp[0][a]>dp[0][b]) dp[i][a]=max(dp[i][a],dp[i-1][j]);
                else dp[i][j]=max(dp[i][j],dp[i-1][j]);
            } else {
                dp[i][a]=max(dp[i][a],dp[i-1][j]+dp[0][a]);
                dp[i][j]=max(dp[i][j],dp[i-1][j]+dp[0][b]);
            }
        }
    }
    ll ans=0;
    rep(i,n) ans=max(ans,dp[n-1][i]);
    cout << ans << endl;
    return 0;
}
