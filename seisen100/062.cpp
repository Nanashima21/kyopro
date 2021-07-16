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
    int h,w;
    cin >> h >> w;
    ll t[10][10]={{0}};
    rep(i,10) rep(j,10) t[i][j]=(i!=j)*INF;
    rep(i,10) rep(j,10) cin >> t[i][j];
    rep(k,10) rep(i,10) rep(j,10) t[i][j]=min(t[i][j],t[i][k]+t[k][j]);
    ll sum=0;
    rep(i,h) rep(j,w) {
        int a;
        cin >> a;
        if(a==-1||a==1) continue;
        else sum+=t[a][1]; 
    }
    cout << sum << endl;
    return 0;
}
