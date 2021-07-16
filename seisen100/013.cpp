#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
typedef long long ll;

int main()
{
    int r,c;
    cin >> r >> c;
    vector<vector<int>> v(r,vector<int> (c));
    rep(i,r) rep(j,c) cin >> v[i][j];
    ll ans=r*c;
    for(int bit=0;bit<(1<<r);bit++) {
        vector<vector<int>> nv(r,vector<int> (c));
        rep(i,r) rep(j,c) nv[i][j]=v[i][j];
        rep(i,r) {
            if(1<<i&bit) {
                rep(j,c) nv[i][j]^=1;
            }
        }
        vector<int> cnt(c);
        rep(i,c) rep(j,r) cnt[i]+=nv[j][i];
        ll sum=0;
        rep(i,c) {
            if(cnt[i]>=r-cnt[i]) sum+=r-cnt[i];
            else sum+=cnt[i];
        }
        ans=min(ans,sum);
    }
    cout << r*c-ans << endl;
    return 0;
}
