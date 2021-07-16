#include <bits/stdc++.h>
using namespace std;
//using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n+2);
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++) {
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout << dp[n] << endl;
    return 0;
}
