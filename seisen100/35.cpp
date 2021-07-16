#include <bits/stdc++.h>
using namespace std;
//using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
typedef long long ll;

int main()
{
    int n,W;
    cin >> n >> W;
    vector<int> v(n),w(n);
    rep(i,n) cin >> v[i] >> w[i];
    vector<int> dp(W+1,0);
    rep(i,n) {
        for(int j=W-w[i];j>=0;j--) {
            dp[j+w[i]]=max(dp[j+w[i]],dp[j]+v[i]);
        }
    }
    cout << dp[W] << endl;
    return 0;
}