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
    int h,w;
    cin >> h >> w;
    vector<vector<int>> p(h,vector<int> (w));
    rep(i,h) rep(j,w) cin >> p[i][j];
    ll ans=0;
    for(int bit=1;bit<(1<<h);bit++) {
        vector<int> v,y(w);
        int cnt=0;
        rep(i,h) if(1<<i&bit) {
            v.push_back(i);
            cnt++;
        }
        int x=v.size();
        vector<bool> flag(w,true);
        rep(i,w) y[i]=p[v[0]][i];
        for(int i=1;i<x;i++) {
            rep(j,w) if(y[j]!=p[v[i]][j]) flag[j]=false;
        }
        map<ll,ll> m;
        rep(i,w) if(flag[i]) m[y[i]]++;
        for(auto z:m) ans=max(ans,z.second*cnt);
    }
    cout << ans << endl;
    return 0;
}