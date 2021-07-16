#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
typedef long long ll;
typedef pair<ll,ll> pl;
typedef tuple<ll,ll,ll> tupl;

int main()
{
    int m,n,k;
    cin >> m >> n >> k;
    vector<vector<char>> s(m+1,vector<char> (n+1));
    for(int i=1;i<=m;i++) for(int j=1;j<=n;j++) cin >> s[i][j];
    vector<vector<int>> J(m+1,vector<int> (n+1,0));
    vector<vector<int>> O(m+1,vector<int> (n+1,0));
    vector<vector<int>> I(m+1,vector<int> (n+1,0)); 
    rep(i,m+1) rep(j,n+1) {
        if(i==0||j==0) continue;
        J[i][j]+=J[i][j-1];
        O[i][j]+=O[i][j-1];
        I[i][j]+=I[i][j-1];
        if(s[i][j]=='J') J[i][j]++;
        if(s[i][j]=='O') O[i][j]++;
        if(s[i][j]=='I') I[i][j]++;
    }
    rep(i,m+1) rep(j,n+1) {
        if(i==0||j==0) continue;
        J[i][j]+=J[i-1][j];
        O[i][j]+=O[i-1][j];
        I[i][j]+=I[i-1][j];
    }
    rep(i,k) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        a--; b--;
        cout << J[c][d]+J[a][b]-J[a][d]-J[c][b];
        cout << " " << O[c][d]+O[a][b]-O[a][d]-O[c][b];
        cout << " " << I[c][d]+I[a][b]-I[a][d]-I[c][b] << endl;
    }
    return 0;
}
