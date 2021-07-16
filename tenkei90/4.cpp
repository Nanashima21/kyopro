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
    vector<vector<int>> v(h,vector<int> (w));
    rep(i,h) rep(j,w) cin >> v[i][j];
    vector<int> s1(h,0),s2(w,0);
    rep(i,h) rep(j,w) s1[i]+=v[i][j];
    rep(i,w) rep(j,h) s2[i]+=v[j][i];
    rep(i,h) {
        rep(j,w) {
            if(j) cout << " ";
            cout << s1[i]+s2[j]-v[i][j];
        }
        cout << endl;
    }
    return 0;
}