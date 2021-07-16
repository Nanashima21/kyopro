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
    ll n;
    cin >> n;
    vector<vector<ll>> v(3,vector<ll> (n));
    rep(i,3) rep(j,n) {
        cin >> v[i][j];
        v[i][j]%=46;
    }
    vector<ll> dp1(46,0),dp2(46,0),dp3(46,0);
    rep(i,n) dp1[v[0][i]]++;
    rep(j,46) {
        if(dp1[j]==0) continue;
        rep(i,n) dp2[(j+v[1][i])%46]+=dp1[j]; 
    }
    rep(j,46) {
        if(dp2[j]==0) continue;
        rep(i,n) dp3[(j+v[2][i])%46]+=dp2[j];
    }
    cout << dp3[0] << endl;
    return 0;
}