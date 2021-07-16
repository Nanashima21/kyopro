#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;
typedef tuple<ll,ll,ll> tupl;

const ll mod=1000000007;

int main()
{
    ll n,l;
    cin >> n >> l;
    vector<ll> dp(n+1,0);
    dp[0]=1;
    rep(i,n) {
        dp[i+1]+=dp[i];
        dp[i+1]%=mod;
        if(i+l<=n) {
            dp[i+l]+=dp[i];
            dp[i+l]%=mod;
        }
    }
    cout << dp[n] << endl;
    return 0;
}