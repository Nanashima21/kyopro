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
    vector<int> v(n);
    rep(i,n) cin >> v[i];
    vector<vector<ll>> dp(n-1,vector<ll> (21,0));
    int b=v.back();
    dp[0][v[0]]=1;
    for(int i=1;i<n-1;i++) {
        rep(j,21) {
            if(0<=j-v[i]) dp[i][j-v[i]]+=dp[i-1][j];
            if(j+v[i]<=20) dp[i][j+v[i]]+=dp[i-1][j];
        }
    }
    cout << dp[n-2][b] << endl;
    return 0;
}
