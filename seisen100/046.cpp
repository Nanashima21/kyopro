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
    vector<int> p(n+1);
    for(int i=1;i<=n;i++) cin >> p[i-1] >> p[i];
    int dp[105][105]={0};
    for(int l=2;l<=n;l++) {
        for(int i=1;i<=n-l+1;i++) {
            int j=i+l-1;
            dp[i][j]=(1<<21);
            for(int k=i;k<=j-1;k++) {
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+p[i-1]*p[k]*p[j]);
            }
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}
