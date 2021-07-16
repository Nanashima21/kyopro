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

int main()
{
    int n;
    cin >> n;
    vector<vector<ll>> v(1010,vector<ll> (1010,0));
    rep(i,n) {
        int a,b,c,d;
        cin >> a >> b >> c >> d; 
        v[b][a]++; v[d][a]--;
        v[b][c]--; v[d][c]++;
    }
    for(int i=0;i<=1000;i++) {
        for(int j=1;j<=1000;j++) {
            v[i][j]+=v[i][j-1];
        }
    }
    for(int i=0;i<=1000;i++) {
        for(int j=1;j<=1000;j++) {
            v[j][i]+=v[j-1][i];
        }
    }
    vector<ll> ans(n,0);
    rep(i,1001) rep(j,1001) {
        if(v[i][j]==0) continue;
        ans[v[i][j]-1]++;
    }
    rep(i,n) cout << ans[i] << endl;
    return 0;
}