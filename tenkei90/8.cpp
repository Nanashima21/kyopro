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
ll dp[100009][8];

int main()
{
    int n;
    string s;
    cin >> n >> s;
    dp[0][0]=1;
    for(int i=0;i<(int)s.size();i++) {
        for(int j=0;j<=7;j++) {
            dp[i+1][j]+=dp[i][j];
            if(s[i]=='a'&&j==0) dp[i+1][j+1]+=dp[i][j];
            if(s[i]=='t'&&j==1) dp[i+1][j+1]+=dp[i][j];
            if(s[i]=='c'&&j==2) dp[i+1][j+1]+=dp[i][j];
            if(s[i]=='o'&&j==3) dp[i+1][j+1]+=dp[i][j];
            if(s[i]=='d'&&j==4) dp[i+1][j+1]+=dp[i][j];
            if(s[i]=='e'&&j==5) dp[i+1][j+1]+=dp[i][j];
            if(s[i]=='r'&&j==6) dp[i+1][j+1]+=dp[i][j];
        }
        for(int j=0;j<=7;j++) dp[i+1][j]%=mod;
    }
    cout << dp[s.size()][7] << endl;
    return 0;
}