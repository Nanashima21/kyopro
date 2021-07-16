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
    vector<string> s(5);
    rep(i,5) cin >> s[i];
    vector<vector<int>> cnt(n,vector<int> (3,0));
    rep(i,5) rep(j,n) {
        if(s[i][j]=='R') cnt[j][0]++;
        else if(s[i][j]=='B') cnt[j][1]++;
        else if(s[i][j]=='W') cnt[j][2]++;
    }
    int dp[1010][3]={0};
    for(int i=1;i<n;i++) rep(j,3) dp[i][j]=5*n;
    rep(i,3) dp[0][i]=5-cnt[0][i];
    for(int i=1;i<n;i++) {
        rep(j,3) rep(k,3) {
            if(j==k) continue;
            dp[i][k]=min(dp[i-1][j]+(5-cnt[i][k]),dp[i][k]);
        }
    }
    int ans=5*n;
    rep(i,3) ans=min(ans,dp[n-1][i]);
    cout << ans << endl;
    return 0;
}
