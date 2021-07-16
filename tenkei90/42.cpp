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
    ll k;
    cin >> k;
    if(k%9!=0) cout << 0 << endl;
    else {
        vector<ll> dp(k+1);
        dp[0]=1;
        for(int i=1;i<=k;i++) {
            for(int j=1;j<=min(i,9);j++) {
                dp[i]+=dp[i-j];
                dp[i]%=mod;
            }
        }
        cout << dp[k] << endl;
    }
    return 0;
}