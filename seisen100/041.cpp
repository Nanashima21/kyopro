#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
typedef long long ll;

int main()
{
    int d,n;
    cin >> d >> n;
    vector<int> t(d),a(n),b(n),c(n);
    rep(i,d) cin >> t[i];
    rep(i,n) cin >> a[i] >> b[i] >> c[i];
    int dp[210][210]={0};
    for(int i=1;i<d;i++) {
        rep(j,n) rep(k,n) {
            if(a[j]>t[i]||t[i]>b[j]) continue;
            if(a[k]>t[i-1]||t[i-1]>b[k]) continue;
            dp[i][j]=max(dp[i-1][k]+abs(c[j]-c[k]),dp[i][j]);
        }
    }
    int ans=0;
    rep(i,n) ans=max(ans,dp[d-1][i]);
    cout << ans << endl;
    return 0;
}
