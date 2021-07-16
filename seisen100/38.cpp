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
    rep(i,n) {
        string s,t;
        cin >> s >> t;
        int x=s.size(),y=t.size();
        vector<vector<int> > dp(x+1,vector<int> (y+1,0));
        for(int i=1;i<=x;i++) {
            for(int j=1;j<=y;j++) {
                if(s[i-1]==t[j-1]) {
                    dp[i][j]=dp[i-1][j-1]+1;
                } else {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        cout << dp[x][y] << endl;
    }
    return 0;
}