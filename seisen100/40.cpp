#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
typedef long long ll;

const int mod=10000;

int main()
{
    int n,k;
    cin >> n >> k;
    vector<int> v(n+1,-1);
    rep(i,k) {
        int a,b;
        cin >> a >> b;
        v[a]=b-1;
    }
    ll dp[105][3][3]={0};
    dp[0][0][0]=1;
    for(int i=1;i<=n;i++) { 
        rep(x,3) rep(y,3) rep(z,3) {
            if(v[i]>=0&&v[i]!=z) continue;
            if(i>=3&&x==y&&y==z) continue;
            dp[i][y][z]+=dp[i-1][x][y];
            dp[i][y][z]%=mod;
        }
    }
    ll ans=0;
    rep(i,3) rep(j,3) ans+=dp[n][i][j];
    ans%=mod;
    cout << ans << endl;
    return 0;
}