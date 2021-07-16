#include <bits/stdc++.h>
using namespace std;
//using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
typedef long long ll;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> v(m);
    rep(i,m) cin >> v[i];
    vector<int> dp(1e5);
    rep(i,1e5) dp[i]=i;
    for(int i=1;i<m;i++) {
        rep(j,n-v[i]+1) {
            dp[j+v[i]]=min(dp[j+v[i]],dp[j]+1);
        }
    }
    cout << dp[n] << endl;
    return 0;
}
