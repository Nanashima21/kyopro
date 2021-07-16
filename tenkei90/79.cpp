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
    vector<vector<int>> a(h,vector<int> (w));
    vector<vector<int>> b(h,vector<int> (w));
    rep(i,h) rep(j,w) cin >> a[i][j];
    rep(i,h) rep(j,w) cin >> b[i][j];
    vector<vector<int>> c(h,vector<int> (w));
    rep(i,h) rep(j,w) {
        if((i%2==0&&j%2==1)||(i%2==1&&j%2==0)) c[i][j]=-(a[i][j]-b[i][j]);
        else c[i][j]=a[i][j]-b[i][j];
    } 
    for(int i=1;i<h;i++) rep(j,w) c[i][j]+=c[i-1][j];
    for(int i=1;i<w;i++) rep(j,h) c[j][i]+=c[j][i-1];
    ll sum=0;
    bool flag=true;
    rep(i,h) {
        rep(j,w) {
            sum+=abs(c[i][j]);
            if(i==h-1&&c[i][j]!=0) flag=false;
            if(j==w-1&&c[i][j]!=0) flag=false; 
        }
    }
    if(flag) cout << "Yes" << endl << sum << endl;
    else cout << "No" << endl;
    return 0;
}